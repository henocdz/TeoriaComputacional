#include <stdio.h>

int main() 
{ 
	char cinta [13]; 
	int terminar = 0; 
	int ubicacion=0; 
	int estado=0; 
	int x;
	printf(" Programa que imita la maquina de turing"); 
	printf("\n ingrese los valores de la cinta... ");
	scanf("%s", cinta); 
	printf(" %i",estado); 
	printf("\n %s \n", cinta); 
	getchar();
	do 
	{ 
		if (cinta[ubicacion]==NULL)
			terminar=1;
		else 
			if (estado==0) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					ubicacion++; 
					estado=7; 
				} 
				else 
					if (cinta[ubicacion]=='1') 
					{ 
						cinta[ubicacion]='0'; 
						ubicacion++; 
						estado=1; 
				} 
			} 
		else 
			if (estado==1) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					++ubicacion; 
					estado=2; 
				} 
				else 
					if (cinta[ubicacion]=='1') 
					{ 
						cinta[ubicacion]='1'; 
						++ubicacion; 
						estado=1; 
					} 
			} 
		else 
			if (estado==2) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					++ubicacion; 
					estado=3; 
				} 
				else 
				if (cinta[ubicacion]=='1') 
				{ 
					cinta[ubicacion]='1'; 
					++ubicacion; 
					estado=2; 
				} 
			} 
		else 
		if (estado==3) 
		{ 
			if (cinta[ubicacion]=='0') 
			{ 
				cinta[ubicacion]='1'; 
				ubicacion--; 
				estado=4; 
			} 
			else 
				if (cinta[ubicacion]=='1') 
				{ 
					cinta[ubicacion]='1'; 
					++ubicacion; 
					estado=3; 
				} 
		} 
		else 
			if (estado==4) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					ubicacion--; 
					estado=5; 
				} 
				else 
					if (cinta[ubicacion]=='1') 
					{ 
						cinta[ubicacion]='1'; 
						ubicacion--; 
						estado=4; 
					} 
			} 
		else 
			if (estado==5) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					ubicacion--; 
					estado=6; 
				} 
			else 
				if (cinta[ubicacion]=='1') 
				{ 
					cinta[ubicacion]='1'; 
					ubicacion--; 
					estado=5; 
				} 
			} 
		else 
		if (estado==6) 
		{ 
			if (cinta[ubicacion]=='0') 
			{ 
				cinta[ubicacion]='1'; 
				++ubicacion; 
				estado=0; 
			} 
			else 
				if (cinta[ubicacion]=='1') 
				{ 
					cinta[ubicacion]='1'; 
					ubicacion--; 
					estado=6; 
				} 
		} 
		else 
			if (estado==7) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					++ubicacion; 
					estado=12; 
				} 
				else 
				if (cinta[ubicacion]=='1') 
				{ 
					cinta[ubicacion]='0'; 
					++ubicacion; 
					estado=8; 
				} 
			} 
		else 
			if (estado==8) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					++ubicacion; 
					estado=9; 
				} 
			else 
				if (cinta[ubicacion]=='1') 
				{ 
					cinta[ubicacion]='1'; 
					++ubicacion; 
					estado=8; 
				} 
			} 
		else 
			if (estado==9) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='1'; 
					ubicacion--; 
					estado=10; 
				} 
				else 
					if (cinta[ubicacion]=='1') 
					{ 
						cinta[ubicacion]='1'; 
						++ubicacion; 
						estado=9; 
					} 
			} 
		else 
			if (estado==10) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='0'; 
					ubicacion--; 
					estado=11; 
				} 
				else 
					if (cinta[ubicacion]=='1') 
					{ 
						cinta[ubicacion]='1'; 
						ubicacion--; 
						estado=10; 
					} 
			} 
		else 
			if (estado==11) 
			{ 
				if (cinta[ubicacion]=='0') 
				{ 
					cinta[ubicacion]='1'; 
					++ubicacion; 
					estado=7; 
				} 
				else 
					if (cinta[ubicacion]=='1') 
					{ 
						cinta[ubicacion]='1'; 
						ubicacion--; 
						estado=11; 
					} 
			} 
		else
			terminar=1; 

		printf(" ");

		for(x=0;x;){ 
			printf(" "); 
		} 

		printf("%i",estado); 
		printf("\n %s \n", cinta); 
		getchar(); 
	}while (terminar!=1); 

		printf("\n El resultado es: %s ", cinta); 
		getchar(); 
		getchar(); 
		return 0; 
} 