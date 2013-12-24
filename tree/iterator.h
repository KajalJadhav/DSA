#include "dList.h"
typedef struct Iterator{
	node* current;
	DoubleList* list;
} Iterator;

void* next(Iterator* it);
int hasNext(Iterator* it);