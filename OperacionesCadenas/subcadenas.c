/**
        @file subcadenas.c
        @author Henoc Díaz
        @date Martes 12 de Marzo de 2013
        @version 0
        @brief Genera y muestra las subcadenas, en base a la cadena que se le haya pasado
*/


#include <stdio.h>

int limi(int l){
	int r = 0;
	int i;

	for(i=0;i<=l;i++)
		r+=i;

	return r;
}

/**
	@brief Genera y muestra la subcadenas de la cadena recibida.
	@param palabra apuntador a arreglo de caracteres que contiene la palabra
	@param l numero de caracteres que contiene el arreglo
*/
void subcadenas(char *palabra,int l){
	int lim = 1; //limite de caracteres que toma
	int li = 1;
	int i,x,y;
	i = x = y = 0;


	while(y < l){
		while(x<l && i <= 5){
			
			if(i==(l-(lim-1)))
					break;

			for(i=i;i<li;i++)
				printf("%c",palabra[i]);

			printf("\n");
			i -= lim - 1;
			li ++;

			x++;
		}

		li = ++lim;
		x = i = 0;
		y++;

		printf("\n");
	}
	}
