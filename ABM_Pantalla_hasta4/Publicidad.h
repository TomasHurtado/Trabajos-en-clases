#ifndef PUBLICIDAD_H_INCLUDED
#define PUBLICIDAD_H_INCLUDED

typedef struct
{
    char cuit[50];
    char archivo[250];
    int dias;
    int isEmpty; ///1vacio - 0ocupado
    int idPublicidad; ///clave unica de identidad univoca
    int idPantalla;
}Publicidad;

int pub_initPublicidad(Publicidad* pPublicidad,int len);

int pub_addPub(Publicidad* pPublicidad,Pantalla* pPantalla,int len,char* msgE,int tries);
int pub_removePublicidad(Publicidad* pPublicidad, int len,char* msgE,int tries);

int pub_findPubById(Publicidad* pPublicidad, int len, int idE);
int pub_findFree(Publicidad* pPublicidad, int len);

int pub_getID (Publicidad* pPublicidad,int len,char* msgE,int tries);
int pub_printContrataciones(Publicidad* pPublicidad,Pantalla* pPantalla,int lenPub,int lenPan);
void pub_printContrataciones2(Publicidad* lista,int len);
void printpublicidaddiasmenores(Publicidad* pPublicidad,Pantalla* pPantalla,int lenPan,int lenPub,int dia);
int pan_orderByday(Publicidad* pPublicidad, int len);

#endif // PUBLICIDAD_H_INCLUDED
