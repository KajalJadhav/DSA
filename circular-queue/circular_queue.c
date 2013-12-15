#include "circular_queue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

Queue* create(int maxElements,int elementSize){
    Queue *queue;
    queue = (Queue*)malloc(sizeof(Queue));
    queue->elements = calloc(maxElements,elementSize);
    queue->capacity = maxElements;
    queue->size = elementSize;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isFull(Queue* queue){
    if(queue->capacity-1 == queue->rear && queue->front == 0)
        return true;
    return false;
}

int isEmpty(Queue* queue){
    if(queue->rear == -1)
            return true;
    return false;
}

int enqueue(Queue *queue,void* element){
    int length = queue->front;
    if(queue->front > 0 && (queue->front <= length))
            queue -> rear = -1;
    if(isFull(queue))
    	return 1;
    else {
      	void* address;
        queue->rear++;
        address = queue->elements+(queue->rear*queue->size);
            memmove(address,element, queue->size);
        return 0;
    }
}

void* dequeue(Queue* queue){
	void* elements = malloc(queue->size);
    if(isEmpty(queue)) return false;        
    memmove(elements,queue->elements+(queue->size*queue->front),queue->size);
    queue->front++;
    return elements;
}

void* front(Queue *queue){
    if(queue->rear == -1)
        return false;
    return &queue->front;
}