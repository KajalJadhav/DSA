#include "DLList.h"

typedef struct {
	node* current;
	DLList* list;
} Iterator;

void* next(Iterator* it);

int hasNext(Iterator* it);