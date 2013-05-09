run: a.out
	./a.out
a.out:
	gcc -c main.c -Wall -Wextra
	gcc -c prefijos.c -Wall -Wextra
	gcc -c sufijos.c -Wall -Wextra
	gcc -c subcadenas.c -Wall -Wextra
	gcc -c operaciones.c -Wall -Wextra
	gcc main.o prefijos.o subcadenas.o sufijos.o operaciones.o
	#gcc main.c -Wall -Wextra	
clean:
	rm ./a.out
	rm ./main.o
	rm ./operaciones.o
	rm ./subcadenas.o
	rm ./prefijos.o
	rm ./sufijos.o

