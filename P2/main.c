#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "direcciones.h"
#include "operaciones.h"


#include <linux/input.h>
#include <fcntl.h>
#include <X11/Xlib.h>


#include <gtk/gtk.h>
#include <gdk/gdk.h>


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
        if (moves > 90){

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

