#include <stdbool.h>

typedef char String[50];

typedef int compareFunction(void* , void*);

void* bSearch(void* array,void* key,int length,int elementSize,compareFunction* compare);
