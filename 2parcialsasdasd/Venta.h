#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
#define TEXT_SIZE 30

typedef struct
{
    int id;
    char fecha[TEXT_SIZE];//fecha
    char tipo[TEXT_SIZE];
    float precio;//precio
    int cantidad;//cantidadr
    char cuit[TEXT_SIZE];
}Fotos;

void ventas_setIdInicial(int val);
int ventas_generarId(void);
void ventas_imprimirMasterId(void);

Fotos* ventas_new(void);
Fotos* ventas_newParametros(char* idStr,char* fechaStr,char* tipo , char* cantidadStr,char* precioStr,char* cuit);
void ventas_delete(Fotos* this);

int ventas_setId(Fotos* this,int id);
int ventas_getId(Fotos* this,int* id);
int ventas_setIdStr(Fotos* this,char* id);

int ventas_setTipo(Fotos* this,char* fecha);
int ventas_getTipo(Fotos* this,char* fecha);


int ventas_setCantidad(Fotos* this,int cantidad);
int ventas_getCantidad(Fotos* this,int* cantidad);
int ventas_setCantidadStr(Fotos* this,char* cantidadStr);

int ventas_setIntDos(Fotos* this,int intDos);
int ventas_getIntDos(Fotos* this,int* intDos);
int ventas_setIntDosStr(Fotos* this,char* intDos);

int ventas_setPrecio(Fotos* this,float precio);
int ventas_getPrecio(Fotos* this,float* precio);
int ventas_setPrecioStr(Fotos* this,char* precioStr);

int ventas_printNode(Fotos *this);
int ventas_comparaTipo(void *this,void *that);

int ventas_getCuit(Fotos* this,char* cuit);
int ventas_setCuit(Fotos* this,char* cuit);

int ventas_setFecha(Fotos* this,char* fecha);
int ventas_getFecha(Fotos* this,char* fecha);




 //int ventas_setPesoStr(Fotos* this,char* precioStr, char* elotro);
#endif // ENTREGAS_H_INCLUDED
