#ifndef FUNCIONES_STRING_H_INCLUDED
#define FUNCIONES_STRING_H_INCLUDED


int inicializarArray(char *nombres[]);

int buscarLibre (char lista[][56], int* pIndex, int cantidadPos);
int getStringnnumero(char *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);
int getString(char *pResult,char *pMsg,char *pMsgError,int min,int max,int intentos);
void getString2(char mensaje[],char input[]);
int validarLetra (char letras[]);

int getNumber(int* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

int isValidIntNumber(char* cadena);
int getValidFloat( float* input,char requestMessage[],char errorMessage[],float lowLimit, float hiLimit,int attemps);
int getStringNumerosFlotantes(char mensaje[],char input[]);
int esNumericoFlotante(char str[]);

#endif // FUNCIONES_STRING_H_INCLUDED
