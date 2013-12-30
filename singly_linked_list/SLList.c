#include "SLList.h"
#include <stdlib.h>

List* createList(){
	List* list = (List*)malloc(sizeof(List));
	list->head = NULL;
	list->length = 0;
	return list;
}

int insertAtFront(Node* newNode,List* list,int index,Node* head){
    if(index == 0){
        list->head = newNode;
        return 1;
    }
    return 0;
}

int insertAtEnd(Node* newNode,List* list,int index,Node* head){
    if(index == list->length){               
        head->next = newNode;
        return 1;
    }
    return 0;
}

void insertAtMiddle(Node* newNode,Node* head){
    newNode->next = head->next;
    head->next = newNode;
}

int insertNode(List *list,int index,void* data){
    Node *head,*newNode;
    int i;
    if(index <= -1 || index > list->length)
        return 0;
    list->length++;
        head = list->head;
    for (i = 0; i < index; ++i){
        if(head->next != NULL)
            head = head->next;
    }
    newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    if(1 == insertAtFront(newNode,list,index,head)) return 1;
    if(1 == insertAtEnd(newNode,list,index,head)) return 1;
    insertAtMiddle(newNode, head);
    return 1;
}

int deleteNode(List* list,int index){
    int i;
    Node *head, *deletedNode;
    if(index <= -1 || index >= list->length)
        return 0;
    head = list->head;
    for(i = 0 ; i < index ; i++)
        head = head->next;
    if(i == 0){            
        list->head = list->head->next;
    	list->length--;
		free(head);
        return 1;
    }
    if(i == list->length - 1){     
        list->head->next = NULL;
        list->length--;
        return 1;
    }
    list->head->data = head->next->data;
    list->length--;
    return 1;
};

int isNextNodePresent(Iterator *it){
    List list;
    if(NULL == it->list) return 0;
    list = *(List*)it->list;
    if(it->position == list.length) return 0;
    return 1;
}

void* nextNodeInList(Iterator *it){
    int i;
    Node* currentNode;
    if(isNextNodePresent(it) == 0) return NULL;
    currentNode = ((List*)(it->list))->head;
    for(i = 0; i<it->position; i++){
            currentNode = currentNode->next;
    };
    it->position++;
    return currentNode->data;
}

Iterator getIteratorForList(List *list){
    Iterator it;
    it.list = list;
    it.position = 0;
    it.hasNext = &isNextNodePresent;
    it.next = &nextNodeInList;
    return it;
}

void disposeList(List *list){
    Node *nextNode;
    if(list->head == NULL)
        return;
    nextNode = list->head;
    list->head = nextNode->next;
    free(nextNode);
    disposeList(list);
}