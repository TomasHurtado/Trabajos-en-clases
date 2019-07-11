#include <stdio.h>
#include <stdlib.h>
#include "Llamada.h"
#include "utn.h"
#include "string.h"

static int idPer=0;

int llamada_generarId(void)
{
    return idPer++;
}
 void llamada_setIdInicial(int val)
{
    idPer= val;
}
void llamada_imprimirMasterId(void)
{
    printf("\n%d",idPer);
}

LLamada* llamada_new(void)
{
    return (LLamada*) malloc(sizeof(LLamada));
}

LLamada* llamada_newParametros(char* idStr,char* fechaStr,char* idClienteStr, char* idProblema, char* solucion)
{
    LLamada* pLLamada=llamada_new();
    if (pLLamada!=NULL)
    {
        llamada_setIdStr(pLLamada,idStr);
        llamada_setFecha(pLLamada,fechaStr);
        //llamada_setApellido(pLLamada,apellidoStr);
        llamada_setSolucionstr(pLLamada,solucion);
        //llamada_setIntDosStr(pLLamada,intDosStr);
        llamada_idCliente(pLLamada,idClienteStr);
        llamada_iidProblemastr(pLLamada,idProblema);
        //llamada_setSumadedos(pLLamada,uno,el otro);
    }
    return pLLamada;
}

void llamada_delete(LLamada* this)
{
    free(this);
}

int llamada_setId(LLamada* this,int id)
{
    int retorno=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int llamada_getId(LLamada* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int llamada_setIdStr(LLamada* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if (this!=NULL && isValidNumber(id))
    {
        bufferInt= atoi(id);
        if (bufferInt>0)
        {
            llamada_setId(this,bufferInt);
        }
    }
    return retorno;
}

int llamada_setFecha(LLamada* this,char* fecha)
{
    int retorno = -1;

        strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno = 0;

    return retorno;
}

int llamada_getFecha(LLamada* this,char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(fecha,this->fecha,sizeof(this->fecha));
        retorno = 0;
    }
    return retorno;
}

int llamada_setSolucionstr(LLamada* this,char* solucion)
{
    int retorno = -1;
    strncpy(this->solucion,solucion,sizeof(this->solucion));

    retorno = 0;

    return retorno;
}

int llamada_getSolucionstr(LLamada* this,char* solucion)
{
    int retorno=-1;

    strncpy(solucion,this->solucion,sizeof(this->solucion));
    retorno = 0;
    return retorno;
}



int llamada_setidCliente(LLamada* this,int idCliente)
{
    int retorno=-1;
    if (this!=NULL && idCliente>0)
    {
        this->idCliente=idCliente;
        retorno=0;
    }
    return retorno;
}

int llamada_getidCliente(LLamada* this,int* idCliente)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *idCliente = this->idCliente;
        retorno=0;
    }
    return retorno;
}

int llamada_idCliente(LLamada* this,char* idClienteStr)
{
    int retorno=-1;
    int bufferInt;
      if (this!=NULL && isValidNumber(idClienteStr))
    {
        bufferInt= atoi(idClienteStr);
        if (bufferInt>0)
        {
            llamada_setidCliente(this,bufferInt);
        }
    }
    return retorno;
}


int llamada_setidProblema(LLamada* this,int idProblema)
{
    int retorno=-1;


        this->idProblema=idProblema;
        retorno=0;

    return retorno;
}

int llamada_getidProblema(LLamada* this,int* idProblema)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *idProblema = this->idProblema;
        retorno=0;
    }
    return retorno;
}

int llamada_iidProblemastr(LLamada* this,char* idProblemastr)
{
    int retorno=-1;
    int bufferHora;
    if (this!=NULL)
    {
        bufferHora= atoi(idProblemastr);
        if (bufferHora>0)
        {
            llamada_setidProblema(this,bufferHora);
        }
    }
    return retorno;
}




int llamada_printNode(LLamada *this)
{
    int retorno=-1;
    char bufferFecha[TEXT_SIZE];
    char bufferCantidad[TEXT_SIZE];
    int bufferId;
    int bufferidCliente;
    if (this!=NULL)
    {
        llamada_getId(this,&bufferId);
        printf("\n ID: %d",bufferId);
        llamada_getFecha(this,bufferFecha);
        printf("\f Fecha: %s",bufferFecha);
        llamada_getSolucionstr(this,bufferCantidad);
        printf("\f solucion: %s",bufferCantidad);
        llamada_getidCliente(this,&bufferidCliente);
        printf("\f idCliente: %d",bufferidCliente);
        retorno=0;
    }
    return retorno;
}

int llamada_comparaFecha(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((LLamada*)this)->fecha,((LLamada*)that)->fecha);
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




int llamada_comparar(void *this)
{
    int retorno;
    int num=0;
    num=printf("Ingrese numero a filtrar");
//    if (this->idProblema==num)
    {
        retorno=1;
    }
//    else
    {
        retorno=0;
    }

    return retorno;
}

