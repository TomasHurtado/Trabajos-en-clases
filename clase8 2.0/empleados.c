#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn.h"




int empleado_iniciar(Empleado* empleador,int leng)
{
    int i;
    int ret=-1;
    if(empleador != NULL && leng >=0)
     {
        for(i=0;i<leng;i++)
        {
            empleador[i].isEmpty=1;
            ret=0;
        }
    }

    return ret;
}

int empleado_mostrar(Empleado* empleador,int leng)

{
    int j;
    for(j=0;j<leng; j++)
          {
            if(empleador[j].isEmpty==0)
            {
                printf("%s \n",empleador[j].nombre);

            }

          }
        return 0;
}



int empleado_lugarLibre(Empleado *empleador,int leng,int* lugar)
{
    int i;
    int ret=-1;
    for(i=0; i<leng ; i++)
    {
        if(empleador[i].isEmpty==1)
        {
            *lugar = i;
            ret=0;
            break;
        }
    }
    return ret;

}
int empleado_daralta(Empleado *empleador,int leng)
{

    int lugar;
    if(empleado_lugarLibre(empleador,leng,&lugar)==0)
    {
        printf("Se encontro lugar en %d\n",lugar);
        printf("ingrese nombre");
        scanf("%s",empleador[lugar].nombre);
        printf("ingrese apellido");
        scanf("%s",empleador[lugar].apellido);

    }

    return 0;
}


//baja
//modificar
//ordenar
