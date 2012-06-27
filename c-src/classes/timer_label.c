/* timer_label.c generated by valac 0.16.0, the Vala compiler
 * generated from timer_label.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <time.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include <string.h>


#define PDFPC_TYPE_TIMER_LABEL (pdfpc_timer_label_get_type ())
#define PDFPC_TIMER_LABEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_TYPE_TIMER_LABEL, pdfpcTimerLabel))
#define PDFPC_TIMER_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_TYPE_TIMER_LABEL, pdfpcTimerLabelClass))
#define PDFPC_IS_TIMER_LABEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_TYPE_TIMER_LABEL))
#define PDFPC_IS_TIMER_LABEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_TYPE_TIMER_LABEL))
#define PDFPC_TIMER_LABEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_TYPE_TIMER_LABEL, pdfpcTimerLabelClass))

typedef struct _pdfpcTimerLabel pdfpcTimerLabel;
typedef struct _pdfpcTimerLabelClass pdfpcTimerLabelClass;

#define PDFPC_TYPE_COUNTDOWN_TIMER (pdfpc_countdown_timer_get_type ())
#define PDFPC_COUNTDOWN_TIMER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_TYPE_COUNTDOWN_TIMER, pdfpcCountdownTimer))
#define PDFPC_COUNTDOWN_TIMER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_TYPE_COUNTDOWN_TIMER, pdfpcCountdownTimerClass))
#define PDFPC_IS_COUNTDOWN_TIMER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_TYPE_COUNTDOWN_TIMER))
#define PDFPC_IS_COUNTDOWN_TIMER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_TYPE_COUNTDOWN_TIMER))
#define PDFPC_COUNTDOWN_TIMER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_TYPE_COUNTDOWN_TIMER, pdfpcCountdownTimerClass))

typedef struct _pdfpcCountdownTimer pdfpcCountdownTimer;
typedef struct _pdfpcCountdownTimerClass pdfpcCountdownTimerClass;

#define PDFPC_TYPE_END_TIME_TIMER (pdfpc_end_time_timer_get_type ())
#define PDFPC_END_TIME_TIMER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_TYPE_END_TIME_TIMER, pdfpcEndTimeTimer))
#define PDFPC_END_TIME_TIMER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_TYPE_END_TIME_TIMER, pdfpcEndTimeTimerClass))
#define PDFPC_IS_END_TIME_TIMER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_TYPE_END_TIME_TIMER))
#define PDFPC_IS_END_TIME_TIMER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_TYPE_END_TIME_TIMER))
#define PDFPC_END_TIME_TIMER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_TYPE_END_TIME_TIMER, pdfpcEndTimeTimerClass))

typedef struct _pdfpcEndTimeTimer pdfpcEndTimeTimer;
typedef struct _pdfpcEndTimeTimerClass pdfpcEndTimeTimerClass;

#define PDFPC_TYPE_COUNTUP_TIMER (pdfpc_countup_timer_get_type ())
#define PDFPC_COUNTUP_TIMER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PDFPC_TYPE_COUNTUP_TIMER, pdfpcCountupTimer))
#define PDFPC_COUNTUP_TIMER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PDFPC_TYPE_COUNTUP_TIMER, pdfpcCountupTimerClass))
#define PDFPC_IS_COUNTUP_TIMER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PDFPC_TYPE_COUNTUP_TIMER))
#define PDFPC_IS_COUNTUP_TIMER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PDFPC_TYPE_COUNTUP_TIMER))
#define PDFPC_COUNTUP_TIMER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PDFPC_TYPE_COUNTUP_TIMER, pdfpcCountupTimerClass))

typedef struct _pdfpcCountupTimer pdfpcCountupTimer;
typedef struct _pdfpcCountupTimerClass pdfpcCountupTimerClass;
typedef struct _pdfpcTimerLabelPrivate pdfpcTimerLabelPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _pdfpcCountdownTimerPrivate pdfpcCountdownTimerPrivate;
typedef struct _pdfpcEndTimeTimerPrivate pdfpcEndTimeTimerPrivate;
typedef struct _pdfpcCountupTimerPrivate pdfpcCountupTimerPrivate;

struct _pdfpcTimerLabel {
	GtkLabel parent_instance;
	pdfpcTimerLabelPrivate * priv;
	gint time;
	time_t start_time;
	guint timeout;
	GdkColor normal_color;
	GdkColor pretalk_color;
};

struct _pdfpcTimerLabelClass {
	GtkLabelClass parent_class;
	void (*start) (pdfpcTimerLabel* self);
	void (*stop) (pdfpcTimerLabel* self);
	void (*reset) (pdfpcTimerLabel* self);
	gboolean (*on_timeout) (pdfpcTimerLabel* self);
	void (*format_time) (pdfpcTimerLabel* self);
};

struct _pdfpcCountdownTimer {
	pdfpcTimerLabel parent_instance;
	pdfpcCountdownTimerPrivate * priv;
	gint duration;
	guint last_minutes;
	GdkColor last_minutes_color;
	GdkColor negative_color;
};

struct _pdfpcCountdownTimerClass {
	pdfpcTimerLabelClass parent_class;
};

struct _pdfpcEndTimeTimer {
	pdfpcCountdownTimer parent_instance;
	pdfpcEndTimeTimerPrivate * priv;
	time_t end_time;
	struct tm end_time_object;
};

struct _pdfpcEndTimeTimerClass {
	pdfpcCountdownTimerClass parent_class;
};

struct _pdfpcCountupTimer {
	pdfpcTimerLabel parent_instance;
	pdfpcCountupTimerPrivate * priv;
};

struct _pdfpcCountupTimerClass {
	pdfpcTimerLabelClass parent_class;
};


static gpointer pdfpc_timer_label_parent_class = NULL;
static gpointer pdfpc_countdown_timer_parent_class = NULL;
static gpointer pdfpc_end_time_timer_parent_class = NULL;
static gpointer pdfpc_countup_timer_parent_class = NULL;

GType pdfpc_timer_label_get_type (void) G_GNUC_CONST;
pdfpcTimerLabel* pdfpc_getTimerLabel (gint duration, time_t end_time, guint last_minutes, time_t start_time);
pdfpcEndTimeTimer* pdfpc_end_time_timer_new (time_t end_time, guint last_minutes, time_t start_time);
pdfpcEndTimeTimer* pdfpc_end_time_timer_construct (GType object_type, time_t end_time, guint last_minutes, time_t start_time);
GType pdfpc_countdown_timer_get_type (void) G_GNUC_CONST;
GType pdfpc_end_time_timer_get_type (void) G_GNUC_CONST;
pdfpcCountdownTimer* pdfpc_countdown_timer_new (gint duration, guint last_minutes, time_t start_time);
pdfpcCountdownTimer* pdfpc_countdown_timer_construct (GType object_type, gint duration, guint last_minutes, time_t start_time);
pdfpcCountupTimer* pdfpc_countup_timer_new (time_t start_time);
pdfpcCountupTimer* pdfpc_countup_timer_construct (GType object_type, time_t start_time);
GType pdfpc_countup_timer_get_type (void) G_GNUC_CONST;
enum  {
	PDFPC_TIMER_LABEL_DUMMY_PROPERTY
};
pdfpcTimerLabel* pdfpc_timer_label_construct (GType object_type, time_t start_time);
void pdfpc_timer_label_start (pdfpcTimerLabel* self);
static void pdfpc_timer_label_real_start (pdfpcTimerLabel* self);
gboolean pdfpc_timer_label_on_timeout (pdfpcTimerLabel* self);
static gboolean _pdfpc_timer_label_on_timeout_gsource_func (gpointer self);
void pdfpc_timer_label_stop (pdfpcTimerLabel* self);
static void pdfpc_timer_label_real_stop (pdfpcTimerLabel* self);
gboolean pdfpc_timer_label_pause (pdfpcTimerLabel* self);
gboolean pdfpc_timer_label_is_paused (pdfpcTimerLabel* self);
void pdfpc_timer_label_reset (pdfpcTimerLabel* self);
static void pdfpc_timer_label_real_reset (pdfpcTimerLabel* self);
gint pdfpc_timer_label_calculate_countdown (pdfpcTimerLabel* self);
void pdfpc_timer_label_format_time (pdfpcTimerLabel* self);
static gboolean pdfpc_timer_label_real_on_timeout (pdfpcTimerLabel* self);
static void pdfpc_timer_label_real_format_time (pdfpcTimerLabel* self);
void pdfpc_timer_label_show_time (pdfpcTimerLabel* self, guint timeInSecs, const gchar* prefix);
static void pdfpc_timer_label_finalize (GObject* obj);
enum  {
	PDFPC_COUNTDOWN_TIMER_DUMMY_PROPERTY
};
static void pdfpc_countdown_timer_real_format_time (pdfpcTimerLabel* base);
static void pdfpc_countdown_timer_finalize (GObject* obj);
enum  {
	PDFPC_END_TIME_TIMER_DUMMY_PROPERTY
};
static void pdfpc_end_time_timer_real_start (pdfpcTimerLabel* base);
static void pdfpc_end_time_timer_real_stop (pdfpcTimerLabel* base);
static void pdfpc_end_time_timer_real_reset (pdfpcTimerLabel* base);
static gboolean pdfpc_end_time_timer_real_on_timeout (pdfpcTimerLabel* base);
static void pdfpc_end_time_timer_finalize (GObject* obj);
enum  {
	PDFPC_COUNTUP_TIMER_DUMMY_PROPERTY
};
static void pdfpc_countup_timer_real_format_time (pdfpcTimerLabel* base);


/**
      * Factory function for creating TimerLabels, depending if a duration was
      * given.
      */
pdfpcTimerLabel* pdfpc_getTimerLabel (gint duration, time_t end_time, guint last_minutes, time_t start_time) {
	pdfpcTimerLabel* result = NULL;
	time_t _tmp0_;
	_tmp0_ = end_time;
	if (_tmp0_ > ((time_t) 0)) {
		time_t _tmp1_;
		guint _tmp2_;
		time_t _tmp3_;
		pdfpcEndTimeTimer* _tmp4_;
		pdfpcTimerLabel* _tmp5_;
		_tmp1_ = end_time;
		_tmp2_ = last_minutes;
		_tmp3_ = start_time;
		_tmp4_ = pdfpc_end_time_timer_new (_tmp1_, _tmp2_, _tmp3_);
		_tmp5_ = (pdfpcTimerLabel*) g_object_ref_sink (_tmp4_);
		result = _tmp5_;
		return result;
	} else {
		gint _tmp6_;
		_tmp6_ = duration;
		if (_tmp6_ > 0) {
			gint _tmp7_;
			guint _tmp8_;
			time_t _tmp9_;
			pdfpcCountdownTimer* _tmp10_;
			pdfpcTimerLabel* _tmp11_;
			_tmp7_ = duration;
			_tmp8_ = last_minutes;
			_tmp9_ = start_time;
			_tmp10_ = pdfpc_countdown_timer_new (_tmp7_, _tmp8_, _tmp9_);
			_tmp11_ = (pdfpcTimerLabel*) g_object_ref_sink (_tmp10_);
			result = _tmp11_;
			return result;
		} else {
			time_t _tmp12_;
			pdfpcCountupTimer* _tmp13_;
			pdfpcTimerLabel* _tmp14_;
			_tmp12_ = start_time;
			_tmp13_ = pdfpc_countup_timer_new (_tmp12_);
			_tmp14_ = (pdfpcTimerLabel*) g_object_ref_sink (_tmp13_);
			result = _tmp14_;
			return result;
		}
	}
}


/**
         * Default constructor taking the initial time as argument, as well as
         * the time to countdown until the talk actually starts.
         *
         * The second argument is optional. If no countdown_time is specified
         * the countdown will be disabled. The timer is paused in such a case
         * at the given intial_time.
         */
pdfpcTimerLabel* pdfpc_timer_label_construct (GType object_type, time_t start_time) {
	pdfpcTimerLabel * self = NULL;
	time_t _tmp0_;
	GdkColor _tmp1_ = {0};
	GdkColor _tmp2_ = {0};
	self = (pdfpcTimerLabel*) g_object_new (object_type, NULL);
	_tmp0_ = start_time;
	self->start_time = _tmp0_;
	gdk_color_parse ("white", &_tmp1_);
	self->normal_color = _tmp1_;
	gdk_color_parse ("green", &_tmp2_);
	self->pretalk_color = _tmp2_;
	return self;
}


/**
         * Start the timer
         */
static gboolean _pdfpc_timer_label_on_timeout_gsource_func (gpointer self) {
	gboolean result;
	result = pdfpc_timer_label_on_timeout (self);
	return result;
}


static void pdfpc_timer_label_real_start (pdfpcTimerLabel* self) {
	gboolean _tmp0_ = FALSE;
	guint _tmp1_;
	gboolean _tmp3_;
	_tmp1_ = self->timeout;
	if (_tmp1_ != ((guint) 0)) {
		gint _tmp2_;
		_tmp2_ = self->time;
		_tmp0_ = _tmp2_ < 0;
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	if (_tmp3_) {
		self->time = 0;
	} else {
		guint _tmp4_;
		_tmp4_ = self->timeout;
		if (_tmp4_ == ((guint) 0)) {
			guint _tmp5_ = 0U;
			_tmp5_ = g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 1000, _pdfpc_timer_label_on_timeout_gsource_func, g_object_ref (self), g_object_unref);
			self->timeout = _tmp5_;
		}
	}
}


void pdfpc_timer_label_start (pdfpcTimerLabel* self) {
	g_return_if_fail (self != NULL);
	PDFPC_TIMER_LABEL_GET_CLASS (self)->start (self);
}


/**
         * Stop the timer
         */
static void pdfpc_timer_label_real_stop (pdfpcTimerLabel* self) {
	guint _tmp0_;
	_tmp0_ = self->timeout;
	if (_tmp0_ != ((guint) 0)) {
		guint _tmp1_;
		_tmp1_ = self->timeout;
		g_source_remove (_tmp1_);
		self->timeout = (guint) 0;
	}
}


void pdfpc_timer_label_stop (pdfpcTimerLabel* self) {
	g_return_if_fail (self != NULL);
	PDFPC_TIMER_LABEL_GET_CLASS (self)->stop (self);
}


/**
         * Pauses the timer if it's running. Returns if the timer is paused.
         */
gboolean pdfpc_timer_label_pause (pdfpcTimerLabel* self) {
	gboolean result = FALSE;
	gboolean paused;
	gint _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	paused = FALSE;
	_tmp0_ = self->time;
	if (_tmp0_ > 0) {
		guint _tmp1_;
		_tmp1_ = self->timeout;
		if (_tmp1_ != ((guint) 0)) {
			pdfpc_timer_label_stop (self);
			paused = TRUE;
		} else {
			pdfpc_timer_label_start (self);
		}
	}
	result = paused;
	return result;
}


/**
         * Returns if the timer is paused
         */
gboolean pdfpc_timer_label_is_paused (pdfpcTimerLabel* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gint _tmp1_;
	gboolean _tmp3_;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp1_ = self->time;
	if (_tmp1_ > 0) {
		guint _tmp2_;
		_tmp2_ = self->timeout;
		_tmp0_ = _tmp2_ == ((guint) 0);
	} else {
		_tmp0_ = FALSE;
	}
	_tmp3_ = _tmp0_;
	result = _tmp3_;
	return result;
}


/**
         * Reset the timer to its initial value
         *
         * Furthermore the stop state will be restored
         * If the countdown is running the countdown value is recalculated. The
         * timer is not stopped in such situation.
         *
         * In presentation mode the time will be reset to the initial
         * presentation time.
         */
static void pdfpc_timer_label_real_reset (pdfpcTimerLabel* self) {
	gint _tmp0_ = 0;
	gint _tmp1_;
	pdfpc_timer_label_stop (self);
	_tmp0_ = pdfpc_timer_label_calculate_countdown (self);
	self->time = _tmp0_;
	_tmp1_ = self->time;
	if (_tmp1_ < 0) {
		pdfpc_timer_label_start (self);
	} else {
		self->time = 0;
	}
	pdfpc_timer_label_format_time (self);
}


void pdfpc_timer_label_reset (pdfpcTimerLabel* self) {
	g_return_if_fail (self != NULL);
	PDFPC_TIMER_LABEL_GET_CLASS (self)->reset (self);
}


/**
         * Calculate and return the countdown time in (negative) seconds until
         * the talk begins.
         */
static void g_time_local (time_t time, struct tm* result) {
	struct tm _result_ = {0};
	struct tm _tmp0_ = {0};
	localtime_r (&time, &_tmp0_);
	_result_ = _tmp0_;
	*result = _result_;
	return;
}


gint pdfpc_timer_label_calculate_countdown (pdfpcTimerLabel* self) {
	gint result = 0;
	time_t _tmp0_;
	struct tm _tmp1_ = {0};
	time_t _tmp2_ = 0;
	time_t now;
	time_t _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	_tmp0_ = time (NULL);
	g_time_local (_tmp0_, &_tmp1_);
	_tmp2_ = mktime (&_tmp1_);
	now = _tmp2_;
	_tmp3_ = self->start_time;
	result = (gint) (now - _tmp3_);
	return result;
}


/**
         * Update the timer on every timeout step (every second)
         */
static gboolean pdfpc_timer_label_real_on_timeout (pdfpcTimerLabel* self) {
	gboolean result = FALSE;
	gint _tmp0_;
	_tmp0_ = self->time;
	self->time = _tmp0_ + 1;
	pdfpc_timer_label_format_time (self);
	result = TRUE;
	return result;
}


gboolean pdfpc_timer_label_on_timeout (pdfpcTimerLabel* self) {
	g_return_val_if_fail (self != NULL, FALSE);
	return PDFPC_TIMER_LABEL_GET_CLASS (self)->on_timeout (self);
}


/**
         * Shows the corresponding time
         */
static void pdfpc_timer_label_real_format_time (pdfpcTimerLabel* self) {
	g_critical ("Type `%s' does not implement abstract method `pdfpc_timer_label_format_time'", g_type_name (G_TYPE_FROM_INSTANCE (self)));
	return;
}


void pdfpc_timer_label_format_time (pdfpcTimerLabel* self) {
	g_return_if_fail (self != NULL);
	PDFPC_TIMER_LABEL_GET_CLASS (self)->format_time (self);
}


/**
         * Shows a time (in seconds) in hh:mm:ss format, with an additional prefix
         */
void pdfpc_timer_label_show_time (pdfpcTimerLabel* self, guint timeInSecs, const gchar* prefix) {
	guint hours = 0U;
	guint minutes = 0U;
	guint seconds = 0U;
	guint _tmp0_;
	guint _tmp1_;
	guint _tmp2_;
	const gchar* _tmp3_;
	gchar* _tmp4_ = NULL;
	gchar* _tmp5_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (prefix != NULL);
	_tmp0_ = timeInSecs;
	hours = (_tmp0_ / 60) / 60;
	_tmp1_ = timeInSecs;
	minutes = (_tmp1_ / 60) % 60;
	_tmp2_ = timeInSecs;
	seconds = (_tmp2_ % 60) % 60;
	_tmp3_ = prefix;
	_tmp4_ = g_strdup_printf ("%s%.2u:%.2u:%.2u", _tmp3_, hours, minutes, seconds);
	_tmp5_ = _tmp4_;
	gtk_label_set_text ((GtkLabel*) self, _tmp5_);
	_g_free0 (_tmp5_);
}


static void pdfpc_timer_label_class_init (pdfpcTimerLabelClass * klass) {
	pdfpc_timer_label_parent_class = g_type_class_peek_parent (klass);
	PDFPC_TIMER_LABEL_CLASS (klass)->start = pdfpc_timer_label_real_start;
	PDFPC_TIMER_LABEL_CLASS (klass)->stop = pdfpc_timer_label_real_stop;
	PDFPC_TIMER_LABEL_CLASS (klass)->reset = pdfpc_timer_label_real_reset;
	PDFPC_TIMER_LABEL_CLASS (klass)->on_timeout = pdfpc_timer_label_real_on_timeout;
	PDFPC_TIMER_LABEL_CLASS (klass)->format_time = pdfpc_timer_label_real_format_time;
	G_OBJECT_CLASS (klass)->finalize = pdfpc_timer_label_finalize;
}


static void pdfpc_timer_label_instance_init (pdfpcTimerLabel * self) {
	self->time = 0;
	self->start_time = (time_t) 0;
	self->timeout = (guint) 0;
}


static void pdfpc_timer_label_finalize (GObject* obj) {
	pdfpcTimerLabel * self;
	self = PDFPC_TIMER_LABEL (obj);
	G_OBJECT_CLASS (pdfpc_timer_label_parent_class)->finalize (obj);
}


/**
     * Specialized label, which is capable of easily displaying a timer
     */
GType pdfpc_timer_label_get_type (void) {
	static volatile gsize pdfpc_timer_label_type_id__volatile = 0;
	if (g_once_init_enter (&pdfpc_timer_label_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (pdfpcTimerLabelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdfpc_timer_label_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (pdfpcTimerLabel), 0, (GInstanceInitFunc) pdfpc_timer_label_instance_init, NULL };
		GType pdfpc_timer_label_type_id;
		pdfpc_timer_label_type_id = g_type_register_static (GTK_TYPE_LABEL, "pdfpcTimerLabel", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&pdfpc_timer_label_type_id__volatile, pdfpc_timer_label_type_id);
	}
	return pdfpc_timer_label_type_id__volatile;
}


pdfpcCountdownTimer* pdfpc_countdown_timer_construct (GType object_type, gint duration, guint last_minutes, time_t start_time) {
	pdfpcCountdownTimer * self = NULL;
	time_t _tmp0_;
	gint _tmp1_;
	guint _tmp2_;
	GdkColor _tmp3_ = {0};
	GdkColor _tmp4_ = {0};
	_tmp0_ = start_time;
	self = (pdfpcCountdownTimer*) pdfpc_timer_label_construct (object_type, _tmp0_);
	_tmp1_ = duration;
	self->duration = _tmp1_;
	_tmp2_ = last_minutes;
	self->last_minutes = _tmp2_;
	gdk_color_parse ("orange", &_tmp3_);
	self->last_minutes_color = _tmp3_;
	gdk_color_parse ("red", &_tmp4_);
	self->negative_color = _tmp4_;
	return self;
}


pdfpcCountdownTimer* pdfpc_countdown_timer_new (gint duration, guint last_minutes, time_t start_time) {
	return pdfpc_countdown_timer_construct (PDFPC_TYPE_COUNTDOWN_TIMER, duration, last_minutes, start_time);
}


/**
         * Format the given time in a readable hh:mm:ss way and update the
         * label text
         */
static void pdfpc_countdown_timer_real_format_time (pdfpcTimerLabel* base) {
	pdfpcCountdownTimer * self;
	guint timeInSecs = 0U;
	gchar* _tmp0_;
	gchar* prefix;
	gint _tmp1_;
	guint _tmp17_;
	const gchar* _tmp18_;
	self = (pdfpcCountdownTimer*) base;
	_tmp0_ = g_strdup ("");
	prefix = _tmp0_;
	_tmp1_ = ((pdfpcTimerLabel*) self)->time;
	if (_tmp1_ < 0) {
		gchar* _tmp2_;
		gint _tmp3_;
		GdkColor _tmp4_;
		_tmp2_ = g_strdup ("-");
		_g_free0 (prefix);
		prefix = _tmp2_;
		_tmp3_ = ((pdfpcTimerLabel*) self)->time;
		timeInSecs = (guint) (-_tmp3_);
		_tmp4_ = ((pdfpcTimerLabel*) self)->pretalk_color;
		gtk_widget_modify_fg ((GtkWidget*) self, GTK_STATE_NORMAL, &_tmp4_);
	} else {
		gint _tmp5_;
		gint _tmp6_;
		_tmp5_ = ((pdfpcTimerLabel*) self)->time;
		_tmp6_ = self->duration;
		if (_tmp5_ < _tmp6_) {
			gint _tmp7_;
			gint _tmp8_;
			guint _tmp9_;
			guint _tmp10_;
			_tmp7_ = self->duration;
			_tmp8_ = ((pdfpcTimerLabel*) self)->time;
			timeInSecs = (guint) (_tmp7_ - _tmp8_);
			_tmp9_ = timeInSecs;
			_tmp10_ = self->last_minutes;
			if (_tmp9_ < (_tmp10_ * 60)) {
				GdkColor _tmp11_;
				_tmp11_ = self->last_minutes_color;
				gtk_widget_modify_fg ((GtkWidget*) self, GTK_STATE_NORMAL, &_tmp11_);
			} else {
				GdkColor _tmp12_;
				_tmp12_ = ((pdfpcTimerLabel*) self)->normal_color;
				gtk_widget_modify_fg ((GtkWidget*) self, GTK_STATE_NORMAL, &_tmp12_);
			}
		} else {
			GdkColor _tmp13_;
			gint _tmp14_;
			gint _tmp15_;
			gchar* _tmp16_;
			_tmp13_ = self->negative_color;
			gtk_widget_modify_fg ((GtkWidget*) self, GTK_STATE_NORMAL, &_tmp13_);
			_tmp14_ = ((pdfpcTimerLabel*) self)->time;
			_tmp15_ = self->duration;
			timeInSecs = (guint) (_tmp14_ - _tmp15_);
			_tmp16_ = g_strdup ("-");
			_g_free0 (prefix);
			prefix = _tmp16_;
		}
	}
	_tmp17_ = timeInSecs;
	_tmp18_ = prefix;
	pdfpc_timer_label_show_time ((pdfpcTimerLabel*) self, _tmp17_, _tmp18_);
	_g_free0 (prefix);
}


static void pdfpc_countdown_timer_class_init (pdfpcCountdownTimerClass * klass) {
	pdfpc_countdown_timer_parent_class = g_type_class_peek_parent (klass);
	PDFPC_TIMER_LABEL_CLASS (klass)->format_time = pdfpc_countdown_timer_real_format_time;
	G_OBJECT_CLASS (klass)->finalize = pdfpc_countdown_timer_finalize;
}


static void pdfpc_countdown_timer_instance_init (pdfpcCountdownTimer * self) {
	self->last_minutes = (guint) 5;
}


static void pdfpc_countdown_timer_finalize (GObject* obj) {
	pdfpcCountdownTimer * self;
	self = PDFPC_COUNTDOWN_TIMER (obj);
	G_OBJECT_CLASS (pdfpc_countdown_timer_parent_class)->finalize (obj);
}


GType pdfpc_countdown_timer_get_type (void) {
	static volatile gsize pdfpc_countdown_timer_type_id__volatile = 0;
	if (g_once_init_enter (&pdfpc_countdown_timer_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (pdfpcCountdownTimerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdfpc_countdown_timer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (pdfpcCountdownTimer), 0, (GInstanceInitFunc) pdfpc_countdown_timer_instance_init, NULL };
		GType pdfpc_countdown_timer_type_id;
		pdfpc_countdown_timer_type_id = g_type_register_static (PDFPC_TYPE_TIMER_LABEL, "pdfpcCountdownTimer", &g_define_type_info, 0);
		g_once_init_leave (&pdfpc_countdown_timer_type_id__volatile, pdfpc_countdown_timer_type_id);
	}
	return pdfpc_countdown_timer_type_id__volatile;
}


pdfpcEndTimeTimer* pdfpc_end_time_timer_construct (GType object_type, time_t end_time, guint last_minutes, time_t start_time) {
	pdfpcEndTimeTimer * self = NULL;
	guint _tmp0_;
	time_t _tmp1_;
	time_t _tmp2_;
	time_t _tmp3_;
	struct tm _tmp4_ = {0};
	_tmp0_ = last_minutes;
	_tmp1_ = start_time;
	self = (pdfpcEndTimeTimer*) pdfpc_countdown_timer_construct (object_type, 1000, _tmp0_, _tmp1_);
	_tmp2_ = end_time;
	self->end_time = _tmp2_;
	_tmp3_ = end_time;
	g_time_local (_tmp3_, &_tmp4_);
	self->end_time_object = _tmp4_;
	return self;
}


pdfpcEndTimeTimer* pdfpc_end_time_timer_new (time_t end_time, guint last_minutes, time_t start_time) {
	return pdfpc_end_time_timer_construct (PDFPC_TYPE_END_TIME_TIMER, end_time, last_minutes, start_time);
}


static void pdfpc_end_time_timer_real_start (pdfpcTimerLabel* base) {
	pdfpcEndTimeTimer * self;
	time_t _tmp0_;
	struct tm _tmp1_ = {0};
	time_t _tmp2_ = 0;
	time_t now;
	time_t _tmp3_;
	self = (pdfpcEndTimeTimer*) base;
	_tmp0_ = time (NULL);
	g_time_local (_tmp0_, &_tmp1_);
	_tmp2_ = mktime (&_tmp1_);
	now = _tmp2_;
	_tmp3_ = self->end_time;
	((pdfpcCountdownTimer*) self)->duration = (gint) (_tmp3_ - now);
	PDFPC_TIMER_LABEL_CLASS (pdfpc_end_time_timer_parent_class)->start ((pdfpcTimerLabel*) PDFPC_COUNTDOWN_TIMER (self));
}


static gchar* g_time_format (struct tm *self, const gchar* format) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* buffer;
	gint buffer_length1;
	gint _buffer_size_;
	gchar* _tmp1_;
	gint _tmp1__length1;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gint _tmp3__length1;
	gchar* _tmp4_;
	g_return_val_if_fail (format != NULL, NULL);
	_tmp0_ = g_new0 (gchar, 64);
	buffer = _tmp0_;
	buffer_length1 = 64;
	_buffer_size_ = buffer_length1;
	_tmp1_ = buffer;
	_tmp1__length1 = buffer_length1;
	_tmp2_ = format;
	strftime (_tmp1_, _tmp1__length1, _tmp2_, &(*self));
	_tmp3_ = buffer;
	_tmp3__length1 = buffer_length1;
	_tmp4_ = g_strdup ((const gchar*) _tmp3_);
	result = _tmp4_;
	buffer = (g_free (buffer), NULL);
	return result;
}


static void pdfpc_end_time_timer_real_stop (pdfpcTimerLabel* base) {
	pdfpcEndTimeTimer * self;
	gchar* _tmp0_ = NULL;
	gchar* _tmp1_;
	self = (pdfpcEndTimeTimer*) base;
	PDFPC_TIMER_LABEL_CLASS (pdfpc_end_time_timer_parent_class)->stop ((pdfpcTimerLabel*) PDFPC_COUNTDOWN_TIMER (self));
	_tmp0_ = g_time_format (&self->end_time_object, "Until %H:%M");
	_tmp1_ = _tmp0_;
	gtk_label_set_text ((GtkLabel*) self, _tmp1_);
	_g_free0 (_tmp1_);
}


static void pdfpc_end_time_timer_real_reset (pdfpcTimerLabel* base) {
	pdfpcEndTimeTimer * self;
	guint _tmp0_;
	self = (pdfpcEndTimeTimer*) base;
	PDFPC_TIMER_LABEL_CLASS (pdfpc_end_time_timer_parent_class)->reset ((pdfpcTimerLabel*) PDFPC_COUNTDOWN_TIMER (self));
	_tmp0_ = ((pdfpcTimerLabel*) self)->timeout;
	if (_tmp0_ == ((guint) 0)) {
		gchar* _tmp1_ = NULL;
		gchar* _tmp2_;
		_tmp1_ = g_time_format (&self->end_time_object, "Until %H:%M");
		_tmp2_ = _tmp1_;
		gtk_label_set_text ((GtkLabel*) self, _tmp2_);
		_g_free0 (_tmp2_);
	}
}


static gboolean pdfpc_end_time_timer_real_on_timeout (pdfpcTimerLabel* base) {
	pdfpcEndTimeTimer * self;
	gboolean result = FALSE;
	gint _tmp0_;
	gboolean _tmp6_ = FALSE;
	self = (pdfpcEndTimeTimer*) base;
	_tmp0_ = ((pdfpcTimerLabel*) self)->time;
	if (_tmp0_ == (-1)) {
		time_t _tmp1_;
		struct tm _tmp2_ = {0};
		time_t _tmp3_ = 0;
		time_t now;
		time_t _tmp4_;
		time_t _tmp5_;
		_tmp1_ = time (NULL);
		g_time_local (_tmp1_, &_tmp2_);
		_tmp3_ = mktime (&_tmp2_);
		now = _tmp3_;
		_tmp4_ = self->end_time;
		_tmp5_ = now;
		((pdfpcCountdownTimer*) self)->duration = (gint) (_tmp4_ - _tmp5_);
	}
	_tmp6_ = PDFPC_TIMER_LABEL_CLASS (pdfpc_end_time_timer_parent_class)->on_timeout ((pdfpcTimerLabel*) PDFPC_COUNTDOWN_TIMER (self));
	result = _tmp6_;
	return result;
}


static void pdfpc_end_time_timer_class_init (pdfpcEndTimeTimerClass * klass) {
	pdfpc_end_time_timer_parent_class = g_type_class_peek_parent (klass);
	PDFPC_TIMER_LABEL_CLASS (klass)->start = pdfpc_end_time_timer_real_start;
	PDFPC_TIMER_LABEL_CLASS (klass)->stop = pdfpc_end_time_timer_real_stop;
	PDFPC_TIMER_LABEL_CLASS (klass)->reset = pdfpc_end_time_timer_real_reset;
	PDFPC_TIMER_LABEL_CLASS (klass)->on_timeout = pdfpc_end_time_timer_real_on_timeout;
	G_OBJECT_CLASS (klass)->finalize = pdfpc_end_time_timer_finalize;
}


static void pdfpc_end_time_timer_instance_init (pdfpcEndTimeTimer * self) {
}


static void pdfpc_end_time_timer_finalize (GObject* obj) {
	pdfpcEndTimeTimer * self;
	self = PDFPC_END_TIME_TIMER (obj);
	G_OBJECT_CLASS (pdfpc_end_time_timer_parent_class)->finalize (obj);
}


GType pdfpc_end_time_timer_get_type (void) {
	static volatile gsize pdfpc_end_time_timer_type_id__volatile = 0;
	if (g_once_init_enter (&pdfpc_end_time_timer_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (pdfpcEndTimeTimerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdfpc_end_time_timer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (pdfpcEndTimeTimer), 0, (GInstanceInitFunc) pdfpc_end_time_timer_instance_init, NULL };
		GType pdfpc_end_time_timer_type_id;
		pdfpc_end_time_timer_type_id = g_type_register_static (PDFPC_TYPE_COUNTDOWN_TIMER, "pdfpcEndTimeTimer", &g_define_type_info, 0);
		g_once_init_leave (&pdfpc_end_time_timer_type_id__volatile, pdfpc_end_time_timer_type_id);
	}
	return pdfpc_end_time_timer_type_id__volatile;
}


pdfpcCountupTimer* pdfpc_countup_timer_construct (GType object_type, time_t start_time) {
	pdfpcCountupTimer * self = NULL;
	time_t _tmp0_;
	_tmp0_ = start_time;
	self = (pdfpcCountupTimer*) pdfpc_timer_label_construct (object_type, _tmp0_);
	return self;
}


pdfpcCountupTimer* pdfpc_countup_timer_new (time_t start_time) {
	return pdfpc_countup_timer_construct (PDFPC_TYPE_COUNTUP_TIMER, start_time);
}


/**
         * Format the given time in a readable hh:mm:ss way and update the
         * label text
         */
static void pdfpc_countup_timer_real_format_time (pdfpcTimerLabel* base) {
	pdfpcCountupTimer * self;
	guint timeInSecs = 0U;
	gchar* _tmp0_;
	gchar* prefix;
	gint _tmp1_;
	guint _tmp7_;
	const gchar* _tmp8_;
	self = (pdfpcCountupTimer*) base;
	_tmp0_ = g_strdup ("");
	prefix = _tmp0_;
	_tmp1_ = ((pdfpcTimerLabel*) self)->time;
	if (_tmp1_ < 0) {
		gchar* _tmp2_;
		gint _tmp3_;
		GdkColor _tmp4_;
		_tmp2_ = g_strdup ("-");
		_g_free0 (prefix);
		prefix = _tmp2_;
		_tmp3_ = ((pdfpcTimerLabel*) self)->time;
		timeInSecs = (guint) (-_tmp3_);
		_tmp4_ = ((pdfpcTimerLabel*) self)->pretalk_color;
		gtk_widget_modify_fg ((GtkWidget*) self, GTK_STATE_NORMAL, &_tmp4_);
	} else {
		gint _tmp5_;
		GdkColor _tmp6_;
		_tmp5_ = ((pdfpcTimerLabel*) self)->time;
		timeInSecs = (guint) _tmp5_;
		_tmp6_ = ((pdfpcTimerLabel*) self)->normal_color;
		gtk_widget_modify_fg ((GtkWidget*) self, GTK_STATE_NORMAL, &_tmp6_);
	}
	_tmp7_ = timeInSecs;
	_tmp8_ = prefix;
	pdfpc_timer_label_show_time ((pdfpcTimerLabel*) self, _tmp7_, _tmp8_);
	_g_free0 (prefix);
}


static void pdfpc_countup_timer_class_init (pdfpcCountupTimerClass * klass) {
	pdfpc_countup_timer_parent_class = g_type_class_peek_parent (klass);
	PDFPC_TIMER_LABEL_CLASS (klass)->format_time = pdfpc_countup_timer_real_format_time;
}


static void pdfpc_countup_timer_instance_init (pdfpcCountupTimer * self) {
}


GType pdfpc_countup_timer_get_type (void) {
	static volatile gsize pdfpc_countup_timer_type_id__volatile = 0;
	if (g_once_init_enter (&pdfpc_countup_timer_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (pdfpcCountupTimerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) pdfpc_countup_timer_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (pdfpcCountupTimer), 0, (GInstanceInitFunc) pdfpc_countup_timer_instance_init, NULL };
		GType pdfpc_countup_timer_type_id;
		pdfpc_countup_timer_type_id = g_type_register_static (PDFPC_TYPE_TIMER_LABEL, "pdfpcCountupTimer", &g_define_type_info, 0);
		g_once_init_leave (&pdfpc_countup_timer_type_id__volatile, pdfpc_countup_timer_type_id);
	}
	return pdfpc_countup_timer_type_id__volatile;
}


