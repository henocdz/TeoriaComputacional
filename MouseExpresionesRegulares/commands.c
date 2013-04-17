#include <stdlib.h>
#include <stdio.h>
#include <glib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>

int main(int argc,char *argv[]){
	
	GdkScreen *sc = NULL;
	
	gtk_init(&argc,&argv);

	sc = gdk_screen_get_default();

	if(sc == NULL){
		printf("No funciona! :(");
		exit(1);
	}
	
	GList *windows;
	GdkWindow *wi;
	windows = gdk_screen_get_window_stack(sc);
	//windows = gdk_screen_get_toplevel_windows(sc);
	GList *g ;
/*
	wi = gdk_screen_get_active_window(sc);

	if(wi == NULL)
	{
		printf("No funciona :(\n");
			exit(1);
	}
	gdk_window_unmaximize(wi);
*/
	g = windows;

	while(g != NULL){
		GdkWindow *w = (GdkWindow *)g->data;
		GdkWindow *tl =  gdk_get_default_root_window();

		gdk_window_set_keep_above(w,TRUE);

		//gdk_window_maximize(w);

		printf("%d x %d \n",gdk_window_get_width(w),gdk_window_get_height(w));
		g = g->next;
	}

	return 0;
}
