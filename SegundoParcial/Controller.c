#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Llamada.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLLamada)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if (pFile!=NULL && parser_LLamadaFromText(pFile , pArrayListLLamada)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListLLamada)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if (pFile!=NULL && parser_LLamadaFromBinary(pFile , pArrayListLLamada)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
int controller_sortLLamada(LinkedList* pArrayListLLamada)
{
    int retorno=-1;
    if (pArrayListLLamada!=NULL)
    {
      //  ll_sort(pArrayListLLamada,venta_comparaFecha,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
/*int controller_saveAsText(char* path , LinkedList* pArrayListLLamada)
{
    int retorno=-1;
    int i;
    int size;
    int bufferId;
    char bufferFecha[4096];
    int bufferCantidad;
    float bufferPeso;
    LLamada* pLLamada;
    FILE* fp = fopen(path,"w+");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListLLamada);
        fprintf(fp,"id,fecha,Cantidad,Peso\n");
        for(i=0;i<size;i++)
        {
            pLLamada=ll_get(pArrayListLLamada,i);
            venta_getId(pLLamada,&bufferId);
            venta_getFecha(pLLamada,bufferFecha);
            venta_getCantidad(pLLamada,&bufferCantidad);
            venta_getPeso(pLLamada,&bufferPeso);
            //venta_getIntDos(pLLamada,&bufferIntDos);

            fprintf(fp,"%d,%s,%d,%f\n",bufferId,bufferFecha,bufferCantidad,bufferPeso);

        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLLamada LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path , LinkedList* pArrayListLLamada)
{
    int retorno=-1;
    int i;
    int size;
    LLamada* pLLamada;
    FILE* fp = fopen(path,"w+b");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListLLamada);
        for(i=0;i<size;i++)
        {
            pLLamada=ll_get(pArrayListLLamada,i);
            fwrite(pLLamada,sizeof(LLamada),1,fp);
        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}
int controller_searchIdLLamada(LinkedList* pArrayListLLamada, int id)
{
    int retorno=-1;
    int lenLista;
    int i;
    int bufferId;
    if (pArrayListLLamada!=NULL && id>0 && ll_len(pArrayListLLamada)!=0)
    {
        lenLista=ll_len(pArrayListLLamada);
        for (i=0;i<lenLista;i++)
        {
            venta_getId(ll_get(pArrayListLLamada,i),&bufferId);
            if (id==bufferId)
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
}*/

/*int controller_listByCOSA(LinkedList* this,int (*pFunc)(void*,void*))
{
    int returnAux=-1;
    IterNode* iterator=ll_iterInit(this);
    int lenLista=ll_len(this);
    void* auxElement;
    int i;
    char bufferCosa[1024];
    char bufferCodigo[1024];
    if (this!=NULL && pFunc!=NULL)
    {
        returnAux=0;
        utn_getAlfanumerico("\nIngrese Codigo de loque sea: ","\nError",0,60,1,bufferCosa);
        sscanf(bufferCosa,"%[^-]-",bufferCodigo);
        if (isValidNumber(bufferCodigo))
        {

            for(i=0;i<lenLista;i++)
            {
                auxElement=ll_iterNext(iterator);
                if (pFunc(auxElement,bufferCodigo)==-1)
                {
                    returnAux=-1*i;
                    break;
                }
            }
        }
    }
    ll_iterFinishIter(iterator);
    return returnAux;
}

int imprimoVenta(void* this, void* codigo)
{
    int retorno=-1;
    if (this!=NULL && codigo>0)
    {
        venta_getCodigo((LLamada*)this,&bufferCodigo);
        if (codigo==bufferCodigo)
        {
            venta_printNode(this);
            retorno=0;
        }
    }
    return retorno;
}
*/

/*int controller_ListLLamadaMagia(LinkedList* this, LinkedList* that)
{
    int returnAux=-1;
    IterNode* iteratorA=ll_iterInit(this);
    IterNode* iteratorB;
    int lenListaA=ll_len(this);
    int lenListaB=ll_len(that);
    void* auxElementA;
    void* auxElementB;
    int idCliente;
    int idVenta;
    float monto;
    float montoTotal;
    int cantVentas;
    int i;
    int j;
    if (this!=NULL && that!=NULL)
    {
        //returnAux=0;
        for(i=0;i<lenListaA;i++)
        {
            cantVentas=0;
            auxElementA=ll_iterNext(iteratorA);
            venta_getId(auxElementA,&idCliente);
            iteratorB =ll_iterInit(that);
            for(j=0;j<lenListaB;j++)
            {
                auxElementB=ll_iterNext(iteratorB);
                venta_getId(auxElementB,&idVenta);
                venta_getPeso(auxElementB,&monto);
                if (idCliente==idVenta)
                {
                    cantVentas++;
                    montoTotal+=monto;

                }
            }
            venta_printNode(auxElementA);
            printf("solucion de venta= %d \f monto total= %f",cantVentas,montoTotal);
            ll_iterFinishIter(iteratorB);
        }
        returnAux=0;
    }
    ll_iterFinishIter(iteratorA);
    return returnAux;

}*/


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    LLamada* pEmp;
    int id;
    int precio;
    char cantidad[128];
    char nombre[128];
    int cuit;
    int size;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);
            llamada_getId(pEmp,&id);
            llamada_getFecha(pEmp,nombre);
            llamada_getidCliente(pEmp,&precio);
            llamada_getSolucionstr(pEmp,cantidad);
            llamada_getidProblema(pEmp,&cuit);
//            llamada_getFecha(pEmp,fecha);
            if(pEmp!=NULL)
            {
                printf("Id: %d,fecha: %s,cliente: %d, solucion %s\n",id,nombre,precio,cantidad);

                switch(cuit)
                {

                    case 1:
                    printf("no enciende pc");
                    break;
                    case 2:
                    printf("no funciona mouse");
                    break;
                    case 3:
                    printf("no funciona teclado");
                    break;
                    case 4:
                    printf("no hay internet");
                    break;
                    case 5:
                    printf("no funciona telefono");
                    break;0

                }

            }
        }
    }
   return 1;
}


