/**
 * Spezialized Pdf View
 *
 * This file is part of pdfpc.
 *
 * Copyright (C) 2010-2011 Jakob Westhoff <jakob@westhoffswelt.de>
 * Copyright 2011-2012 David Vilar
 * Copyright 2012, 2015, 2017 Andreas Bilke
 * Copyright 2012, 2015 Robert Schroll
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

namespace pdfpc {
    /**
     * View spezialized to work with Pdf renderers.
     *
     * This class is mainly needed to be decorated with pdf-link-interactions
     * signals.
     *
     * By default it does not implement any further functionality.
     */
    public class View.Pdf : Gtk.DrawingArea {
        /**
         * Signal fired every time a slide is about to be left
         */
        public signal void leaving_slide(int from, int to);

        /**
         * Signal fired every time a slide is entered
         */
        public signal void entering_slide(int slide_number);

        /**
         * Renderer to be used for rendering the slides
         */
        protected Renderer.Pdf renderer;

        /**
         * Return the used renderer object
         */
        public Renderer.Pdf get_renderer() {
            return this.renderer;
        }

        /**
         * Signal emitted every time a precached slide has been created
         *
         * This signal should be emitted slide_count number of times during a
         * precaching cylce.
         */
        public signal void slide_prerendered();

        /**
         * Signal emitted when the precaching cycle is complete
         */
        public signal void prerendering_completed();

        /**
         * Signal emitted when the precaching cycle just started
         */
        public signal void prerendering_started();

        /**
         * Signal emitted on toggling the freeze state
         */
        public signal void freeze_toggled(bool frozen);

        /**
         * The currently displayed slide
         */
        protected int current_slide_number;

        /**
         * Whether the view should remain black
         */
        public bool disabled;

        /**
         * The surface containing the currently shown slide
         */
        protected Cairo.ImageSurface current_slide;

        /**
         * The number of slides in the presentation
         */
        protected int n_slides {
            get {
                return (int) renderer.metadata.get_slide_count();
            }
        }

        /**
         * List to store all associated behaviours
         */
        protected GLib.List<View.Behaviour.Base> behaviours = new GLib.List<View.Behaviour.Base>();

        /**
         * GDK scale factor
         */
        protected int gdk_scale = 1;

        /**
         * Default constructor restricted to Pdf renderers as input parameter
         */
        public Pdf(Renderer.Pdf renderer, bool clickable_links,
            PresentationController controller, int gdk_scale_factor) {
            this.renderer = renderer;
            this.gdk_scale = gdk_scale_factor;

            this.current_slide_number = 0;

            controller.reload_request.connect(this.rebuild_cache);

            // Render the initial page on first realization.
            this.add_events(Gdk.EventMask.STRUCTURE_MASK);
            this.realize.connect(() => {
                try {
                    this.display( this.current_slide_number );
                } catch( Renderer.RenderError e ) {
                    // There should always be a page 0 but you never know.
                    GLib.printerr("Could not render initial page %d: %s\n",
                        this.current_slide_number, e.message);
                    Process.exit(1);
                }

                // Start the prerender cycle if the renderer supports caching
                // and the used cache engine allows prerendering.
                // Executing the cycle here to ensure it is executed within the
                // Gtk event loop. If it is not proper Gdk thread handling is
                // impossible.
                if (renderer.cache != null && renderer.cache.allows_prerendering()) {
                    this.register_prerendering();
                }
            });

            if (clickable_links) {
                // Enable the PDFLink Behaviour by default on PDF Views
                this.associate_behaviour(new View.Behaviour.PdfLink());
            }
        }

        /**
         * Create a new Pdf view from a Fullscreen window instance
         *
         * This is a convenience constructor which automatically creates a full
         * metadata and rendering chain to be used with the pdf view.
         */
        public Pdf.from_fullscreen(Window.Fullscreen window,
            Metadata.Area area, bool clickable_links) {
            var controller = window.controller;
            var metadata = controller.metadata;

            // will be resized on first use
            var renderer = new Renderer.Pdf(metadata, 1, 1, area);

            this(renderer, clickable_links, controller, window.gdk_scale);
        }

        /**
         * Convert an arbitrary Poppler.Rectangle struct into a Gdk.Rectangle
         * struct taking into account the measurement differences between pdf
         * space and screen space.
         */
        public Gdk.Rectangle convert_poppler_rectangle_to_gdk_rectangle(
            Poppler.Rectangle poppler_rectangle) {
            Gdk.Rectangle gdk_rectangle = Gdk.Rectangle();

            Gtk.Allocation allocation;
            this.get_allocation(out allocation);

            // We need the page dimensions for coordinate conversion between
            // pdf coordinates and screen coordinates
            var metadata = this.get_renderer().metadata;
            gdk_rectangle.x = (int) Math.ceil((poppler_rectangle.x1 / metadata.get_page_width()) *
                allocation.width );
            gdk_rectangle.width = (int) Math.floor(((poppler_rectangle.x2 - poppler_rectangle.x1) /
                metadata.get_page_width()) * allocation.width);

            // Gdk has its coordinate origin in the upper left, while Poppler
            // has its origin in the lower left.
            gdk_rectangle.y = (int) Math.ceil(((metadata.get_page_height() - poppler_rectangle.y2) /
                metadata.get_page_height()) * allocation.height);
            gdk_rectangle.height = (int) Math.floor(((poppler_rectangle.y2 - poppler_rectangle.y1) /
                metadata.get_page_height()) * allocation.height);

            return gdk_rectangle;
        }

        /**
         * Start a thread to prerender all slides this view might display at
         * some time.
         *
         * This method may only be called from within the Gtk event loop, as
         * thread handling is borked otherwise.
         */
        protected void register_prerendering() {
            // The pointer is needed to keep track of the slide progress inside
            // the prerender function
            int* i = null;
            // The page_count will be transfered into the lamda function as
            // well.
            if (this.n_slides == 0) {
                return;
            }

            this.prerendering_started();

            Idle.add(() => {
                if (i == null) {
                    i = malloc(sizeof(int));
                    *i = 0;
                }

                // We do not care about the result, as the
                // rendering function stores the rendered
                // pixmap in the cache if it is enabled. This
                // is exactly what we want.
                try {
                    this.get_renderer().render_to_surface(*i);
                } catch(Renderer.RenderError e) {
                    GLib.printerr("Could not render page '%i' while pre-rendering: %s\n", *i, e.message);
                    Process.exit(1);
                }

                // Inform possible observers about the cached slide
                this.slide_prerendered();

                // Increment one slide for each call and stop the loop if we
                // have reached the last slide
                *i = *i + 1;
                if (*i >= this.n_slides) {
                    this.prerendering_completed();
                    free(i);
                    return false;
                } else {
                    return true;
                }
            });
        }

        /**
         * Associate a new Behaviour with this View
         *
         * The implementation supports an arbitrary amount of different
         * behaviours.
         */
        public void associate_behaviour(Behaviour.Base behaviour) {
            this.behaviours.append(behaviour);
            try {
                behaviour.associate(this);
            } catch(Behaviour.AssociationError e) {
                GLib.printerr("Behaviour association failure: %s\n", e.message);
                Process.exit(1);
            }
        }

        /**
         * Display a specific slide number
         *
         * If the slide number does not exist a
         * RenderError.SLIDE_DOES_NOT_EXIST is thrown
         */
        public void display(int slide_number, bool force_redraw=false)
            throws Renderer.RenderError {

            if (this.n_slides == 0) {
                return;
            }

            // If the slide is out of bounds render the outer most slide on
            // each side of the document.
            if (slide_number < 0) {
                slide_number = 0;
            } else if (slide_number >= this.n_slides + 1) {
                slide_number = this.n_slides - 1;
            }

            if (!force_redraw && slide_number == this.current_slide_number &&
                this.current_slide != null) {
                // The slide does not need to be changed, as the correct one is
                // already shown.
                return;
            }

            // Notify all listeners
            this.leaving_slide(this.current_slide_number, slide_number);

            // Render the requested slide
            // An exception is thrown here, if the slide can not be rendered.
            if (slide_number < this.n_slides && !this.disabled)
                this.current_slide = this.renderer.render_to_surface(slide_number);
            else
                this.current_slide = this.renderer.fade_to_black();
            this.current_slide_number = slide_number;

            // Have Gtk update the widget
            this.queue_draw();

            this.entering_slide(this.current_slide_number);
        }

        /**
         * Redraw the current slide. Useful for example when exiting from fade_to_black
         */
        public void redraw() throws Renderer.RenderError {
            this.display(this.current_slide_number, true);
        }

        /**
         * Return the currently shown slide number
         */
        public int get_current_slide_number() {
            return this.current_slide_number;
        }

        /**
         * This method is called by Gdk every time the widget needs to be redrawn.
         *
         * The implementation does a simple blit from the internal pixmap to
         * the window surface.
         */
        public override bool draw(Cairo.Context cr) {
            var metadata = this.get_renderer().metadata;
            if (!metadata.is_ready) {
                return true;
            }

            Gtk.Allocation allocation;
            this.get_allocation(out allocation);

            // not ready yet
            if (allocation.height <= 1 || allocation.width <= 1) {
                return true;
            }

            if (renderer.width != allocation.width*this.gdk_scale ||
                renderer.height != allocation.height*this.gdk_scale) {
                // TODO: this is a mess.
                // Renderer/cache/view ties need to be refactored
                renderer.resize(allocation.width*this.gdk_scale,
                    allocation.height*this.gdk_scale);
                this.rebuild_cache();
                try {
                    this.redraw();
                } catch (Renderer.RenderError e) {
                }
            } else {
                cr.scale((1.0/this.gdk_scale), (1.0/this.gdk_scale));
                cr.set_source_surface(this.current_slide, 0, 0);
                cr.rectangle(0, 0, this.current_slide.get_width(),
                    this.current_slide.get_height());
                cr.fill();
            }

            // We are the only ones drawing on this context; skip everything
            // else.
            return true;
        }

        /**
         * Clear the current cache and begin building it anew
         */
        protected void rebuild_cache() {
            if (this.renderer.cache != null) {
                this.renderer.cache.invalidate();
                if (renderer.cache.allows_prerendering()) {
                    this.register_prerendering();
                }
            }
        }
    }
}
