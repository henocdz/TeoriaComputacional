run: a.out
	./a.out

a.out:


	gcc -c `pkg-config --cflags glib-2.0 gtk+-3.0`  main.c  `pkg-config --libs glib-2.0 gtk+-3.0`
	gcc -c `pkg-config --cflags glib-2.0 gtk+-3.0`  direcciones.c `pkg-config --libs glib-2.0 gtk+-3.0`
	gcc -c `pkg-config --cflags glib-2.0 gtk+-3.0`  operaciones.c  `pkg-config --libs glib-2.0 gtk+-3.0`


	gcc `pkg-config --cflags glib-2.0 gtk+-3.0`  main.o direcciones.o operaciones.o `pkg-config --libs glib-2.0 gtk+-3.0`

clean:
	rm ./a.out
	rm ./main.o
	rm ./direcciones.o
	rm ./operaciones.o