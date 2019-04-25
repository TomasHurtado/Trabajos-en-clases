#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string.h"
#include "pantallas.h"
#include "publicidad.h"
#define CANTIPANTALLAS 100
#define CANTICONTRATACION 1000

int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int valor;
    int posLibre;
    Pantalla pantallas[CANTIPANTALLAS];
    Publicidad publicidades[CANTICONTRATACION];

    valor=pant_Inicializar(pantallas, CANTIPANTALLAS);

    if (valor==0)
    {
        printf("Pantalla inicializados correctamente\n\n\n");
    }
    while (seguir=='s')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta Pantalla");
        printf("\n\n2-Mostrar Pantalla");
        printf("\n\n3-Borrar pantalla");
        printf("\n\n4-Salir\n");

        do
        {
            printf("\n\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>4);

        switch (opcion)
        {
        case 1:

            if(pant_buscarLibre(pantallas, CANTIPANTALLAS, &posLibre)!=0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pant_Alta(pantallas, CANTIPANTALLAS, posLibre))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");

                    break;
                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;

        case 2:

            pant_mostrarArray(pantallas,CANTIPANTALLAS);
            break;

        case 3:
            if (pant_baja(pantallas, CANTIPANTALLAS)==0)
            {
                printf("exito");
            }
            break;

        case 4:
        {
        if(pub_buscarLibre(publicidades, CANTICONTRATACION, &posLibre)!=0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pub_Alta(publicidades, CANTICONTRATACION, posLibre))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");

                    break;
                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;
        }
        case 5:
        {
            pub_mostrarArray(publicidades,CANTICONTRATACION);
            break;
        }

        case 6:
        {
            if (pub_baja(publicidades, CANTICONTRATACION)==0)
            {
                printf("exito");
            }
            break;

        }
        case 7:
            seguir='f';
            break;
        }
    }
    return 0;
}
