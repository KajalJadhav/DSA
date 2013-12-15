typedef struct {
    int capacity;
    int size;
    int front;
    int rear;
    void *elements;
} Queue;

typedef char String[256];

Queue* create(int maxElements,int elementSize);
int enqueue(Queue *queue,void* element);
void* dequeue(Queue *queue);
void* front(Queue *queue);
int isFull(Queue *queue);
int isEmpty(Queue *queue);