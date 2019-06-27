#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLogistica)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    parser_LogisticaFromText(pFile , pArrayListLogistica);
    fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListLogistica)
{
    int ret=-1;
    FILE* pfile=fopen(path,"rb");
    if(pfile!=NULL)
    {
        ret=parser_LogisticaFromBinary(pfile,pArrayListLogistica);
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_addLogistica(LinkedList* pArrayListLogistica)
{
    Logistica* pEmp;
    int id;
    char tipo[128];
    int cantidad;
    int peso;
    int ret=-1;
    pEmp= logistica_new();
    id=logistica_generarId();
    utn_getName("Ingrese tipo","Error",0,128,2,tipo);
    utn_getUnsignedInt("Ingrese cantidad","Error",0,1000,0,900000,2,&cantidad);
    utn_getUnsignedInt("Ingrese peso","Error",0,1000,0,900000,2,&peso);

    if(pEmp!=NULL && !logistica_setId(pEmp,id) && !logistica_setTipo(pEmp,tipo) && !logistica_setCantidad(pEmp,cantidad) && !logistica_setPeso(pEmp,peso))
    {

            ll_add(pArrayListLogistica,pEmp);
            ret=0;

    }
    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_editLogistica(LinkedList* pArrayListLogistica)
{
    int retorno=-1;
    int id;
    int idaEditar;
    char tipo[128];
    int cantidad;
    int peso;
    int opcion;
    Logistica *pEmp;
    if(pArrayListLogistica!=NULL)
    {
        controller_ListLogistica(pArrayListLogistica);
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),0,30000,1,&id);
        idaEditar=logistica_searchId(pArrayListLogistica,id);
        if(idaEditar==-1)
        {
            printf("\nError");
        }
        else
        {
            do
            {
                pEmp=ll_get(pArrayListLogistica,idaEditar);

                utn_getUnsignedInt("\nModificar: \n1) Nombre \n2) Horas trabajadas \n3) Sueldo \n4)salir","\nError",1,10000,1,100000,1,&opcion);
                switch(opcion)
                {
                    case 1:
                        utn_getName("\nIngrese tipo: ","\nError",1,128,1,tipo);
                        logistica_setTipo(pEmp,tipo);
                        break;
                    case 2:
                        utn_getUnsignedInt("\nIngresde peso: ","\nError",1,sizeof(int),0,30000,1,&peso);
                        logistica_setPeso(pEmp,peso);
                        break;
                    case 3:
                        utn_getUnsignedInt("\nIngrese cantidad: ","\nError",1,sizeof(int),0,30000,1,&cantidad);
                        logistica_setCantidad(pEmp,cantidad);
                        break;
                    case 4:
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!=4);
            retorno=0;
        }
    }
    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_removeLogistica(LinkedList* pArrayListLogistica)
{
 int retorno=-1;
    int id;
    int idaEliminar;
    if(pArrayListLogistica!=NULL)
    {
        controller_ListLogistica(pArrayListLogistica);
        utn_getUnsignedInt("\nID a eliminar: ","\nError",1,6,0,30000,1,&id);
        idaEliminar=logistica_searchId(pArrayListLogistica,id);
        if(idaEliminar==-1)
        {
            printf("\nNo existe este ID");
        }
        else
        {
            ll_remove(pArrayListLogistica,idaEliminar);
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_ListLogistica(LinkedList* pArrayListLogistica)
{
    Logistica* pEmp;
    int id;
    int cantidad;
    float peso;
    char tipo[128];
    int size;
    int i;

    if(pArrayListLogistica!=NULL)
    {
        size=ll_len(pArrayListLogistica);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListLogistica,i);
            logistica_getId(pEmp,&id);
            logistica_getTipo(pEmp,tipo);
            logistica_getCantidad(pEmp,&cantidad);
            logistica_getPeso(pEmp,&peso);
            if(pEmp!=NULL)
            {
                printf("Id: %d,Tipo: %s,cantidad: %d,peso: %2.f\n",id,tipo,cantidad,peso);
            }
        }
    }
   return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_sortLogistica(LinkedList* pArrayListLogistica)
{
    int retorno=-1;
    if (pArrayListLogistica!=NULL)
    {
        ll_sort(pArrayListLogistica,logistica_comparaNombre,1);
        retorno=0;
    }
    return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLogistica)
{
    Logistica* pEmp;
    int size;
    int i;
    char tipo[1024];
    int cantidad;
    int id;
    float peso;
    FILE* pfile=fopen(path,"w+");
    if(pfile!=NULL)
    {
        fprintf(pfile,"id,tipo,pesoTrabajadas,cantidad\n");
        size=ll_len(pArrayListLogistica);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListLogistica,i);

            logistica_getId(pEmp,&id);
            logistica_getTipo(pEmp,tipo);
            logistica_getCantidad(pEmp,&cantidad);
            logistica_getPeso(pEmp,&peso);

            //fprintf(pfile,"%d,%s,%d,%d\n",pEmp->id,pEmp->tipo,pEmp->pesoTrabajadas,pEmp->cantidad);
            fprintf(pfile,"%d,%s,%d,%2.f\n",id,tipo,cantidad,peso);

        }
        fclose(pfile);
    }



    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListLogistica LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListLogistica)
{
    Logistica* pEmp;
    int size;
    int i;

    FILE* pfile=fopen(path,"w+");
    if(pfile!=NULL)
    {

        size=ll_len(pArrayListLogistica);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListLogistica,i);


            fwrite(pEmp,sizeof(Logistica),1,pfile);


        }
        fclose(pfile);
    }

    return 1;
}
int controller_promediopeso(LinkedList* this)
{
    int ret=-1;
    int i=0;
    int acum=0;
   Logistica* log;
    if(this !=NULL )
    {
        for(i=0;i<=ll_len(this);i++)
        {
        log=ll_get(this,i);
        acum+=log->peso;

        }

    }
    ret=acum/ll_len(this);

    return ret;
}

