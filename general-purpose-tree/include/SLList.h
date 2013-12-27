#include "iterator.h"
typedef struct Node{
	void* data;
	struct Node* next;
} Node;

typedef struct list{
	Node* head;
	int length;
} List;

List* create();
int insertNode(List* list,int index,void* data);
int deleteNode(List* list,int index);
Iterator getIterator(List* list);