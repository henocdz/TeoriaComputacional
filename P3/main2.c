#include <stdio.h>
struct nodo{
       char a;
       struct nodo *sgte;
};

typedef struct nodo *pila;

void apila(pila **p, char a)
{ pila *q;
  q->a=a;
  q->sgte=p;
  p=q;
 }
 void desapila(pila &p)
  {int n=p->a;
       pila q=p;
       p=p->sgte;
       delete(q);
       }
int recorrer(int e,char letra, pila **p)
{ const char a='x';
     if(e==0&&letra=='a')
     {apila(p,a);
     return 0;}
     if(e==0&&letra=='b')
     {desapila(p);
     return 1;}
     if(e==1&&letra=='b')
     {desapila(p);
     return 1;}
     return 0;
 }
void leer(char pal[], pila &p)
{ int estado=0;
  int i=0;
  printf("e. inicial//letra\n");
  while(pal[i])
  { printf(estado+"      "+pal[i]);
    estado=recorrer(estado,pal[i],p);
    i++;
    }
  if(estado==1&&p==NULL)
  printf("palabra aceptada");
  else
  printf("palabra rechazada");
  }

int main()
{ pila p=NULL;
  printf("\n\n*****AUTOMATA CON PILA*******\n\n"); ////cambiar aqui la palabra
  
 char w[50]="aab";
 leer(w,p);
 
 
 getch();
 return 0;   
}