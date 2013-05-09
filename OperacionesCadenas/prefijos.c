/**
        @file prefijos.c
        @author Henoc Díaz
        @date Martes 12 de Marzo de 2013
        @version 0
        @brief A traves de una funcion a la cual se le pasa una cadena, genera sus prefijos y los muestra en pantalla*/

#include <stdio.h>
/**
	@brief Calcular y mostrar los prefijos
	@param palabra apuntador a char
	@param l longitud de palabra
*/
void prefijos(char *palabra,int l){
	int i,x;
	i = x = 0;
	while(i<l){
		for (x=0; x <= i; x++)
			printf("%c", palabra[x]);
		
		i++;
		printf("\n");
	}
	printf("Epsilon\n");
}
