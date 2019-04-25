#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED
typedef struct
{   int id_pantalla;
    int isEmpty;

    char nombre[50];
    char direccion[50];
    float precio;
    char tipo[4];

}Pantalla;
int pant_Alta(Pantalla* pantallas, int cantidad, int posLibre);
int pant_Inicializar(Pantalla* pantallas, int cantidad);
int pant_buscarLibre(Pantalla* pantallas, int cantidad, int* devuelve);
void pant_mostrarArray(Pantalla* pantallas, int cantidad);
int pant_buscarEnArray (Pantalla* pantallas, int cantidad, int* pantallaEncontrado);
int pant_baja(Pantalla* pantallas, int cantidad);

#endif // PANTALLAS_H_INCLUDED
