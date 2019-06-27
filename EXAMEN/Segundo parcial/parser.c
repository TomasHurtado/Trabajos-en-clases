#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int parser_LogisticaFromText(FILE* pFile , LinkedList* pArrayListLogistica)
{
    char bufferId[4096];
    char bufferTipo[4096];
    char bufferCantidad[4096];
    char bufferPeso[4096];
    int id;
    int maxId=-1;
    int retorno=-1;
    Logistica *pEmpleado;


    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferTipo,bufferCantidad,bufferPeso);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",  bufferId,bufferTipo,bufferCantidad,bufferPeso);

            pEmpleado = logistica_newParametros(bufferId,bufferTipo,bufferCantidad,bufferPeso);

            if(pEmpleado != NULL)
            {
                if(ll_add(pArrayListLogistica,pEmpleado))
                {
                    logistica_getId(pEmpleado,&id);
                    if (id>maxId)
                    {
                        maxId=id;
                    }
                    retorno=0;

                }
            }
              logistica_iniciarId(maxId+1);
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int parser_LogisticaFromBinary(FILE* pFile , LinkedList* pArrayListLogistica)
{
    Logistica* pempleado;

    do{
        pempleado= logistica_new();

        if(pempleado!= NULL && fread(pempleado,sizeof(Logistica),1,pFile)==1)
        {
            ll_add(pArrayListLogistica,pempleado);
        }
        else
        {
            logistica_delete(pempleado);
        }

    }while(!feof(pFile));

    return 1;
}

