/* -*- coding: utf-8; -*- */
/* gtk_helloworld.c - traditional GTK+ helloworld program */

#include <gtk/gtk.h>

void hello(GtkWidget *widget, gpointer data);
gint delete_event(GtkWidget *widget, GdkEvent event, gpointer data);
void end_program(GtkWidget *widget, gpointer data);

int main(int argc, char* argv[])
{
	// Initialize gtk
	gtk_init(&argc, &argv);

	// Main container
	GtkWindow *window;

	// One of the widgets in the main container
	GtkButton *button;

	// Initialize main container
	window = g_object_new(GTK_TYPE_WINDOW, 
		"default-height", 200,
		"default-width", 200,
		"title", "Hello, world!",
		"border-width", 12,
		NULL);

	//Connect signal of the main container to the handlers
	g_signal_connect(window, 
		"delete-event", G_CALLBACK(delete_event),
		NULL);
	g_signal_connect(window, 
		"destroy", G_CALLBACK(end_program), 
		NULL);

	// Create button widget
	button = g_object_new(GTK_TYPE_BUTTON,
		"label", "Hello, World! \n ***Click Here***",
		"use-underline", TRUE,
		NULL);

	// Connect button widget signals to the handlers
	g_signal_connect(button,
		"clicked", G_CALLBACK(hello), 
		NULL);
	g_signal_connect_swapped(button, 
		"clicked", G_CALLBACK(gtk_widget_destroy), window);

	// Display boilerplate
	gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(button));
	gtk_widget_show_all(GTK_WIDGET(window));

	// Start main loop
	gtk_main();

	return 0;
}

void hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello, World!\n");
}

gint delete_event(GtkWidget *widget, GdkEvent event, gpointer data)
{
	return FALSE;
}

void end_program(GtkWidget *widget, gpointer data)
{
	gtk_main_quit();
}
