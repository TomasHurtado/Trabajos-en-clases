#ifndef Controller_H_INCLUDED
#define Controller_H_INCLUDED
#include "LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayListFotos);
int controller_loadFromBinary(char* path , LinkedList* pArrayListFotos);
//int controller_addFotos(LinkedList* pArrayListFotos);
//int controller_editFotos(LinkedList* pArrayListFotos);
int controller_removeFotos(LinkedList* pArrayListFotos);
int controller_ListFotos(LinkedList* pArrayListFotos);
int controller_sortFotos(LinkedList* pArrayListFotos);
int controller_saveAsText(char* path , LinkedList* pArrayListFotos);
int controller_saveAsBinary(char* path , LinkedList* pArrayListFotos);
int controller_searchIdFotos(LinkedList* pArrayListFotos, int id);
int controller_ListFotosMagia(LinkedList* this, LinkedList* that);
int controller_cantidadDeBultos(LinkedList* this,FILE* pFile);
int controller_cantidadDeFotosPorTipo(LinkedList* this, FILE* pFile);
int controller_pesosTotales(LinkedList* this);
int controller_cantidadMaximaDeBultos(LinkedList* this,FILE* pFile);
int controller_cantidadMax150(LinkedList* this,FILE* pFile);
int controller_cantidadMax300(LinkedList* this,FILE* pFile);
int controller_cantidaddFotos(LinkedList* this,FILE* pFile);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_comparar(void *this,void *that);
int controller_cantidadDeEntregasPorTipo(LinkedList* this,FILE* pFile);
int comparar(LinkedList* this);



#endif
