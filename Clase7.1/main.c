#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define LEN_LISTA    100
int main()
{

    int opcion;
    char buffer[20];
    char nombres[LEN_LISTA][20];
    int i;
    int lugar;
    int posaborrar;
    // Inicializacion
    for(i=0; i<LEN_LISTA; i++)
    {
        nombres[i][0] = '\0';
    }


    //
    while(1)
    {

        utn_getNumber(&opcion,"1)ingresar\n2)listar\n","NO!",1,10,2);

        printf("elegiste:%d\n",opcion);
        switch(opcion)
        {
            case 1:
            {
                if(buscarlibre(&lugar,nombres)==0)
                {
                    printf("se encontro lugar en %d\n",lugar);
                    //utn_getString(buffer,"ingrese nombre:","error",1,20,3);
                    fgets(buffer,20,stdin);




                    strncpy(nombres[lugar],buffer,20);
                    printf("el nombre es: %s\n",buffer);

                }



                break;
            }

            case 2:
            {

                    int j=0;
                   for(j=0;j<10;j++)
                    {
                        printf("-%d: %s\n",j,nombres[j]);
                    }

            break;
            }

            case 4:
            {   utn_getString(buffer,"ingrese nombre","error",1,56,1);
                //en buufer esta el nommbre

                buscarNombre(buffer,nombres,LEN_LISTA,&posaborrar);

                char nada='\0'
                nombres[posaborrar][]=nombres[][nada];



                break;
            }
        }

    }






    return 0;
}
