#include <stdio.h>
#include <stdlib.h>
#include "Venta.h"
#include "utn.h"
#include "string.h"

static int idPer=0;

int ventas_generarId(void)
{
    return idPer++;
}
 void ventas_setIdInicial(int val)
{
    idPer= val;
}
void ventas_imprimirMasterId(void)
{
    printf("\n%d",idPer);
}

Fotos* ventas_new(void)
{
    return (Fotos*) malloc(sizeof(Fotos));
}

Fotos* ventas_newParametros(char* idStr,char* fechaStr,char* tipo , char* cantidadStr,char* precioStr,char* cuit)
{
    Fotos* pFotos=ventas_new();
    if (pFotos!=NULL)
    {
        ventas_setIdStr(pFotos,idStr);
        ventas_setFecha(pFotos,fechaStr);
        ventas_setTipo(pFotos,tipo);
        ventas_setCantidadStr(pFotos,cantidadStr);
        ventas_setCuit(pFotos,cuit);
        ventas_setPrecioStr(pFotos,precioStr);

    }
    return pFotos;
}

void ventas_delete(Fotos* this)
{
    free(this);
}

int ventas_setId(Fotos* this,int id)
{
    int retorno=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        retorno=0;
    }
    return retorno;
}

int ventas_getId(Fotos* this,int* id)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *id = this->id;
        retorno=0;
    }
    return retorno;
}

int ventas_setIdStr(Fotos* this,char* id)
{
    int retorno=-1;
    int bufferInt;
    if (this!=NULL && isValidNumber(id))
    {
        bufferInt= atoi(id);
        if (bufferInt>0)
        {
            ventas_setId(this,bufferInt);
        }
    }
    return retorno;
}

int ventas_setTipo(Fotos* this,char* tipo)
{
    int retorno = -1;
    if(this!=NULL )
    {
        strncpy(this->tipo,tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int ventas_getTipo(Fotos* this,char* tipo)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(tipo,this->tipo,sizeof(this->tipo));
        retorno = 0;
    }
    return retorno;
}

int ventas_setCantidad(Fotos* this,int cantidad)
{
    int retorno=-1;
    if (this!=NULL )
    {
        this->cantidad=cantidad;
        retorno=0;
    }
    return retorno;
}

int ventas_getCantidad(Fotos* this,int* cantidad)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *cantidad = this->cantidad;
        retorno=0;
    }
    return retorno;
}

int ventas_setCantidadStr(Fotos* this,char* cantidadStr)
{
    int retorno=-1;
    int bufferHora;
    if (this!=NULL && isValidNumber(cantidadStr))
    {
        bufferHora= atoi(cantidadStr);
        if (bufferHora>0)
        {
            ventas_setCantidad(this,bufferHora);
        }
    }
    return retorno;
}

int ventas_setPrecio(Fotos* this,float precio)
{
    int retorno=-1;
    if (this!=NULL && precio>0)
    {
        this->precio=precio;
        retorno=0;
    }
    return retorno;
}

int ventas_getPrecio(Fotos* this,float* precio)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *precio = this->precio;
        retorno=0;
    }
    return retorno;
}

int ventas_setPrecioStr(Fotos* this,char* precioStr)
{
    int retorno=-1;
    float bufferHora;
    if (this!=NULL && isValidFloatNumber(precioStr))
    {
        bufferHora= atof(precioStr);
        if (bufferHora>0)
        {
            ventas_setPrecio(this,bufferHora);
        }
    }
    return retorno;
}

int ventas_getFecha(Fotos* this,char* fecha)
{
    int retorno=-1;
    if (this!=NULL)
    {
       strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno=0;
    }
    return retorno;
}

int ventas_setFecha(Fotos* this,char* fecha)
{
    int retorno=-1;
    if (this!=NULL)
    {
      strncpy(this->fecha,fecha,sizeof(this->fecha));
        retorno=0;
    }
    return retorno;
}

int ventas_setCuit(Fotos* this,char* cuit)
{
    int retorno=-1;
    if (this!=NULL && isValidCUIT(cuit))
    {
        strncpy(this->cuit,cuit,sizeof(this->cuit));
        retorno=0;
    }
    return retorno;
}

int ventas_getCuit(Fotos* this,char* cuit)
{
    int retorno=-1;
    if (this!=NULL && isValidCUIT(cuit))
    {
       strncpy(cuit,this->cuit,sizeof(this->cuit));
        retorno=0;
    }
    return retorno;
}




int ventas_printNode(Fotos *this)
{
    int retorno=-1;
    char bufferTipo[TEXT_SIZE];
    int bufferCantidad;
    int bufferId;
    float bufferPeso;
    if (this!=NULL)
    {
        ventas_getId(this,&bufferId);
        printf("\n ID: %d",bufferId);
        ventas_getTipo(this,bufferTipo);
        printf("\f Tipo: %s",bufferTipo);
        ventas_getCantidad(this,&bufferCantidad);
        printf("\f cantidad: %d",bufferCantidad);
        ventas_getPrecio(this,&bufferPeso);
        printf("\f Peso: %.2f",bufferPeso);
        retorno=0;
    }
    return retorno;
}

int ventas_comparaTipo(void *this,void *that)
{
    int retorno;
    int comparacion = strcmp(((Fotos*)this)->fecha,((Fotos*)that)->fecha);
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
 int ventas_setPesoStr(Fotos* this,char* precioStr, char* elotro)
{
    int retorno=-1;
    float bufferHora;
    int bufferOtro;
    if (this!=NULL && isValidFloatNumber(precioStr) && isValidNumber(elotro))
    {
        bufferHora= atof(precioStr);
        bufferOtro= atoi(elotro);
        if (bufferHora>0 bufferOtro>0)
        {
            bufferHora= (float)bufferHora*bufferOtro;
            ventas_setPeso(this,bufferHora);
        }
    }
    return retorno;

int ventas_setPeso(Fotos* this,float precio)
{
    int retorno=-1;
    if (this!=NULL && precio>0)
    {
        this->montoTotal=precio;
        retorno=0;
    }
    return retorno;
}

int ventas_getPeso(Fotos* this,float* precio)
{
    int retorno=-1;
    if (this!=NULL)
    {
        *precio = this->precio;
        retorno=0;
    }
    return retorno;
}

*/

