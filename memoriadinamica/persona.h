#ifndef PERSONA_H
#define PERSONA_H

typedef struct
{
    int id;
    char nombre[32];
    char apellido[32];
    int edad;
}Persona;
#endif

Persona* persona_new();
Persona* persona_newParametros(int id,char* nombre, char* apellido,int edad);
//busca
int persona_setId(Persona* this, int* id);
int persona_setname(Persona* this, char* nombre);
int persona_setapellido(Persona* this, char* apellido);
int persona_setedad(Persona* this, int* edad);
//asigna
int personas_getId(Persona* this,int* pid);
int personas_getname(Persona* this, char* pnombre);
int personas_getapelldio(Persona* this, char* papellido);
int personas_getedad(Persona* this, int* pedad);
