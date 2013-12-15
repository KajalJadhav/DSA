typedef char String[256];

typedef struct queue{
    void* data;
    int priority;
    struct queue *next;
}Queue;

typedef struct{
    Queue *front;
    int length;
}List;

List* create();
typedef int compareFunc(void* , void*);
int insertElement(List *queue,Queue *q,compareFunc* compare);
int removeElement(List* queue);