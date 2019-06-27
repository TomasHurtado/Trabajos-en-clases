int controller_loadFromText(char* path , LinkedList* pArrayListLogistica);
int controller_loadFromBinary(char* path , LinkedList* pArrayListLogistica);
int controller_addLogistica(LinkedList* pArrayListLogistica);
int controller_editLogistica(LinkedList* pArrayListLogistica);
int controller_removeLogistica(LinkedList* pArrayListLogistica);
int controller_ListLogistica(LinkedList* pArrayListLogistica);
int controller_sortLogistica(LinkedList* pArrayListLogistica);
int controller_saveAsText(char* path , LinkedList* pArrayListLogistica);
int controller_saveAsBinary(char* path , LinkedList* pArrayListLogistica);
int controller_promediopeso(LinkedList* this);

