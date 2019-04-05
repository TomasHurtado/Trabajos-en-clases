#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define largo 10


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
