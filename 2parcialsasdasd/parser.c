#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Venta.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int parser_FotosFromText(FILE* pFile , LinkedList* pArrayListFotos)
{
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferFecha[4096];
    char bufferCantidad[4096];
    char bufferCuit[4096];
    char bufferPrecio[4096];
    int bufferInt;
    int maxId=-1;
    int retorno=-1;
    Fotos *pFotos;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferFecha,
                                                  bufferTipo,
                                                  bufferCantidad,bufferPrecio,bufferCuit);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferFecha,
                                                  bufferTipo,
                                                  bufferCantidad,bufferPrecio,bufferCuit);

           pFotos = ventas_newParametros(     bufferId,
                                                    bufferFecha,
                                                    bufferTipo,
                                                    bufferCantidad,bufferPrecio,bufferCuit);



            if(pFotos!=NULL &&
                ll_add(pArrayListFotos,pFotos)==0)
            {
                ventas_getId(pFotos,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
        }
        ventas_setIdInicial(maxId+1);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int parser_FotosFromBinary(FILE* pFile , LinkedList* pArrayListFotos)
{
    int retorno=-1;
    Fotos *pFotos;
    int bufferInt;
    int maxId=-1;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pFotos=ventas_new();
            if(pFotos!=NULL &&
                fread(pFotos,sizeof(Fotos),1,pFile)&&
                ll_add(pArrayListFotos,pFotos)==0)
            {
                ventas_getId(pFotos,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
            else
            {
                ventas_delete(pFotos);
            }
        }
        ventas_setIdInicial(maxId+1);
    }
    return retorno;
}
