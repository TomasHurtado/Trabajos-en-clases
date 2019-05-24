#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#define QTY_ALUMNO 1000

int main()
{
    Alumno* arrayAlumnos[QTY_ALUMNO];
    Alumno* pAux;
    pAux = alumno_new();
    if(pAux != NULL)
    {
        alumno_setId(pAux,44);
        arrayAlumnos[0] = pAux;
    }


    pAux = alumno_new();
    if(pAux != NULL)
    {
        alumno_setId(pAux,14);
        arrayAlumnos[1] = pAux;
    }

    pAux = alumno_newParametros(11,11100,0,"Juan");
    if(pAux != NULL)
    {
        arrayAlumnos[2] = pAux;
    }
    return 0;
}


/*  int* pAuxHeap;
    int* pAuxint;

    // guardo memorira con malloc
    pAuxHeap=(int*) malloc(sizeof(int)*100);
    if(pAuxHeap!= NULL)
    {
    *(pAuxHeap+10)=22;
    }
    //realloc aumenta o achica la memoria si encuentra

    pAuxint=(int*) realloc(pAuxHeap,sizeof(int)*110);
    if(pAuxint!= NULL)
    {
        pAuxHeap=pAuxint;
    }

    // libera memoria
    free(pAuxHeap);*/
