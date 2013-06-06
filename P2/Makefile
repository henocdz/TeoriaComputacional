run: a.out
	./a.out

a.out:
	gcc -c `pkg-config --cflags glib-2.0 gtk+-3.0`  main.c  `pkg-config --libs glib-2.0 gtk+-3.0`
	gcc `pkg-config --cflags glib-2.0 gtk+-3.0`  main.o  `pkg-config --libs glib-2.0 gtk+-3.0`

clean:
	rm ./a.out
	rm ./main.o