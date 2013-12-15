#include <stdbool.h>

typedef struct{
	int capacity;
	int size;
	int rear;
	void* elements;
}Queue;

typedef char String[256];
Queue* create(int maxElements,int elementSize);
int enqueue(Queue *queue,void* element);
void* dequeue(Queue *queue);
void* rear(Queue *queue);