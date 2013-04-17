#include <stdlib.h>
#include <stdio.h>
#include <glib.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>

GdkWindow * minimizar(){

	printf("Minimizando\n");


	GdkScreen *sc = NULL;

	sc = gdk_screen_get_default();

	if(sc == NULL){
		printf("No funciona! :(");
		exit(1);
	}

	GdkWindow *wi,*bck;

	wi = gdk_screen_get_active_window(sc);

	if(wi == NULL)
	{
		printf("No funciona :(\n");
			exit(1);
	}

	bck = wi;


	gdk_window_hide(wi);
	printf("%d x %d \n",gdk_window_get_width(wi),gdk_window_get_height(wi));
	return bck;
}


GdkWindow * maximizar(){

	printf("Maximizando\n");


	GdkScreen *sc = NULL;

	sc = gdk_screen_get_default();

	if(sc == NULL){
		printf("No funciona! :(");
		exit(1);
	}

	GdkWindow *wi,*bck;

	if(wi == NULL)
	{
		printf("No funciona :(\n");
			exit(1);
	}

	bck = wi;


	//gdk_window_deiconify(wi);
	gdk_window_show(wi);
	printf("%d x %d \n",gdk_window_get_width(wi),gdk_window_get_height(wi));
	return bck;
}

void allWindows(){
	GdkScreen *sc = NULL;

	sc = gdk_screen_get_default();

	if(sc == NULL){
		printf("No funciona! :(");
		exit(1);
	}

	GdkWindow *wi,*bck;

	/*wi = gdk_screen_get_active_window(sc);

	if(wi == NULL){
		printf("No funciona :(\n");
			exit(1);
	}*/

		
	GList *windows,*g;
	windows = gdk_screen_get_window_stack(sc);
	wi = gdk_screen_get_active_window(sc);
	//windows = gdk_screen_get_toplevel_windows(sc);
	gdk_window_iconify(gdk_screen_get_active_window(sc));
	//printf("%d x %d \n",gdk_window_get_width(gdk_screen_get_active_window(sc)),gdk_window_get_height(gdk_screen_get_active_window(sc)));
	///*
	g = windows;
	while(g != NULL){
		//GdkWindow *w = (GdkWindow *)g->data;

		//gdk_window_iconify(gdk_screen_get_active_window(sc));

		printf("%d x %d \n",gdk_window_get_width(g->data),gdk_window_get_height(g->data));
		g = g->next;

		wi = gdk_screen_get_active_window(sc);
		//windows = gdk_screen_get_toplevel_windows(sc);
		gdk_window_iconify(gdk_screen_get_active_window(sc));

	}
	//*/

}

int main(int argc,char *argv[]){
	
	
	gtk_init(&argc,&argv);
	gdk_init(&argc,&argv);
	
	//GList *windows;
	//windows = gdk_screen_get_window_stack(sc);
	//windows = gdk_screen_get_toplevel_windows(sc);
	//GList *g ;

	GdkWindow *wi;

	//wi = minimizar();

	int i;

	system("pause");


	allWindows();


	system("pause");


	allWindows();


	system("pause");


	allWindows();
	//wi = maximizar();
	

	
	

	/*
		for(i = 0;i<100000;i++){printf("-");}

		sc = gdk_screen_get_default();

		wi = gdk_screen_get_active_window(sc);
		gdk_window_deiconify(wi);
	*/

	/*
		g = windows;
		while(g != NULL){
			//GdkWindow *w = (GdkWindow *)g->data;

			gdk_window_deiconify(g->data);


			printf("%d x %d \n",gdk_window_get_width(g->data),gdk_window_get_height(g->data));
			g = g->next;
		}
	*/

	return 0;
}
