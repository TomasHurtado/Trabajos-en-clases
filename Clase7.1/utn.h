#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


int utn_getString(char* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

//a partir de esta funcion puedo crear muchas otras de validacion
int utn_isValidIntNumber(char* cadena);

int utn_getNumber(int* pResultado,char* msg,char* msgError,int minimo,int maximo,int reintentos);

int buscarlibre(int *plibre, char lugar[][20]);

int buscarNombre(char* pnombre,char lugar[][20],int len,int* pindex);

#endif // UTN_H_INCLUDED
