#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define largo 10

int getNumber(int *resultado, char *msg, char *msgerror, int minimo, int maximo,int reintentos);
int getString(char *pResultado, char msg, char *msgerror,int minimo, int maximo,int reintentos);
int isvalidNumber(char *cadena);

int getString(char *pResultado, char msg, char *msgerror,int minimo, int maximo,int reintentos)

{
    char bufferStr[4096];

    fgets(bufferStr,sizeof(bufferStr),stdin);
    bufferStr[strlen(bufferStr)-1]= '\0';

    return 0;
}



int isvalidNumber(char *cadena)

{
    return 1;
}


int getNumber(int *resultado, char *msg, char *msgerror, int minimo, int maximo,int reintentos)

{
    int retorno=-1;
    char bufferStr[4096];
    int bufferInt;
    if(resultado != NULL && reintentos >=0)
    {
        if(!getString(bufferStr,msg,msgerror,1,7,1) && isvalidNumber(bufferStr))
        {
          // atoi(bufferStr=bufferInt);
           bufferInt=atoi(bufferStr);
           if(bufferInt>= minimo && bufferInt <= maximo)
           {
                retorno=0;
                *resultado=bufferInt;

           }
        }
    }


    return retorno;
}



/**
int main()
{
int numero[largo];
int num;

pedirnumero(numero, largo);

mayor(numero,largo);

menor(numero, largo);

promedio(numero,largo);

ordenamiento(numero,largo);

printf("ingrese numero a buscar");
scanf("%d",&num);
buscarnumeros(numero,largo,num);
return 0;

}
*/
