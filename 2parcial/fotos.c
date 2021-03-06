#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "utn.h"
#include "string.h"

static int idPer=0;

int entregas_generarId(void)
{
    return idPer++;
}
 void entregas_setIdInicial(int val)
{
    idPer= val;
}
void entregas_imprimirMasterId(void)
{
    printf("\n%d",idPer);
}

Fotos* entregas_new(void)
{
    return (Fotos*) malloc(sizeof(Fotos));
}

Fotos* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr , char* pesoStr)
{
    Fotos* pFotos=entregas_new();
    if (pFotos!=NULL)
    {
        entregas_setIdStr(pFotos,idStr);
        entregas_setTipo(pFotos,tipoStr);
        //entregas_setApellido(pFotos,apellidoStr);
        entregas_setCantidadStr(pFotos,cantidadStr);
        //entregas_setIntDosStr(pFotos,intDosStr);
        entregas_setPesoStr(pFotos,pesoStr);
        //entregas_setSumadedos(pFotos,uno,el otro);
    }
    return pFotos;
}

void entregas_delete(Fotos* this)
{
    free(this);
}

int entregas_setId(Fotos* this,int id)
{
    int retorno=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int entregas_getId(Fotos* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int entregas_setIdStr(Fotos* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if (this!=NULL && isValidNumber(id))
    {
        bufferInt= atoi(id);
        if (bufferInt>0)
        {
            entregas_setId(this,bufferInt);
        }
    }
    return retorno;
}

int entregas_setTipo(Fotos* this,char* tipo)
{
    int retorno = -1;
    if(this!=NULL && isValidName(tipo))
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int entregas_getTipo(Fotos* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int entregas_setCantidad(Fotos* this,int cantidad)
{
    int retorno=-1;
    if (this!=NULL && cantidad>0)
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_getCantidad(Fotos* this,int* cantidad)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *cantidad = this->cantidad;
        retorno=0;
    }
    return retorno;
}

int entregas_setCantidadStr(Fotos* this,char* cantidadStr)
{
    int retorno=-1;
    int bufferHora;
    if (this!=NULL && isValidNumber(cantidadStr))
    {
        bufferHora= atoi(cantidadStr);
        if (bufferHora>0)
        {
            entregas_setCantidad(this,bufferHora);
        }
    }
    return retorno;
}

int entregas_setPeso(Fotos* this,float peso)
{
    int retorno=-1;
    if (this!=NULL && peso>0)
    {
        this->peso=peso;
        retorno=0;
    }
    return retorno;
}

int entregas_getPeso(Fotos* this,float* peso)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *peso = this->peso;
        retorno=0;
    }
    return retorno;
}

int entregas_setPesoStr(Fotos* this,char* pesoStr)
{
    int retorno=-1;
    float bufferHora;
    if (this!=NULL && isValidFloatNumber(pesoStr))
    {
        bufferHora= atof(pesoStr);
        if (bufferHora>0)
        {
            entregas_setPeso(this,bufferHora);
        }
    }
    return retorno;
}

int entregas_printNode(Fotos *this)
{
    int retorno=-1;
    char bufferTipo[TEXT_SIZE];
    int bufferCantidad;
    int bufferId;
    float bufferPeso;
    if (this!=NULL)
    {
        entregas_getId(this,&bufferId);
        printf("\n ID: %d",bufferId);
        entregas_getTipo(this,bufferTipo);
        printf("\f Tipo: %s",bufferTipo);
        entregas_getCantidad(this,&bufferCantidad);
        printf("\f cantidad: %d",bufferCantidad);
        entregas_getPeso(this,&bufferPeso);
        printf("\f Peso: %.2f",bufferPeso);
        retorno=0;
    }
    return retorno;
}

int entregas_comparaTipo(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((Fotos*)this)->tipo,((Fotos*)that)->tipo);
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




/*
 int entregas_setPesoStr(Fotos* this,char* pesoStr, char* elotro)
{
    int retorno=-1;
    float bufferHora;
    int bufferOtro;
    if (this!=NULL && isValidFloatNumber(pesoStr) && isValidNumber(elotro))
    {
        bufferHora= atof(pesoStr);
        bufferOtro= atoi(elotro);
        if (bufferHora>0 bufferOtro>0)
        {
            bufferHora= (float)bufferHora*bufferOtro;
            entregas_setPeso(this,bufferHora);
        }
    }
    return retorno;

int entregas_setPeso(Fotos* this,float peso)
{
    int retorno=-1;
    if (this!=NULL && peso>0)
    {
        this->montoTotal=peso;
        retorno=0;
    }
    return retorno;
}

int entregas_getPeso(Fotos* this,float* peso)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *peso = this->peso;
        retorno=0;
    }
    return retorno;
}

*/

