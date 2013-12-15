typedef struct
{
    void* element;
    void* previous;
} Data;

typedef struct {
    Data* top;
    int elementsPresent;
    int typeSize;
} Stack;
typedef char String[256];

Stack* create(int typeSize);
void push(Stack* stack,void* element);
Data* pop(Stack* stack);