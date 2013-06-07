#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include <linux/input.h>
#include <fcntl.h>
#include <X11/Xlib.h>


#include <gtk/gtk.h>
#include <gdk/gdk.h>

#define MOUSEFILE "/dev/input/mice"





void max_unmax(int max_min){
    //Maximizar minimizar
    GdkScreen *sc = NULL;

    sc = gdk_screen_get_default();

    if(sc == NULL){
        printf("No funciona! :(");
        exit(1);
    }

    GdkWindow *wi,*bck;
    
    if(max_min)
        gdk_window_maximize(gdk_screen_get_active_window(sc));
    else
        gdk_window_unmaximize(gdk_screen_get_active_window(sc));


    gdk_window_deiconify(gdk_screen_get_active_window(sc));
    gdk_window_show(gdk_screen_get_active_window(sc));
    gdk_window_raise(gdk_screen_get_active_window(sc));


}


//gcc `pkg-config --cflags glib-2.0 gtk+-3.0` main.c  `pkg-config --libs glib-2.0 gtk+-3.0`


void allWindows(){
        GdkScreen *sc = NULL;

    sc = gdk_screen_get_default();

    if(sc == NULL){
        printf("No funciona! :(");
        exit(1);
    }

    GdkWindow *wi,*bck;

        
    GList *windows,*g;
    windows = gdk_screen_get_window_stack(sc);

    ///*
    g = g_list_next(windows);

    wi = gdk_screen_get_active_window(sc);
        
    //gdk_window_iconify(wi);

    printf("%d x %d \n",gdk_window_get_width(wi),gdk_window_get_height(wi));

    //windows = gdk_screen_get_toplevel_windows(sc);
    //gdk_window_iconify(g->data);
    GdkWindow *n;

    n = (GdkWindow *)g->data;

    gdk_window_deiconify(n);
    gdk_window_raise(n);
    gdk_window_show(n); 

    printf("%d x %d \n",gdk_window_get_width(n),gdk_window_get_height(n));

    //gdk_window_iconify(n);

    //gdk_window_scroll(g->data,400,0);

    g_object_unref(g->data);
    g_list_free(windows);

}