#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}



int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


int pedirnumero(int linea[], int leng)
{
    int x;
    for(x=0;x<leng;x++)
    {
        printf("Ingrese elemento:");
        scanf("%d",&linea[x]);
    }
    return 0;
}

int mayor(int mayor[],int leng)
{
    int may=mayor[0];

    int x;
    for(x=1;x<leng;x++)
    {
        if (mayor[x]>may)
        {
            may=mayor[x];

        }
    }
    printf("Mayor numero:%d\n",may);


    return 0;
}


int menor(int menor[],int leng)
{
    int men=menor[0];

    int x;
    for(x=1;x<leng;x++)
    {
        if (menor[x]<men)
        {
            men=menor[x];

        }
    }
    printf("Mayor numero:%d\n",men);


    return 0;
}


int promedio(int promedio[],int leng)
{
    int acu=0;
    int x;
    for(x=0;x<leng;x++)
    {



            acu=acu+promedio[x];


    }
    printf("el promedio es:%d\n",acu);


    return 0;
}


int ordenamiento(int ordenar[],int leng)
{
    int k,f;
    for (k = 0; k < leng; k++)
    {
        for (f = 0; f < leng - k; f++)
        {
            if (ordenar[f] < ordenar[f + 1])
            {
                int aux;
                aux = ordenar[f];
                ordenar[f] = ordenar[f + 1];
                ordenar[f + 1] = aux;
            }
        }
    }

    int x;
    for(x=0;x<leng;x++)
    {
        printf("los numeros ordenasdo son %d\n",ordenar[x]);
    }
    return 0;
}

int buscarnumeros(int buscar[],int leng,int numabuscar)
{
    int ret=-1;
    int x;
    for(x=0;x<leng;x++)
    {
        if(numabuscar==buscar[x])
        {
          printf("el numero si esta en el vector %d",buscar[x]);
          ret=0;
          break;
        }

    }
    printf("el numero no existe");
    return ret;

}

