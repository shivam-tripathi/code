/** THis is comment
 ** GTK+ is a widget toolkit.
 ** It is event driven.
 ** It is implemented in GObject, object oriented frame work for C.
 ** It depends on the following libraries:
 **      GLib - General purpose utility library
 **      GObject - type system, fundamental type (object type and a signal system)
 **      GIO - VFS API, network programming, DBus communications
 **      cairo - 2D graphics library with support for multiple outputs
 **      Pango - Text handling library
 **      ATK - Accessibility toolkit, generic interface for accessing GUI
 **      GdkPixBuf - Library to create pixel buffer, use with GtkImage to show images
 **      GDK - Abstraction layer to support GTK+ on multiple windowing systems (x11, windows, OSX)
 **      GTK+ - Library containing GUI elements like widgets (GtkButton, GtkTextView, etc)
 **/

#include <gtk/gtk.h>

static void
activate (GtkApplication* app, gpointer user_data)
{
  // Create a new widget of type window belonging to GtkApplication
  GtkWidget *window;
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "New window!");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 500);
  gtk_widget_show_all(window);
}


// In GTK+ application, function of main is to create and run a GtkApplication
// This is done using gtk_application_new("application.name", flags)
// g_signal_connect(GtkApplication *, property_name, G_CALLBACK(function), NULL) connects a signal
// g_application_run(G_APPLICATION(GtkApplication), argc, argv) runs the application

gint
main (gint   argc,
      gchar *argv[])
{
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}

