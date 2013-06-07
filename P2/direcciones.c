#include "direcciones.h"

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