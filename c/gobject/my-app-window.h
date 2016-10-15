#ifndef _my_app_window_h_
#define _my_app_window_h_

G_BEGIN_DECLS

#define MY_APP_TYPE_WINDOW (my_app_window_get_type())

G_DECLARE_FINAL_TYPE(MyAppWindow, my_app_window, MY_APP, WINDOW, GtkApplicationWindow)

MyAppWindow (*my_app_window_new) (void);

G_END_DECLS

#endif 
/* _my_app_window_h_ */
