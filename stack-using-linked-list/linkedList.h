typedef struct node{
    void* data;
    struct node *next;
} Node;

typedef struct list{
    Node* head;
    int length;
} List;

List* create();
int insertNode(List *list,int index,void* data);
void* deleteNode(List* list,int index);