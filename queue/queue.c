#include "queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Queue* create(int maxElements, int elementSize){
	Queue *q;
	q = (Queue*)malloc(sizeof(Queue));
	q->elements = calloc(maxElements,elementSize);
	q->capacity = maxElements;
	q->size = elementSize;
	q->rear = -1;
	return q;
} 

int isFull(Queue* queue){
	if(queue->capacity-1 == queue->rear)
		return true;
	return false;
}

int isEmpty(Queue* queue){
	if(queue->rear == -1)
		return true;
	return false;
}

int enqueue(Queue *queue,void* element){
	if(isFull(queue))
		return 1;
	else{
		void* address;
		queue->size++;
		queue->rear = queue->rear + 1;
		address = queue->elements+(queue->rear*queue->size);
		memmove(address,element,queue->size);
	}
	return 0;
}

void* dequeue(Queue *queue){
	void* poppedElement = malloc(queue->size);	
	memcpy(poppedElement,queue->elements,queue->size);
	if(isEmpty(queue)) return NULL;
	memmove(queue->elements,queue->elements+queue->size,(queue->capacity-1)*queue->size);
	queue->rear--;
	return poppedElement;
}

