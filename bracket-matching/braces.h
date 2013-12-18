#include <stdbool.h>
typedef struct {
    void* elements;
    int top;
    int length;
    int elementSize;
}Stack;

typedef char String[256];
Stack* create(int length,int elementSize);
int push(Stack* stack,void* element);

void* pop(Stack* stack);
void* peek(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
bool braceMatch(String str);