#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED
#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayListLLamada);
int controller_loadFromBinary(char* path , LinkedList* pArrayListLLamada);
//int controller_addLLamada(LinkedList* pArrayListLLamada);
//int controller_editLLamada(LinkedList* pArrayListLLamada);
int controller_removeLLamada(LinkedList* pArrayListLLamada);
int controller_ListLLamada(LinkedList* pArrayListLLamada);
int controller_sortLLamada(LinkedList* pArrayListLLamada);
int controller_saveAsText(char* path , LinkedList* pArrayListLLamada);
int controller_saveAsBinary(char* path , LinkedList* pArrayListLLamada);
int controller_searchIdLLamada(LinkedList* pArrayListLLamada, int id);
int controller_ListLLamadaMagia(LinkedList* this, LinkedList* that);
int controller_solucionDeBultos(LinkedList* this,FILE* pFile);
int controller_solucionDeLLamadaPorFecha(LinkedList* this, FILE* pFile);
int controller_idClientesTotales(LinkedList* this);
int controller_solucionMaximaDeBultos(LinkedList* this,FILE* pFile);
int controller_solucionMax150(LinkedList* this,FILE* pFile);
int controller_solucionMax300(LinkedList* this,FILE* pFile);
int controller_soluciondLLamada(LinkedList* this,FILE* pFile);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_comparar(void *this,void *that);
int controller_solucionDeEntregasPorFecha(LinkedList* this,FILE* pFile);
int comparar(LinkedList* this);
int controller_ListEmployee(LinkedList* pArrayListEmployee);




#endif
