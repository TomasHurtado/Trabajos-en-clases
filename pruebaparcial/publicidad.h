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
int pub_Alta(Pantalla* pantallas, int cantidad, int posLibre);
int pub_Inicializar(Pantalla* pantallas, int cantidad);
int pub_buscarLibre(Pantalla* pantallas, int cantidad, int* devuelve);
void pub_mostrarArray(Pantalla* pantallas, int cantidad);
int pub_buscarEnArray (Pantalla* pantallas, int cantidad, int* pantallaEncontrado);
int pub_baja(Pantalla* pantallas, int cantidad);

#endif // PUBLICIDAD_H_INCLUDED
