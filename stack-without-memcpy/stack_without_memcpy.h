typedef struct{
    void *elements;
    int top;
    int elementsSize;
    int size;
}stack;

typedef char String[256];

stack* create(int elementsSize,int size);
int push(stack* Stack,void* element);
void* pop(stack* Stack);
void* top(stack* Stack);