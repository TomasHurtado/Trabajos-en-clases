#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


int main()
{
    FILE* pFile;
    pFile = fopen("informes.txt","w+");
    int option = 0;
    int prom=0;
    LinkedList* listaLogistica = ll_newLinkedList();
    do{ printf("1carga 2creatxt 3 salir");
    utn_getUnsignedInt("","\nError",1,sizeof(int),1,60,1,&option);

        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaLogistica);
                break;
            case 2:
               //fprinf
                controller_ListLogistica(listaLogistica);
                fprintf(pFile,"hola q aze %d\n",15);

                break;

            case 3:
                break;
            default:
                printf("\nOpcion no valida");

        }
    }while(option != 3);
    prom=controller_promediopeso(listaLogistica);
    fprintf(pFile,"promedio %d",prom);
    return 0;
}
