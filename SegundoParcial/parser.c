#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Llamada.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
int parser_LLamadaFromText(FILE* pFile , LinkedList* pArrayListLLamada)
{
    char bufferId[4096];
    char bufferFecha[4096];
    char bufferNumeroCliente[4096];
    char bufferProblema[4096];
    char bufferSolucion[4096];
    int bufferInt;
    int maxId=-1;
    int retorno=-1;
    LLamada *pLLamada;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferFecha,
                                                  bufferNumeroCliente,
                                                  bufferProblema,bufferSolucion);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,
                                                  bufferFecha,
                                                  bufferNumeroCliente,
                                                  bufferProblema,bufferSolucion);

           pLLamada = llamada_newParametros(      bufferId,
                                                  bufferFecha,
                                                  bufferNumeroCliente,
                                                  bufferProblema,bufferSolucion);



            if(pLLamada!=NULL &&
                ll_add(pArrayListLLamada,pLLamada)==0)
            {
               llamada_getId(pLLamada,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
        }
        llamada_setIdInicial(maxId+1);
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
int parser_LLamadaFromBinary(FILE* pFile , LinkedList* pArrayListLLamada)
{
    int retorno=-1;
    LLamada *pLLamada;
    int bufferInt;
    int maxId=-1;
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pLLamada=llamada_new();
            if(pLLamada!=NULL &&
                fread(pLLamada,sizeof(LLamada),1,pFile)&&
                ll_add(pArrayListLLamada,pLLamada)==0)
            {
                llamada_getId(pLLamada,&bufferInt);
                if (bufferInt>maxId)
                {
                    maxId=bufferInt;
                }
                retorno=0;
            }
            else
            {
                llamada_delete(pLLamada);
            }
        }
        llamada_setIdInicial(maxId+1);
    }
    return retorno;
}
