#include <stdio.h>
#include <stdlib.h>
#include "utn.h"



int main()
{
    int memoria;
    int ret;



   ret = utn_getnumber(&memoria,100,0,"ingrese_nuemero","error\n",3);
  int vec[ret];
  int x;

    for(x=0;x<ret;x++)
    {
        printf("Ingrese elemento:");
        scanf("%i",&vec[x]);
    }

    int z;
    printf("Contenido completo del vector:");
    for(z=0;z<ret;z++)
    {
        printf("%i ",vec[z]);
    }

    return 0;
}
