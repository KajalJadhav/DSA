# include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "braces.h"

void* getElement(Stack* s,int top){
    return s->elements + top * s->elementSize;
};

Stack* create(int length, int elementSize){
    Stack* stack;
    stack = (Stack*)calloc(sizeof(Stack),1);
    stack->elements = calloc(elementSize,length);
    stack->elementSize = elementSize;
    stack->length = length;
    stack->top = 0;
    return stack;
}

int push(Stack* stack,void* element){
    if(isFull(stack))
        return 0;
    memcpy(getElement(stack,stack->top++),element,stack->elementSize);
    return 1;
}

void* pop(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return getElement(stack,--(stack->top));
};

void* peek(Stack* stack){
    if(isEmpty(stack)) return NULL;
    return getElement(stack,(stack->top-1));
}

int isEmpty(Stack* stack){
    if(stack->top)
        return 0;
    return 1;
}

int isFull(Stack* stack){
    if(stack->top == stack->length)
        return 1;
    return 0;
}

bool braceMatch(String str){
    Stack* stack;
    const char* input = str;
    void* current;
    int i,limit;
    stack = create(500,sizeof(char));
    limit = strlen(input);
    for(i = 0;i < limit;i++){
        // printf("%c\n",input[i] );
        if(input[i] == '{' || input[i] == '[' || input[i] == '('){
            push(stack,(void*)&input[i]);
        };
        if(input[i] == '}'){
            current = peek(stack);
            if(NULL == current) return false;
            if('{' == *(char*)current)
                pop(stack);
            else
                return false;
        }
        if(input[i] == ']'){
            current = peek(stack);
            if('[' == *(char*)current)
                pop(stack);
            else
                return false;
        }
        if(input[i] == ')'){
            current = peek(stack);
            if('(' == *(char*)current)
                pop(stack);
            else
                return false;
        }
    }
    if(stack->top == 0)
        return true;
    else
        return false;
    return 0;
}
