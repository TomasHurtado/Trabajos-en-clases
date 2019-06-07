#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"


Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    Employee* emp=employee_new();
    if(emp!=NULL)
    {
        employee_setIdchar(emp,idStr);
        employee_setNombre(emp,nombreStr);
        employee_setHorasTrabajadaschars(emp,horasTrabajadasStr);
        employee_setSueldochar(emp,sueldo);

    }


    return emp;
}



int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}


int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{

    int retorno = -1;
    if(this != NULL && isLetter(nombre))
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strncpy(nombre,this->nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{

    int retorno = -1;
    if(this != NULL && sueldo >= 0)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


int employee_setIdchar(Employee* this,char* id)
{
    int val;
    int retorno = -1;
    if(this != NULL &&  isValidnumeric(id))

    {
        val=atoi(id);
        this->id = val;
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadaschars(Employee* this,char* horasTrabajadas)
{
    int val;
    int retorno = -1;
    if(this != NULL )
    {
        val=atoi(horasTrabajadas);
        this->horasTrabajadas = val;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldochar(Employee* this,char* sueldo)
{
    int val;
    int retorno = -1;
    if(this != NULL && isValidNumber(sueldo))
    {
        val=atoi(sueldo);
        this->sueldo = val;
        retorno = 0;
    }
    return retorno;
}
