#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
static int idgen=0;


Logistica* logistica_new()
{
    return (Logistica*) malloc(sizeof(Logistica));
}

int logistica_generarId(void)
{
    return idgen++;
}

void logistica_iniciarId(int val)
{
    idgen= val;
}

Logistica* logistica_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* peso)
{
    Logistica* log=logistica_new();
    if(log!=NULL)
    {
        logistica_setIdchar(log,idStr);
        logistica_setTipo(log,tipoStr);
        logistica_setCantidadstr(log,cantidadStr);
        logistica_setPesostr(log,peso);

    }


    return log;
}

void logistica_delete(Logistica* this)
{
    free(this);
}

int logistica_setId(Logistica* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int logistica_getId(Logistica* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int logistica_setTipo(Logistica* this,char* tipo)
{

    int retorno = -1;
    if(this != NULL && isLetter(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int logistica_getTipo(Logistica* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int logistica_setCantidad(Logistica* this,int cantidad)
{
    int retorno = -1;
    if(this != NULL && cantidad >= 0)
    {
        this->cantidad = cantidad;
        retorno = 0;
    }
    return retorno;
}

int logistica_getCantidad(Logistica* this,int* cantidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *cantidad = this->cantidad;
        retorno = 0;
    }
    return retorno;
}

int logistica_setPeso(Logistica* this,int peso)
{

    int retorno = -1;
    if(this != NULL && peso >= 0)
    {
        this->peso = peso;
        retorno = 0;
    }
    return retorno;
}

int logistica_getPeso(Logistica* this,float* peso)
{
    int retorno = -1;
    if(this != NULL)
    {
        *peso = this->peso;
        retorno = 0;
    }
    return retorno;
}


int logistica_setIdchar(Logistica* this,char* id)
{
    int val;
    int retorno = -1;
    if(this != NULL &&  isValidnumeric(id))

    {
        val=atoi(id);
        this->id = val;
        retorno = 0;
    }
    return retorno;
}

int logistica_setCantidadstr(Logistica* this,char* cantidad)
{
    int val;
    int retorno = -1;
    if(this != NULL && isValidnumeric(cantidad))
    {
        val=atoi(cantidad);
        this->cantidad = val;
        retorno = 0;
    }
    return retorno;
}

int logistica_setPesostr(Logistica* this,char* peso)
{
    float val;
    int retorno = -1;
    if(this != NULL && isValidFloatNumber(peso))
    {
        val=atof(peso);
        this->peso = val;
        retorno = 0;
    }
    return retorno;
}

int logistica_comparaNombre(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((Logistica*)this)->tipo,((Logistica*)that)->tipo);
    if (comparacion<0)
    {
        retorno=1;
    }
    else if (comparacion>0)
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int logistica_searchId(LinkedList* pArrayListLogistica, int id)
{
    int retorno=-1;
    int len;
    int i;
    int auxId;
    if (pArrayListLogistica!=NULL && id>=0 && ll_len(pArrayListLogistica)>=0)
    {
        len=ll_len(pArrayListLogistica);
        for (i=0;i<len;i++)
        {
            logistica_getId(ll_get(pArrayListLogistica,i),&auxId);
            if (id==auxId)
            {
                retorno=i;
                break;
            }
        }

    }
    else
    {
        printf("\nLa lista esta vacia");
    }
    return retorno;
}



