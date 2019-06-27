#ifndef logistica_H_INCLUDED
#define logistica_H_INCLUDED
typedef struct
{
    int id;
    char tipo[128];
    int cantidad;
    float peso;
}Logistica;

Logistica* logistica_new();
int logistica_generarId(void);
void logistica_iniciarId(int val);

Logistica* logistica_newParametros(char* idStr,char* tipoStr,char* cantidadStr,char* peso);
void logistica_delete();

int logistica_setId(Logistica* this,int id);
int logistica_getId(Logistica* this,int* id);
int logistica_setIdchar(Logistica* this,char* id);


int logistica_setTipo(Logistica* this,char* tipo);
int logistica_getTipo(Logistica* this,char* tipo);

int logistica_setCantidad(Logistica* this,int cantidad);
int logistica_getCantidad(Logistica* this,int* cantidad);
int logistica_setCantidadstr(Logistica* this,char* cantidad);

int logistica_setPeso(Logistica* this,int peso);
int logistica_getPeso(Logistica* this,float* peso);
int logistica_setPesostr(Logistica* this,char* peso);

int logistica_comparaNombre(void *this,void *that);
int logistica_searchId(LinkedList* pArrayListLogistica, int id);


#endif // logistica_H_INCLUDED

