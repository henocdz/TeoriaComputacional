#pragma once

#define TOLERANCIA 10

struct dirs{
    int dir1[2],dir3[2],dir5[2],dir7[2];
};

int calculaDireccion(int refX,int refY,int x,int y);