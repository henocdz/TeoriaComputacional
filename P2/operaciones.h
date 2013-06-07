#pragma once

#define MOUSEFILE "/dev/input/mice"



void max_unmax(int max_min);


//gcc `pkg-config --cflags glib-2.0 gtk+-3.0` main.c  `pkg-config --libs glib-2.0 gtk+-3.0`


void allWindows();