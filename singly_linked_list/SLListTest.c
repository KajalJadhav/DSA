#include "testUtils.h"
#include "SLList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* list;

void tearDown(){
	free(list);
}

typedef char String[256];

typedef struct{
    int accountNo;
    int balance;
} Account;

int areAccountsEqual(Account expected,Account actual){
    return expected.accountNo == actual.accountNo && expected.balance == actual.balance;
}

void test_1_gives_a_singly_linked_list_with_head_NULL(){
	list = create();
	ASSERT(NULL == list->head);
	ASSERT(0 == list->length);
};

void test_2_inserts_element_as_head_of_linked_list(){
	int num = 10;
	list = create();
	insertNode(list,0,&num);
	ASSERT(10 == *(int*)list->head->data);
	ASSERT(NULL == list->head->next);
	ASSERT(1 == list->length);
};

void test_3_inserts_element_at_the_end_of_linked_list(){
	int value;
	Node *result1,*result2;
	list = create();
	value = 10;
	insertNode(list,0,&value);
	ASSERT(10 == *(int*)list->head->data);
	ASSERT(NULL == list->head->next);
	ASSERT(1 == list->length);

	value = 20;
	insertNode(list,1,&value);
	result1 = list->head->next;
	ASSERT(20 == *(int*)result1->data);
	ASSERT(NULL == result1->next);
	ASSERT(2 == list->length);

	value = 30;
	insertNode(list,2,&value);
	result2 = result1->next;
	ASSERT(30 == *(int*)result2->data);
	ASSERT(NULL == result2->next);
	ASSERT(3 == list->length);
};

void test_4_inserts_element_at_middle_of_linked_list(){
	Node *second,*third,*fourth;
	int* nums = malloc(sizeof(int)*4);
	nums[0] = 10;
	nums[1] = 20;
	nums[2] = 30;
	nums[3] = 40;
	list = create();
	insertNode(list,0,nums+0);
	ASSERT(1 == list->length);
	insertNode(list,1,nums+2);
	ASSERT(2 == list->length);
	insertNode(list,2,nums+3);
	ASSERT(3 == list->length);
	insertNode(list,1,nums+1);
	ASSERT(4 == list->length);
	second = list->head->next;
	third = second->next;
	fourth = third->next;
	ASSERT(10 == *(int*)list->head->data);
	ASSERT(30 == *(int*)second->data);
	ASSERT(20 == *(int*)third->data);
	ASSERT(40 == *(int*)fourth->data);
};

void test_5_inserts_multiple_elements_at_head_of_linked_list(){
	int* nums = malloc(sizeof(int)*3);
	list = create();
	nums[0] = 10;
	nums[1] = 20;
	nums[2] = 30;
	insertNode(list,0,nums);
	ASSERT(10 == *(int*)list->head->data);
	ASSERT(1 == list->length);
	insertNode(list,0,nums+1);
	ASSERT(20 == *(int*)list->head->data);
	ASSERT(2 == list->length);
	insertNode(list,0,nums+2);
	ASSERT(30 == *(int*)list->head->data);
	ASSERT(3 == list->length);
};

void test_6_inserts_double_element_in_the_linked_list(){
	double* nums = malloc(sizeof(double)*3);
	list = create();
	nums[0] = 1.0;
	nums[1] = 2.0;
	nums[2] = 3.0;
	insertNode(list,0,&nums[0]);
	ASSERT(1.0 == *(double*)list->head->data);
	ASSERT(1 == list->length);
	insertNode(list,1,&nums[1]);
	ASSERT(2.0 == *(double*)list->head->next->data);
	ASSERT(2 == list->length);
	insertNode(list,2,&nums[2]);
	ASSERT(3 == list->length);
};

void test_7_inserts_character_elements_in_the_linked_list(){
	char* chars = malloc(sizeof(char)*3);
	list = create();
	chars[0] = 'a';
	chars[1] = 'b';
	chars[2] = 'c';
	insertNode(list,0,&chars[0]);
	ASSERT('a' == *(char*)list->head->data);
	ASSERT(1 == list->length);
	insertNode(list,1,&chars[1]);
	ASSERT('b' == *(char*)list->head->next->data);
	ASSERT(2 == list->length);
	insertNode(list,2,&chars[2]);
	ASSERT(3 == list->length);
};

void test_8_inserts_the_string_elements_in_the_linked_list(){
    String* names = malloc(sizeof(String)*3);
    list = create();
    strcpy(names[0], "Kajal");
    strcpy(names[1], "Manali");
    strcpy(names[2], "Shital");
    insertNode(list, 0, &names[0]);
    ASSERT(0 == strcmp("Kajal",(char*)list->head->data));
    ASSERT(1 == list->length);
    insertNode(list, 1, &names[1]);
    ASSERT(0 == strcmp("Manali",(char*)list->head->next->data));
    ASSERT(2 == list->length);
    insertNode(list, 1, &names[2]);
    ASSERT(0 == strcmp("Manali",(char*)list->head->next->data));
    ASSERT(3 == list->length);
};

void test_9_inserts_the_structures_in_the_linked_list(){
    Account* accounts = malloc(sizeof(Account)*3);
    list = create();
    accounts[0].accountNo = 100; accounts[0].balance = 1000;
    accounts[1].accountNo = 101; accounts[1].balance = 2000;
    accounts[2].accountNo = 102; accounts[2].balance = 3000;
    insertNode(list,0,&accounts[0]);
    ASSERT(areAccountsEqual(accounts[0], *(Account*)list->head->data));
    ASSERT(1 == list->length);
    insertNode(list,1,&accounts[1]);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->data));
    ASSERT(2 == list->length);
    insertNode(list,1,&accounts[2]);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->data));
    ASSERT(3 == list->length);
};

void test_10_deletes_element_from_list_which_has_only_one_element(){
    int* nums = malloc(sizeof(int));
    *nums = 10;
    list = create();
    insertNode(list, 0, &nums);
    ASSERT(deleteNode(list, 0));
    ASSERT(0 == list->length);
    ASSERT(NULL == list->head);
};

void test_11_deletes_first_element_from_list_when_more_than_one_elements_are_there(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insertNode(list, 0,&nums[0]);
    insertNode(list, 1,&nums[1]);
    insertNode(list, 2,&nums[2]);
    ASSERT(3 == list->length);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(deleteNode(list, 0));
    ASSERT(2 == list->length);
    ASSERT(20 == *(int*)list->head->data);
};

void test_12_deletes_last_element_from_linked_list(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insertNode(list, 0,&nums[0]);
    insertNode(list, 1,&nums[1]);
    insertNode(list, 2,&nums[2]);
    ASSERT(deleteNode(list, 2));
    ASSERT(2 == list->length);
    ASSERT(NULL == list->head->next);
};

void test_13_deletes_element_in_between_of_linked_list(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insertNode(list,0,&nums[0]);
    insertNode(list,1,&nums[1]);
    insertNode(list,2,&nums[2]);
    ASSERT(deleteNode(list, 1));
    ASSERT(2 == list->length);
    ASSERT(30 == *(int*)list->head->data);
};

void test_fail(){
	ASSERT(0);
};
