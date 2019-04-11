#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
int getInt(char mensaje[]);
float getFloat(char mensaje[]);
int pedirnumero(int linea[], int leng);
int mayor(int mayor[],int leng);
int menor(int menor[],int leng);
int promedio(int promedio[],int leng);
int ordenamiento(int ordenar[],int leng);
int buscarnumeros(int buscar[],int leng,int numabuscar);

int getString(  char *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);
int getNumber(  int *resultado,char *msg,char *msgError,int minimo,int maximo,int reintentos);
int isValidNumber (char* cadena);
#endif // UTN_H_INCLUDED
