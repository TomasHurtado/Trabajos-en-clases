#ifndef ENTREGAS_H_INCLUDED
#define ENTREGAS_H_INCLUDED
#define TEXT_SIZE 10

typedef struct
{
    int id;
    char tipo[TEXT_SIZE];//tipo
    float peso;//peso
    int cantidad;//cantidadr
}Fotos;

void entregas_setIdInicial(int val);
int entregas_generarId(void);
void entregas_imprimirMasterId(void);

Fotos* entregas_new(void);
Fotos* entregas_newParametros(char* idStr,char* tipoStr,char* cantidadStr, char* pesoStr);
void entregas_delete(Fotos* this);

int entregas_setId(Fotos* this,int id);
int entregas_getId(Fotos* this,int* id);
int entregas_setIdStr(Fotos* this,char* id);

int entregas_setTipo(Fotos* this,char* tipo);
int entregas_getTipo(Fotos* this,char* tipo);


int entregas_setCantidad(Fotos* this,int cantidad);
int entregas_getCantidad(Fotos* this,int* cantidad);
int entregas_setCantidadStr(Fotos* this,char* cantidadStr);

int entregas_setIntDos(Fotos* this,int intDos);
int entregas_getIntDos(Fotos* this,int* intDos);
int entregas_setIntDosStr(Fotos* this,char* intDos);

int entregas_setPeso(Fotos* this,float peso);
int entregas_getPeso(Fotos* this,float* peso);
int entregas_setPesoStr(Fotos* this,char* pesoStr);

int entregas_printNode(Fotos *this);
int entregas_comparaTipo(void *this,void *that);

 //int entregas_setPesoStr(Fotos* this,char* pesoStr, char* elotro);
#endif // ENTREGAS_H_INCLUDED

