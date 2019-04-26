#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string.h"
#include "pantallas.h"
#include "publicidad.h"


int pub_Inicializar(Publicidad* publicidades, int cantidad)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        publicidades[i].isEmpty=1;
        ret=0;
    }

    return ret;
}

int pub_Alta(Publicidad* publicidades, int cantidad, int posLibre)
{
    int ret;
    if (getString(publicidades[posLibre].cuit_cliente,"Ingrese cuit:","error, vuelva a intentar\n\n",2,50,2)==0)
    {
        if (getNumber(&publicidades[posLibre].cantidad_dias,"Ingrese dias:","error, vuelva a intentar\n\n",2,50,2)==0)
        {
            publicidades[posLibre].isEmpty=0;
            ret=0;

            if (getString(publicidades[posLibre].archivo,"Ingrese nombre archivo:","error, vuelva a intentar\n\n",2,50,2)==0)
            {
                publicidades[posLibre].isEmpty=0;
                ret=0;
            }
        }
        else
        {
            ret=1;
        }

    }

    return ret;
}

int pub_buscarLibre(Publicidad* publicidades, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        if (publicidades[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }

        ret=1;
    }

    return ret;
}

void pub_mostrarArray(Publicidad* publicidades, int cantidad)
{

    for (int i=0; i<cantidad;i++)
    {
        if(publicidades[i].isEmpty==0)
        {
            printf("posicion %d :estado %d\n", i, publicidades[i].isEmpty);
            printf("posicion %d :nombre %s\n", i, publicidades[i].cuit_cliente);
            printf("posicion %d :direccion %d\n", i, publicidades[i].cantidad_dias);
            printf("posicion %d :tipo %s\n", i, publicidades[i].archivo);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}


int pub_baja(Publicidad* publicidades, int cantidad)
{

    int posPublicidad;
    switch (pub_buscarEnArray(publicidades, cantidad,&posPublicidad))
    {
    case 0:
        if (publicidades[posPublicidad].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            publicidades[posPublicidad].isEmpty=1;
            printf("El empleado borrado es: %s\n\n",publicidades[posPublicidad].cuit_cliente);

        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

int pub_buscarEnArray (Publicidad* publicidades, int cantidad, int* publicidadEncontrado)
{
    int ret=1;
    Publicidad auxPublicidad;

    if (getString(auxPublicidad.cuit_cliente,"ingrese el cuit que quiera eliminar: ","Vuelva a ingresar",2,20,3)==0)
    {

        ret=-1;
        for(int i=0;i<cantidad;i++)
        {

            if (strcmp(publicidades[i].cuit_cliente, auxPublicidad.cuit_cliente)==0)
            {
                ret=0;
                *publicidadEncontrado=i;
                break;
            }
        }
    }
    return ret;
}
