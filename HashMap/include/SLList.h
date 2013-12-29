#include "../../iterator.h"
typedef struct Node{
	void* data;
	struct Node* next;
} Node;

typedef struct list{
	Node* head;
	int length;
} List;
typedef int Compare(void* element,void* toSearch);

List* createList();
int insertNode(List* list,int index,void* data);
int deleteNode(List* list,int index);
Iterator getIteratorForList(List* list);