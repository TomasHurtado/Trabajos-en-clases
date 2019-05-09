#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "autor.h"  //cambiar por nombre entidad
#include "libros.h"
#include "socio.h"
#include "prestamo.h"

#define QTY_TIPO 5

int main()
{
    int opcion;
    int contadorIdautor=0;                   //cambiar

    Autor arrayAutor[QTY_TIPO];
    Libros arrayLibros[QTY_TIPO];
                     //cambiar
    autor_Inicializar(arrayAutor,QTY_TIPO);
    libros_Inicializar(arrayLibros,QTY_TIPO);                //cambiar

    do
    {
        utn_getUnsignedInt("\nAutores\n1) Alta \n2) Modificar \n3) Baja \n4) Listar \n5) Ordenar\nLibros\n6) Alta \n7) Modificar \n8) Baja \n9) Listar \n10) Ordenar \n11) Salir\n",                   //cambiar
                      "\nError",1,sizeof(int),1,11,1,&opcion);
        switch(opcion)
        {
            case 1: //Alta
                autor_alta(arrayAutor,QTY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 2: //Modificar
                autor_modificar(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 3: //Baja
                autor_baja(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 4://Listar
                autor_listar(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 5://Ordenar
                autor_ordenarPorString(arrayAutor,QTY_TIPO);                   //cambiar
                break;

            case 6: //Alta
                libros_alta(arrayLibros,QTY_TIPO,&contadorIdautor);                   //cambiar
                break;

            case 7: //Modificar
                libros_modificar(arrayLibros,QTY_TIPO);                   //cambiar
                break;

            case 8: //Baja
                libros_baja(arrayLibros,QTY_TIPO);                   //cambiar
                break;

            case 9://Listar
                libros_listar(arrayLibros,QTY_TIPO);                   //cambiar
                break;

            case 10://Ordenar
                libros_ordenarPorString(arrayLibros,QTY_TIPO);                   //cambiar
                break;

            case 11://Salir
                break;
            default:
                printf("\nOpcion no valida");
        }
    }
    while(opcion!=11);
    return 0;
}
