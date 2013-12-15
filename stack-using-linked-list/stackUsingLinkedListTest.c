#include "testUtils.h"
#include "stackUsingLinkedList.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef char String[256];
List* list;

void tearDown(){
    free(list);
};

void test_1_gives_an_singly_linked_list_with_head_NULL(){
    list = create();
    ASSERT(NULL == list->head);
    ASSERT(0 == list->length);
};

void test_2_inserts_an_element_as_the_head_of_linked_list_for_integer(){
    int num = 10;
    int a;
    list = create();
    a = push(list,&num);
    ASSERT(a == 1);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
};

void test_3_inserts_elements_at_the_end_of_linked_List_of_integer(){
    int value;
    Node *result1,*result2;
    list = create();
    value = 10;
    push(list,&value);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
    
    value = 20;
    push(list,&value);
    result1 = list->head->next;
    ASSERT(20 == *(int*)result1->data);
    ASSERT(NULL == result1->next);
    ASSERT(2 == list->length);
};

void test_4_inserts_elements_at_the_end_of_linked_List_of_character(){
    char value;
    Node *result1,*result2;
    list = create();
    value = 'a';
    push(list,&value);
    ASSERT('a' == *(char*)list->head->data);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
    
    value = 'b';
    push(list,&value);
    result1 = list->head->next;
    ASSERT('b' == *(char*)result1->data);
    ASSERT(NULL == result1->next);
    ASSERT(2 == list->length);
};

void test_5_inserts_elements_at_the_end_of_linked_List_for_string(){
    String value;
    Node *result1,*result2;
    list = create();
    strcpy(value,"kajal");
    push(list,&value);
    ASSERT(!strcmp("kajal",*(String*)list->head->data));
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
    strcpy(value,"komal");
    push(list,&value);
    result1 = list->head->next;
    ASSERT(!strcmp("komal",*(String*)list->head->data));
    ASSERT(NULL == result1->next);
    ASSERT(2 == list->length);
};

void test_6_deletes_last_element_in_the_linked_List(){
    int* nums = malloc(sizeof(int)*4);
    void* result;
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    nums[3] = 40;
    push(list,&nums[0]);
    push(list,&nums[1]);
    push(list,&nums[2]);
    result = pop(list);
    ASSERT(*(int*)result == 30);
    ASSERT(2 == list->length);
    result = pop(list);
    ASSERT(*(int*)result == 20);
    ASSERT(1 == list->length);
    result = pop(list);
    ASSERT(*(int*)result == 10);
    ASSERT(0 == list->length);
};

void test_7_deletes_last_element_in_the_linked_List_of_character(){
    char* nums = malloc(sizeof(char)*4);
    void* result;
    list = create();
    nums[0] = 'a';
    nums[1] = 'b';
    nums[2] = 'c';
    nums[3] = 'd';
    push(list,&nums[0]);
    push(list,&nums[1]);
    push(list,&nums[2]);
    result = pop(list);
    ASSERT(*(char*)result == 'c');
    ASSERT(2 == list->length);
    result = pop(list);
    ASSERT(*(char*)result == 'b');
    ASSERT(1 == list->length);
    result = pop(list);
    ASSERT(*(char*)result == 'a');
    ASSERT(0 == list->length);
};

void test_fail(){
	ASSERT(0);
}
