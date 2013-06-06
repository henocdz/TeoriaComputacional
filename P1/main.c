/**
	@file main.c
	@author Henoc Díaz
	@date Martes 12 de Marzo de 2013
	@version 0
	@brief Este archivo genera y muestra las subcadenas, prefijos y sufijos de una cadena dada
*/
#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
#include "sufijos.h"
#include "prefijos.h"
#include "subcadenas.h"

/**
	@brief
	@mainpage Reporte Práctica 1
	@section Introducción
		Se buscar crear un programa que al darle una cadena, genere sus subcadenas, prefijos y subfijos.
	@section Herramientas
		Doxygen

		Vim

		Lenguaje C
	@section Procedimiento
		@subsection Etapa_1
			Desarrollo de función para obtener subcadenas, también programando las funciones auxiliares para obtener longitud de la cadena ingresada y el número máximo de subcadenas que podría tener la cadena dada.
		@subsection Etapa_2
			Desarrollo de funciones para obtener prefijos y sufijos
		@subsection Etapa_3
			Pruebas del programa con varias cadenas,también probadas a mano y comparación de resultados
	@section Integrantes
		Henoc Diaz Hernandez - 2012630109
	@section Conclusiones
		@subsection Henoc_Díaz_Hernández
		Un programa sencillo como este me enseno a generar una buena documentacion asi como una buena organizacion de codigo a traves de los archivos. Tambien me sirvio como repaso de lenguaje C que no tocaba hace mas de medio ano.
*/

int main(void)
{
	char palabra[100];
	printf("Introduce la cadena: \n");
	gets(palabra);


	int l = len(palabra);

	system("clear");
	printf("Información de la cadena: %s\n", palabra);
	
	printf("\nPrefijos => \n");
	prefijos(palabra,l);

	printf("\nSufijos => \n");
	sufijos(palabra,l);

	printf("\nSubcadenas =>\n");
	subcadenas(palabra,l);

	return 0;
}
