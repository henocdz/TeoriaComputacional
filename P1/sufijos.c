/**
        @file sufijos.c
        @author Henoc Díaz
        @date Martes 12 de Marzo de 2013
        @version 0
        @brief Muestra los sufijos de la cadena dada, generados por este mismo archivo
*/


#include <stdio.h>

/**
	@brief Genera y muestra los sufijos de la cadena recibida.
	@param palabra Apuntador a arreglo char que contiene la palabra
	@param l longitud de palabra
*/
void sufijos(char *palabra, int l){
	int i = l,x;
	while(i>0){
		i--;
		for (x=i; x < l; x++)
			printf("%c", palabra[x]);

		printf(" \n");
	}
	printf("Epsilon\n");
}
