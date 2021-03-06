#include "../iterator.h"
typedef struct Node{
	void* data;
	struct Node* next;
} Node;

typedef struct list{
	Node* head;
	int length;
} List;

List* createList();
int insertNode(List* list,int index,void* data);
int deleteNode(List* list,int index);
Iterator getIteratorForList(List* list);
void disposeList(List *list);