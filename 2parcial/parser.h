#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_FotosFromText(FILE* pFile , LinkedList* pArrayListFotos);
int parser_FotosFromBinary(FILE* pFile , LinkedList* pArrayListFotos);
#endif
