#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

Persona* persona_new()
{
    return (Persona*) malloc(sizeof(Persona));
}

Persona* persona_newParametros(int id,char* nombre, char* apellido,int edad)
{
    return NULL;
}


int persona_setId(Persona* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = *id;
        retorno = 0;
    }
    return retorno;
}

int persona_setname(Persona* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre !=NULL)
    {
        strncpy(this->nombre,nombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}

int persona_setapellido(Persona* this, char* apellido)
{
    int retorno = -1;
    if(this != NULL && apellido !=NULL)
    {
       strncpy(this->apellido,apellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}


int persona_setedad(Persona* this, int* edad)
{
    int retorno = -1;
    if(this != NULL && edad >= 0)
    {
        this->edad = *edad;
        retorno = 0;
    }
    return retorno;
}


int personas_getId(Persona* this,int* pid)
{
    int retorno = -1;
    if(this != NULL && pid != NULL)
    {
        *pid = this->id;
        retorno = 0;
    }
    return retorno;
}

int personas_getname(Persona* this, char* pnombre)
{
    int retorno = -1;
    if(this != NULL && pnombre != NULL)
    {
        //*pnombre = this->nombre;
        strncpy(this->nombre,pnombre,sizeof(this->nombre));
        retorno = 0;
    }
    return retorno;
}


int personas_getapelldio(Persona* this, char* papellido)
{
    int retorno = -1;
    if(this != NULL && papellido != NULL)
    {
       // *papellido = this->apellido;
        strncpy(this->apellido,papellido,sizeof(this->apellido));
        retorno = 0;
    }
    return retorno;
}


int personas_getedad(Persona* this, int* pedad)
{
    int retorno = -1;
    if(this != NULL && pedad != NULL)
    {
        *pedad = this->edad;
        retorno = 0;
    }
    return retorno;
}

int personas_initarray(Persona* personas[],int len)
{
    int i;
    int ret=-1;
    if(personas!=NULL)
    {
        ret=0;
        for(i=0;i<len;i++)
        {
            personas[i]=NULL;
        }
    }
    return ret;
}

static int cont=0;
static int generar(void)
{
    cont++;
    return cont;
}

void personas_inicializarID(int val)
{
    cont=val;
}
