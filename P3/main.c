#include <stdio.h>
#include <stack.h>

stack <char> pila; 

int mover(int estado , char simbolo)
{
     if( estado == 1 && simbolo == '(' )
        {
          pila.push('X');
          return 1;
        } 
       
     if( estado == 1 && simbolo == 'a' )
          return 2;
        
     if( estado == 2 && simbolo == ')' )
        {
         pila.pop();
         return 2;
        } 
        
     if( estado == 2 && simbolo == '+' )
         return 1;

     if( estado == 2 && simbolo == '-' )
         return 1;

 return 0;
}
     
int scanner(char palabra[10] )
{
    int i = 0;
    int estado = 1; //estado inicial
    
    while(palabra[i])
         {
          estado = mover(estado,palabra[i]);
          i++;
         }
    
    if ( estado == 2 && pila.empty()) //estado final
         return 1;       
    
    return 0;     
}

int main()
{
    system("color f0");
    char palabra[10];

    printf("\n\n\t\tIngrese Cadena : ");
    gets(palabra);
    
    if( scanner(palabra))
       printf("\n\n\t\t\t Corecto !!! ");
  
    else
       printf(" \n\n\t\t\t Error !!!!");   
   
    system("pause");
}
