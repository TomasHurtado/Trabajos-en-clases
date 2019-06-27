#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "entregas.h"
#include "utn.h"

int main()
{

    LinkedList* listaEntregas = ll_newLinkedList();
    int cantBultos=0;
    int lenLista;
    float pesosTotales;
    FILE* pFile=fopen("resultados.csv","w+");
    fprintf(pFile,"********************\n");
    fprintf(pFile,"Informe de ventas\n");
    fprintf(pFile,"********************");
    controller_loadFromText("data.csv",listaEntregas);
    lenLista=ll_len(listaEntregas);
    fprintf(pFile,"\nCantidad de Total de entregas: %d",ll_len(listaEntregas));//1
    controller_cantidadDeEntregasPorTipo(listaEntregas,pFile);
    cantBultos=controller_cantidadDeBultos(listaEntregas,pFile);
    controller_cantidadMaximaDeBultos(listaEntregas,pFile);
    fprintf(pFile,"\nPromedio de Bultos por entrega: %.2f\n",(float)cantBultos/lenLista);
    pesosTotales=controller_pesosTotales(listaEntregas);
    fprintf(pFile,"Promedio peso por Entregas: %2.f\n",(float)pesosTotales/lenLista);
    fprintf(pFile,"********************");

    fclose(pFile);

    ll_deleteLinkedList(listaEntregas);
    return 0;
}
