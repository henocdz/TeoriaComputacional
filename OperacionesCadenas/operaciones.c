/**
        @file operaciones.c
        @author Henoc Díaz
        @date Martes 12 de Marzo de 2013
        @version 0
        @brief Contiene dos funciones auxiliares para obtener que utilizan subcadenas.c y main.c
*/


/**
	@brief Devuelve la longitud de la cadena ingresada.
	@param c apuntador a una cadena
	@return  Entero con la longitud máxima y cadena
*/
int len(char *c){
	int  r = 0;
	while(c[r] !='\0')
		r++;
	return r;
}

