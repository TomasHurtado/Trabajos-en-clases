#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "utn.h"
#include "Llamada.h"


int main()
{
    LinkedList* llamada = ll_newLinkedList();
    FILE* pFile=fopen("data.csv","w+");
    fprintf(pFile,"********************\n");
    fprintf(pFile,"Informe \n");
    fprintf(pFile,"********************");
    controller_loadFromText("DATA_final1.csv",llamada);
    ll_filter(llamada,(*llamada_comparar));

    controller_ListEmployee(llamada);
    fprintf(pFile,"\n********************");
    fclose(pFile);

    ll_deleteLinkedList(llamada);
    return 0;




}
