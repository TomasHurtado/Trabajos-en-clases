#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string.h"
#include "pantallas.h"

int pant_Inicializar(Pantalla* pantallas, int cantidad)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        pantallas[i].isEmpty=1;
        ret=0;
    }

    return ret;
}

int pant_Alta(Pantalla* pantallas, int cantidad, int posLibre)
{
    int ret;
    if (getString(pantallas[posLibre].nombre,"Ingrese nombre:","error, vuelva a intentar\n\n",2,50,2)==0)
    {
        if (getString(pantallas[posLibre].direccion,"Ingrese direccion:","error, vuelva a intentar\n\n",2,50,2)==0)
        {
            pantallas[posLibre].isEmpty=0;
            ret=0;

            if (getValidFloat(&pantallas[posLibre].precio,"Ingrese precio:","error, vuelva a intentar\n\n",2,999999,2)==0)
            {
                pantallas[posLibre].isEmpty=0;
                ret=0;

                if(getString(pantallas[posLibre].tipo,"Ingrese tipo LCD o LED:","error, vuelva a intentar\n\n",3,4,2)==0)
                {
                    pantallas[posLibre].isEmpty=0;
                    ret=0;
                }
            }
        }
        else
        {
            ret=1;
        }

    }

    return ret;
}

int pant_buscarLibre(Pantalla* pantallas, int cantidad, int* devuelve)
{
    int ret;
    for (int i=0; i<cantidad;i++)
    {
        if (pantallas[i].isEmpty==1)
        {
            *devuelve=i;
            ret=0;
            break;
        }

        ret=1;
    }

    return ret;
}

void pant_mostrarArray(Pantalla* pantallas, int cantidad)
{

    for (int i=0; i<cantidad;i++)
    {
        if(pantallas[i].isEmpty==0)
        {
            printf("posicion %d :estado %d\n", i, pantallas[i].isEmpty);
            printf("posicion %d :nombre %s\n", i, pantallas[i].nombre);
            printf("posicion %d :direccion %s\n", i, pantallas[i].direccion);
            printf("posicion %d :precio %2.f\n", i, pantallas[i].precio);
            printf("posicion %d :tipo %s\n", i, pantallas[i].tipo);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}


int pant_baja(Pantalla* pantallas, int cantidad)
{

    int posPantalla;
    switch (pant_buscarEnArray(pantallas, cantidad,&posPantalla))
    {
    case 0:
        if (pantallas[posPantalla].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            pantallas[posPantalla].isEmpty=1;
            printf("El empleado borrado es: %s\n\n",pantallas[posPantalla].nombre);

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

int pant_buscarEnArray (Pantalla* pantallas, int cantidad, int* pantallaEncontrado)
{
    int ret=1;
    Pantalla auxPantalla;

    if (getString(auxPantalla.nombre,"ingrese el nombre de la pantalla que quiera eliminar: ","Vuelva a ingresar",2,20,3)==0)
    {

        ret=-1;
        for(int i=0;i<cantidad;i++)
        {

            if (strcmp(pantallas[i].nombre, auxPantalla.nombre)==0)
            {
                ret=0;
                *pantallaEncontrado=i;
                break;
            }
        }
    }
    return ret;
}
