#include "my-app-window.h"

struct _MyAppWindow
{
	GtkApplicationWindow parent_instance;
	// Instance properties
};

G_DEFINE_TYPE(MyAppWindow, my_app_window, GTK_TYPE_APPLICATION_WINDOW)

static void 
my_app_window_init(MyAppWindow *object)
{
	// virtual function overrides
	// properties and signal definitions 
}



