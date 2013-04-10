#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <linux/input.h>
#include <fcntl.h>
#include <X11/Xlib.h>

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

int main()
{
    int fd;
    struct input_event ie;
    Display *dpy;
    Window root, child;
    XWindowAttributes winDD;
    int rootX, rootY, winX, winY;
    unsigned int mask;

    dpy = XOpenDisplay(NULL);
    XGetWindowAttributes(dpy,DefaultRootWindow(dpy),&winDD);
    XQueryPointer(dpy,DefaultRootWindow(dpy),&root,&child,
    &rootX,&rootY,&winX,&winY,&mask);

    printf("Dimensiones: %dx%d\n  Tolerancia: \n \t Tanchura: %.2f \n\t Taltura: %.2f\n\n",winDD.width,winDD.height,winDD.width*0.10,winDD.height*0.10);

    if((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
        perror("opening device");
        exit(EXIT_FAILURE);
    }


    int moves = 0;
    int prevX,prevY;
    prevX = rootX;
    prevY = rootY;

    while(read(fd, &ie, sizeof(struct input_event))) {
        moves++;
        if (moves > 20){

            XQueryPointer(dpy,DefaultRootWindow(dpy),&root,&child,
            &rootX,&rootY,&winX,&winY,&mask);

            int dir = calculaDireccion(prevX,prevY,rootX,rootY);
            printf("X: %d \t Y: %d \t Direccion: %d \n\n", rootX,rootY,dir); 
            moves = 0;
            prevX = rootX;
            prevY = rootY;
        }
    }

    return 0;
}

