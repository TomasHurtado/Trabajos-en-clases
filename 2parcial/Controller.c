#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Venta.h"




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListFotos)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"r");
    if (pFile!=NULL && parser_FotosFromText(pFile , pArrayListFotos)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListFotos)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if (pFile!=NULL && parser_FotosFromBinary(pFile , pArrayListFotos)==0)
    {
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */


/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
int controller_sortFotos(LinkedList* pArrayListFotos)
{
    int retorno=-1;
    if (pArrayListFotos!=NULL)
    {
      //  ll_sort(pArrayListFotos,venta_comparaTipo,1);
        retorno=0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
/*int controller_saveAsText(char* path , LinkedList* pArrayListFotos)
{
    int retorno=-1;
    int i;
    int size;
    int bufferId;
    char bufferTipo[4096];
    int bufferCantidad;
    float bufferPeso;
    Fotos* pFotos;
    FILE* fp = fopen(path,"w+");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListFotos);
        fprintf(fp,"id,fecha,Cantidad,Peso\n");
        for(i=0;i<size;i++)
        {
            pFotos=ll_get(pArrayListFotos,i);
            venta_getId(pFotos,&bufferId);
            venta_getTipo(pFotos,bufferTipo);
            venta_getCantidad(pFotos,&bufferCantidad);
            venta_getPeso(pFotos,&bufferPeso);
            //venta_getIntDos(pFotos,&bufferIntDos);

            fprintf(fp,"%d,%s,%d,%f\n",bufferId,bufferTipo,bufferCantidad,bufferPeso);

        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}*/

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListFotos LinkedList*
 * \return int
 *
 */
/*int controller_saveAsBinary(char* path , LinkedList* pArrayListFotos)
{
    int retorno=-1;
    int i;
    int size;
    Fotos* pFotos;
    FILE* fp = fopen(path,"w+b");
    if (fp!=NULL)
    {
        size=ll_len(pArrayListFotos);
        for(i=0;i<size;i++)
        {
            pFotos=ll_get(pArrayListFotos,i);
            fwrite(pFotos,sizeof(Fotos),1,fp);
        }
        retorno=0;
        fclose(fp);
    }
    return retorno;
}
int controller_searchIdFotos(LinkedList* pArrayListFotos, int id)
{
    int retorno=-1;
    int lenLista;
    int i;
    int bufferId;
    if (pArrayListFotos!=NULL && id>0 && ll_len(pArrayListFotos)!=0)
    {
        lenLista=ll_len(pArrayListFotos);
        for (i=0;i<lenLista;i++)
        {
            venta_getId(ll_get(pArrayListFotos,i),&bufferId);
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
        venta_getCodigo((Fotos*)this,&bufferCodigo);
        if (codigo==bufferCodigo)
        {
            venta_printNode(this);
            retorno=0;
        }
    }
    return retorno;
}
*/

/*int controller_ListFotosMagia(LinkedList* this, LinkedList* that)
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
            printf("cantidad de venta= %d \f monto total= %f",cantVentas,montoTotal);
            ll_iterFinishIter(iteratorB);
        }
        returnAux=0;
    }
    ll_iterFinishIter(iteratorA);
    return returnAux;

}*/



int controller_cantidadDeFoto(LinkedList* this,FILE* pFile)
{
    int returnAux=-1;

    int lenLista=ll_len(this);
    void* auxElement;
    int contador=0;
    int cantidad;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_get(this,i);
            ventas_getCantidad(auxElement,&cantidad);
            contador+=cantidad;
        }
        returnAux=contador;
        fprintf(pFile,"\nCantidad de fotos reveladas: %d",contador);

    }

    return returnAux;
}

int controller_cantidadMax150(LinkedList* this,FILE* pFile)
{
    int returnAux=-1;
    int lenLista=ll_len(this);
    void* auxElement;
    float precio;
    int cont=0;
    int cant;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_get(this,i);
            ventas_getPrecio(auxElement,&precio);
            ventas_getCantidad(auxElement,&cant);
            if ((precio*cant)>150)
            {
                cont++;
            }
        }
        returnAux=0;
        fprintf(pFile,"\nCantidad de ventas mayores a 150 son: %d",cont);

    }
    return returnAux;
}

int controller_cantidadMax300(LinkedList* this,FILE* pFile)
{
   int returnAux=-1;
    int lenLista=ll_len(this);
    void* auxElement;
    float precio;
    int cont=0;
    int cant;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_get(this,i);
            ventas_getPrecio(auxElement,&precio);
            ventas_getCantidad(auxElement,&cant);
            if ((precio*cant)>300)
            {
                cont++;
            }
        }
        returnAux=0;
        fprintf(pFile,"\nCantidad de ventas mayores a 300 son: %d",cont);

    }
    return returnAux;
}

int controller_cantidaddFotos(LinkedList* this,FILE* pFile)
{
    int returnAux=-1;
    int lenLista=ll_len(this);
    void* auxElement;
    int cantidad;
    int cont=0;
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_get(this,i);
            ventas_getCantidad(auxElement,&cantidad);
            cont=cantidad+cont;

        }
        returnAux=0;
        fprintf(pFile,"\nCantidad de fotos reveladas: %d",cont);

    }
    return returnAux;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Fotos* pEmp;
    int id;
    float precio;
    int cantidad;
    char nombre[128];
    char cuit[128];
    char fecha[128];
    int size;
    int i;

    if(pArrayListEmployee!=NULL)
    {
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);
            ventas_getId(pEmp,&id);
            ventas_getTipo(pEmp,nombre);
            ventas_getPrecio(pEmp,&precio);
            ventas_getCantidad(pEmp,&cantidad);
            ventas_getCuit(pEmp,cuit);
            ventas_getFecha(pEmp,fecha);
            if(pEmp!=NULL)
            {
                printf("Id: %d,fecha: %s,tipo: %s,cantidad: %d precio %f cuit %s\n",id,fecha,nombre,cantidad,precio,cuit);
            }
        }
    }
   return 1;
}

int controller_comparar(void* this,void* that)
{
    int retorno;
    char pol[124]="POLAROID_11x9";
    char ploi[124]="POLAROID_10x10";
    int comparacion = strcmp(((Fotos*)this)->tipo,(pol));
    int comparaciond = strcmp(((Fotos*)this)->tipo,(ploi));
    if (comparacion<0 || comparaciond<0)
    {
        retorno=1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}


int controller_cantidadDeEntregasPorTipo(LinkedList* this,FILE* pFile)
{
    int returnAux=-1;
    int lenLista=ll_len(this);
    void* auxElement;
    int contador10=0;
    char tipo[10];
    int i;
    if (this!=NULL)
    {
        returnAux=0;
        for(i=0;i<lenLista;i++)
        {
            auxElement=ll_get(this,i);
            ventas_getTipo(auxElement,tipo);
            if (strncmp(tipo,"POLAROID_11x9",sizeof(tipo))==0 || (strncmp(tipo,"POLAROID_10x10",sizeof(tipo))==0))
            {
                contador10++;

            }

        }
        fprintf(pFile,"\nCantidad de fotos tipo: polaroid= %d",contador10);
    }
    return returnAux;
}


