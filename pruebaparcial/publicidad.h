#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED
typedef struct
{   int id_publicidad;
    int isEmpty;

    char cuit_cliente[50];
    char cantidad_dias;
    char archivo[50];
    int id_pantalla;
}Publicidad;

int pub_Inicializar(Publicidad* publicidades, int cantidad);
int pub_Alta(Publicidad* publicidades, int cantidad, int posLibre);
int pub_buscarLibre(Publicidad* publicidades, int cantidad, int* devuelve);
void pub_mostrarArray(Publicidad* publicidades, int cantidad);
int pub_baja(Publicidad* publicidades, int cantidad);
int pub_buscarEnArray (Publicidad* publicidades, int cantidad, int* publicidadEncontrado);

#endif // PUBLICIDAD_H_INCLUDED
