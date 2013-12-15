#include "priorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

List* create(){
    List *queue = calloc(sizeof(List),1);
    return queue;
}

int frontInsert(Queue *process,List *queue){
    if(queue->front == NULL)
        process->next = NULL;
    else process->next = queue->front;
    queue->front = process;
    queue->length++;
    return queue->length;        
}

int insertElement(List *queue,Queue *q,compareFunc* compare){
    Queue *previous,*next,*temp;
    int result;
    temp = queue->front;
    if(queue->length == 0)                
        return frontInsert(q,queue);
           if(compare(&q->priority,&temp->priority) < 0) 
        return frontInsert(q,queue);
    while(temp != NULL){
        previous = temp;
        next = temp->next;
        temp = temp->next;
        if(q->priority < next->priority){
                previous->next = q;
                    q->next = next;
                    return ++queue->length;
        }
    };
    return 0;
}
int removeElement(List *queue){
        if(queue->length == 0) return 1;
        queue->front = queue->front->next;
        queue->length--;
    return 0;
}