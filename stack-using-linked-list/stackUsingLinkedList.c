#include "stackUsingLinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int push(List* stack,void* element){
    int result,index;
    index = stack->length;
    result = insertNode(stack,index,element);
    return result;
}
void* pop(List* stack){
    void* result;
    int index = stack->length-1;
    result = deleteNode(stack,index);
    return result;
};