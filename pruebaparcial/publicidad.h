#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
typedef struct
{   int id_publicidad;
    int isEmpty;
    char cuit_cliente[50];
    int cantidad_dias;
    char archivo[50];
    int id_pantalla;


}Publicidad;


#endif // PUBLICIDAD_H_INCLUDED
