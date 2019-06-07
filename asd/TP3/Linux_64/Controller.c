#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    parser_EmployeeFromText(pFile , pArrayListEmployee);
    fclose(pFile);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int ret=-1;
    FILE* pfile=fopen(path,"rb");
    if(pfile!=NULL)
    {
        ret=parser_EmployeeFromBinary(pfile,pArrayListEmployee);
    }
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int size;
    int i;
    char nombre[1024];
    int sueldo;
    int id;
    int hstrabajada;
    FILE* pfile=fopen(path,"w+");
    if(pfile!=NULL)
    {
        fprintf(pfile,"id,nombre,horasTrabajadas,sueldo\n");
        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);

            employee_getId(pEmp,&id);
            employee_getNombre(pEmp,nombre);
            employee_getSueldo(pEmp,&sueldo);
            employee_getHorasTrabajadas(pEmp,&hstrabajada);

            //fprintf(pfile,"%d,%s,%d,%d\n",pEmp->id,pEmp->nombre,pEmp->horasTrabajadas,pEmp->sueldo);
            fprintf(pfile,"%d,%s,%d,%d\n",id,nombre,hstrabajada,sueldo);

        }
        fclose(pfile);
    }



    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* pEmp;
    int size;
    int i;

    FILE* pfile=fopen(path,"w+");
    if(pfile!=NULL)
    {

        size=ll_len(pArrayListEmployee);
        for(i=0;i<size;i++)
        {
            pEmp=ll_get(pArrayListEmployee,i);


            fwrite(pEmp,sizeof(Employee),1,pfile);


        }
        fclose(pfile);
    }

    return 1;
}

