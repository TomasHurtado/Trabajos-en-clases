#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Venta.h"

int main()
{
    LinkedList* listaFotos = ll_newLinkedList();
    FILE* pFile=fopen("Informe.csv","w+");
    fprintf(pFile,"********************\n");
    fprintf(pFile,"Informe de ventas\n");
    fprintf(pFile,"********************");
    controller_loadFromText("data.csv",listaFotos);
    controller_ListEmployee(listaFotos);
    //fprintf(pFile,"\nCantidad de fotos reveladas: %d",ll_len(listaFotos));//1
    controller_cantidadMax150(listaFotos,pFile);
    controller_cantidadMax300(listaFotos,pFile);
    controller_cantidaddFotos(listaFotos,pFile);
   controller_cantidadDeEntregasPorTipo(listaFotos,pFile);
//    ll_contar(listaFotos,(*comparar)(element*));
//int ll_contar(LinkedList* this, int (*pFunc)(void*))


    fprintf(pFile,"\n********************");
    fclose(pFile);

    ll_deleteLinkedList(listaFotos);
    return 0;
}
