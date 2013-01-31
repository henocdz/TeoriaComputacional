#include <stdio.h>
#include <stdlib.h>


int len(char *c){ //Longitud exacta de la cadena ingresada
	int  r = 0;
	while(c[r] !='\0')
		r++;

	return r;
}

void prefijos(char *palabra,int l){ //Calcular y mostrar los prefijos
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

int limi(int l){
	int r = 0;
	int i = r;

	for(i;i<=l;i++){
		r+=i;
	}

	return r;


}

void subcadenas(char *palabra,int l){
	int lim = 1; //limite de caracteres que toma
	int lm = limi(l);
	int li = 1;
	int i,x,y;
	i = x = y = 0;


	while(y < l){
		while(x<l && i <= 5){
			
			if(i==(l-(lim-1)))
					break;

			for(i;i<li;i++)
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