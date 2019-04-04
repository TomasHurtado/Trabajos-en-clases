#include <stdio.h>
#include <stdlib.h>


void prueba(void)
{
    printf("ola k aze desde casa\n");
}



int utn_getnumber(int* puntero,int max, int min,char msg[],char msgError[],int intentos)
{

 int numero;
 int retorno;

 while(intentos>0)
 {
 printf(msg);
 scanf("%d",&numero);


 if(numero>max || numero<min)
 {
    printf("%s",msgError);
    retorno=1;

 }

 else
 {
  printf("bien");
      retorno=0;
    break;
 }
 intentos--;

 }
*puntero=numero;
 return retorno;
}
