#include <stdlib.h>
void* createQueue();
typedef int compFunc(void* element1, void* element2);
int enqueue(void* queue,void* data, size_t priority,compFunc* compare);
void* dequeue(void* queue);