#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int memoria;
    int ret;
    //prueba();
   // printf("Hello world!\n");
   ret = utn_getnumber(&memoria,100,0,"ingrese_nuemero","error\n",3);
   printf("%d",memoria);

   if(ret==1)
   {
    printf("fracasaste en intentos");
   }
    return 0;
}
