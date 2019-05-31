#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define QTY_ARRAYPER 100
int main(void)
{
     FILE *pFile;
     int r;
     char var1[50],var3[50],var2[50],var4[50];

     pFile = fopen("data.csv","r");

     if(pFile == NULL)
     {
         printf("El archivo no existe");
         exit(EXIT_FAILURE);

     }
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

     do
     {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
         if(r==4)
         printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);




         else
         break;
     }while(!feof(pFile));

     fclose(pFile);

     exit(EXIT_SUCCESS);
}











/*
int main()
{
    Persona* arrayPersona[QTY_ARRAYPER];
    persona_initArray(arrayPersona,QTY_ARRAYPER);
    persona_addPersona(arrayPersona,QTY_ARRAYPER,"\nDATO NO VALIDO\n",3);


    return 0;
}
*/
