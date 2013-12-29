#include "./include/SLList.h"

typedef struct{
	List *list;
} Slot;

typedef struct{
	void* key;
	void* value;
} HashElement;

Slot* createSlot();

HashElement *createHashElement(void* key,void* value);

HashElement* getElementFromList(List *list,void* key,Compare *compare);