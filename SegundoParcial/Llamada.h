#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
#define TEXT_SIZE 10

typedef struct
{
    int id;
    char fecha[TEXT_SIZE];//fecha
    int idCliente;//idCliente
    int idProblema;
    char solucion[TEXT_SIZE];//solucionr
}LLamada;

void llamada_setIdInicial(int val);
int llamada_generarId(void);
void llamada_imprimirMasterId(void);

LLamada* llamada_new(void);
LLamada* llamada_newParametros(char* idStr,char* fechaStr,char* idClienteStr, char* idProblema, char* solucion);
void llamada_delete(LLamada* this);

int llamada_setId(LLamada* this,int id);
int llamada_getId(LLamada* this,int* id);
int llamada_setIdStr(LLamada* this,char* id);

int llamada_setFecha(LLamada* this,char* fecha);
int llamada_getFecha(LLamada* this,char* fecha);


int llamada_setSolucionstr(LLamada* this,char* solucion);
int llamada_getSolucionstr(LLamada* this,char* solucion);

int llamada_setIntDos(LLamada* this,int intDos);
int llamada_getIntDos(LLamada* this,int* intDos);
int llamada_setIntDosStr(LLamada* this,char* intDos);

int llamada_setidCliente(LLamada* this,int idCliente);
int llamada_getidCliente(LLamada* this,int* idCliente);
int llamada_idCliente(LLamada* this,char* idClienteStr);

int llamada_getidProblema(LLamada* this,int* idProblema);
int llamada_setidProblema(LLamada* this,int idProblema);
int llamada_iidProblemastr(LLamada* this,char* idProblemastr);

int llamada_comparar(void *this);


int llamada_printNode(LLamada *this);
int llamada_comparaFecha(void *this,void *that);

 //int llamada_idCliente(LLamada* this,char* idClienteStr, char* elotro);
#endif // ENTREGAS_H_INCLUDED
