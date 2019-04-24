#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleados.h"
#include "utn.h"
#define LEN_LISTA    10



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
      if(empleador != NULL && leng >=0)
      {
        for(j=0;j<leng; j++)
              {

                    printf("%s \n",empleador[j].nombre);
                    printf("%s \n",empleador[j].apellido);



              }
        }
            return 0;
}



int empleado_lugarLibre(Empleado *empleador,int leng,int* lugar)
{
    int i;
    int ret=-1;
    if(empleador != NULL && leng >=0)
    {
        for(i=0; i<leng ; i++)
        {
            if(empleador[i].isEmpty==1)
            {
                *lugar = i;
                ret=i;
                break;
            }
        }
     }
        return ret;

}
int empleado_daralta(Empleado *empleador,int leng)
{
    int ret=-1;
    int lugar;
      if(empleador != NULL && leng >=0)
      {
        if(empleado_lugarLibre(empleador,leng,&lugar)==0)
        {
            printf("Se encontro lugar en %d\n",lugar);
            printf("ingrese nombre");
            scanf("%s",empleador[lugar].nombre);
            printf("ingrese apellido");
            scanf("%s",empleador[lugar].apellido);


        }
     }
        return ret;
    }

int buscarNombre(char* pNombre,int len,int* pIndex)
{
    int i;
    int ret=-1;
    for(i=0; i<len; i++)
    {
        if(pNombre[i]==0)
        {
            *pIndex = i;
            ret=0;
            break;
        }
    }
    return ret;


}


int empleado_baja(Empleado *empleador)
{

    char nombres[20];
    int posAeliminar;
    utn_getString(nombres,"Ingrese nombre a borrar:","No!",0,20,1);

                // en buffer esta el nombre
                if(buscarNombre(nombres,LEN_LISTA,&posAeliminar)==0)
                {
                    //borro
                    nombres[posAeliminar]='\0';
                    printf("Eliminado\n");
                }
                else{
                    printf("No existe el nombre\n");
                    }
                    return 0;
}
//modificar
//ordenar
