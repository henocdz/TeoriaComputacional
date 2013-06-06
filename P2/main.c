#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <linux/input.h>
#include <fcntl.h>
#include <X11/Xlib.h>


#include <gtk/gtk.h>
#include <gdk/gdk.h>

#define MOUSEFILE "/dev/input/mice"
#define TOLERANCIA 10


struct dirs{
    int dir1[2],dir3[2],dir5[2],dir7[2];
};


int calculaDireccion(int refX,int refY,int x,int y){
    int dir = 0;
    struct dirs d;

    d.dir1[0] = refX - TOLERANCIA;
    d.dir1[1] = refX + TOLERANCIA;

    d.dir3[0] = refY - TOLERANCIA;
    d.dir3[1] = refY + TOLERANCIA;

    d.dir5[0] = refX - TOLERANCIA;
    d.dir5[1] = d.dir1[1];


    d.dir7[0] = d.dir3[0];
    d.dir7[0] = d.dir3[1];

    if( x > d.dir1[1] ){
        if ( y < d.dir3[0] ){
          dir = 2;
        }else if( y > d.dir3[1] ){
          dir = 4;
        }else{
          dir = 3;
        }
    }else if( x < d.dir1[0]){
      if ( y < d.dir3[0] ){
        dir = 8;
      }else if( y > d.dir3[1] ){
        dir = 6;
      }else{
        dir = 7;
      }
    }else{
      if( y < refY ){
        dir = 1;
      }else{
        dir = 5;
      }
    }


    return dir;
}


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

int main(int argc,char *argv[])
{

    printf("\n\n // \t EL PROGRAMA SOLO MAXIMIZA Y MINIMIZA LA VENTANA ACTIVA \n");
    printf(" // \t SE DEBE CORRER COMO SUPERUSUARIO \n\n\n");
    
    int fd;
    struct input_event ie;
    Display *dpy;
    Window root, child;
    XWindowAttributes winDD;
    int rootX, rootY, winX, winY;
    unsigned int mask;


    gtk_init(&argc,&argv);
    gdk_init(&argc,&argv);


    dpy = XOpenDisplay(NULL);
    XGetWindowAttributes(dpy,DefaultRootWindow(dpy),&winDD);
    XQueryPointer(dpy,DefaultRootWindow(dpy),&root,&child,
    &rootX,&rootY,&winX,&winY,&mask);

    if((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
        perror("opening device");
        exit(EXIT_FAILURE);
    }


    int moves = 0,c = 0;
    int prevX,prevY;
    prevX = rootX;
    prevY = rootY;
    int mm = 0;
    int max_min = 0;
    while(read(fd, &ie, sizeof(struct input_event))) {
        moves++;
        c++;
        if (moves > 160){

            XQueryPointer(dpy,DefaultRootWindow(dpy),&root,&child,
            &rootX,&rootY,&winX,&winY,&mask);

            int dir = calculaDireccion(prevX,prevY,rootX,rootY);
            printf("X: %d \t Y: %d \t Direccion: %d \n\n", rootX,rootY,dir); 
            moves = 0;
            prevX = rootX;
            prevY = rootY;

           if(max_min)
            max_min  = 0;
            else 
                max_min = 1;

            max_unmax(max_min);
        }

        if(c > 200){
            mm++;
            //max_unmax(mm);

            //allWindows();

            if(mm>1)
                mm = -1;

            c = 0;
        }
    }

    return 0;
}

