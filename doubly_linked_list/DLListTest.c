#include "testUtils.h"
#include "DLList.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

DLList* list;

void tearDown(){
	free(list);
};

typedef char String[256];

typedef struct
{
    int accountNo;
    int balance;
} Account;

int areAccountsEqual(Account expected,Account actual){
    return expected.accountNo == actual.accountNo && expected.balance == actual.balance;
}

void test_1_gives_an_Doubly_link_list_with_head_NULL(){
    list = create();
    ASSERT(NULL == list->head);
    ASSERT(0 == list->length);
};

void test_2_creates_node(){
    Node expected = {NULL,NULL,NULL};
    Node *actual = createNode(NULL,NULL);
    ASSERT(expected.next == actual->next);
    ASSERT(expected.prev == actual->prev);
}

void test_3_inserts_an_element_at_head_of_link_list(){
    int* num = malloc(sizeof(int));
    list = create();
    *num = 10;
    insert(list, num, 0);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(NULL == list->head->prev);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
}

void test_4_inserts_an_element_at_the_end_of_linkList(){
    int* nums = malloc(sizeof(int)*3);
    Node *result1,*result2;
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insert(list, &nums[0], 0);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(NULL == list->head->prev);
    ASSERT(NULL == list->head->next);
    ASSERT(1 == list->length);
    insert(list, &nums[1], 1);
    result1 = list->head->next;
    ASSERT(20 == *(int*)result1->data);
    ASSERT(list->head == result1->prev);
    ASSERT(NULL == result1->next);
    ASSERT(2 == list->length);
    insert(list, &nums[2], 2);
    result2 = result1->next;
    ASSERT(30 == *(int*)result2->data);
    ASSERT(result1 == result2->prev);
    ASSERT(NULL == result2->next);
    ASSERT(3 == list->length);
};

void test_5_inserts_element_in_middle_of_link_List(){
    Node *second,*third,*fourth;
    int* nums = malloc(sizeof(int)*3);
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    nums[3] = 40;
    list = create();
    insert(list, nums+0, 0);
    ASSERT(1 == list->length);
    insert(list, nums+2, 1);
    ASSERT(2 == list->length);
    insert(list, nums+3, 2);
    ASSERT(3 == list->length);
    insert(list, nums+1, 1);
    ASSERT(4 == list->length);
    second = list->head->next;
    third = second->next;
    fourth = third->next;
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(20 == *(int*)second->data);
    ASSERT(30 == *(int*)third->data);
    ASSERT(40 == *(int*)fourth->data);
}

void test_6_inserts_multiple_element_as_the_head_of_link_list(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insert(list, nums, 0);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(1 == list->length);
    insert(list, nums+1, 0);
    ASSERT(20 == *(int*)list->head->data);
    ASSERT(NULL == list->head->prev);
    insert(list, nums+2, 0);
    ASSERT(30 == *(int*)list->head->data);
    ASSERT(3 == list->length);
}

void test_7_inserts_the_doubles_in_the_linklist(){
    double* nums = malloc(sizeof(double)*3);
    list = create();
    nums[0] = 1.0;
    nums[1] = 2.0; 
    nums[2] = 3.0;
    insert(list, &nums[0], 0);
    ASSERT(1.0 == *(double*)list->head->data);
    ASSERT(1 == list->length);
    insert(list, &nums[1], 1);
    ASSERT(2.0 == *(double*)list->head->next->data);
    ASSERT(2 == list->length);
    insert(list, &nums[2], 1);
    ASSERT(3.0 == *(double*)list->head->next->data);
    ASSERT(3 == list->length);
}
void test_8_inserts_the_characters_in_the_link_list(){
    char* chars = malloc(sizeof(char)*3);
    list = create();
    chars[0] = 'a';
    chars[1] = 'b'; 
    chars[2] = 'c';
    insert(list, &chars[0], 0);
    ASSERT('a' == *(char*)list->head->data);
    ASSERT(1 == list->length);
    insert(list, &chars[1], 1);
    ASSERT('b' == *(char*)list->head->next->data);
    ASSERT(2 == list->length);
    insert(list, &chars[2], 1);
    ASSERT('c' == *(char*)list->head->next->data);
    ASSERT(3 == list->length);
}
        
void test_9_inserts_the_strings_in_the_link_list(){
    String* names = malloc(sizeof(String)*3);
    list = create();
    strcpy(names[0], "Kajal");
    strcpy(names[1], "Manali");
    strcpy(names[2], "Shital");
    insert(list, &names[0], 0);
    ASSERT(0 == strcmp("Kajal",(char*)list->head->data));
    ASSERT(1 == list->length);
    insert(list, &names[1], 1);
    ASSERT(0 == strcmp("Manali",(char*)list->head->next->data));
    ASSERT(2 == list->length);
    insert(list, &names[2], 1);
    ASSERT(0 == strcmp("Shital",(char*)list->head->next->data));
    ASSERT(3 == list->length);
}

void test_10_inserts_the_structures_in_the_link_list(){
    Account* accounts = malloc(sizeof(Account)*3);
    list = create();
    accounts[0].accountNo = 100;accounts[0].balance = 1000;
    accounts[1].accountNo = 101;accounts[1].balance = 2000;
    accounts[2].accountNo = 102;accounts[2].balance = 4000;
    insert(list, &accounts[0], 0);
    ASSERT(areAccountsEqual(accounts[0], *(Account*)list->head->data));
    ASSERT(1 == list->length);
    insert(list, &accounts[1], 1);
    ASSERT(areAccountsEqual(accounts[1], *(Account*)list->head->next->data));
    ASSERT(2 == list->length);
    insert(list, &accounts[2], 1);
    ASSERT(areAccountsEqual(accounts[2], *(Account*)list->head->next->data));
    ASSERT(3 == list->length);
}

void test_11_deletes_element_in_list_which_has_one_element(){
    int* nums = malloc(sizeof(int));
    *nums = 5;
    list = create();
    insert(list, nums, 0);
    ASSERT(deleteNode(list, 0));
    ASSERT(0 == list->length);
    ASSERT(NULL == list->head);
}

void test_12_deletes_first_element_in_list_when_more_than_one_elements_are_there(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insert(list,&nums[0], 0);
    insert(list,&nums[1], 1);
    insert(list,&nums[2], 2);
    ASSERT(3 == list->length);
    ASSERT(10 == *(int*)list->head->data);
    ASSERT(deleteNode(list, 0));
    ASSERT(2 == list->length);
    ASSERT(20 == *(int*)list->head->data);
}

void test_13_deletes_last_element_in_the_link_List(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insert(list,&nums[0], 0);
    insert(list,&nums[1], 1);
    insert(list,&nums[2], 2);
    ASSERT(deleteNode(list, 2));
    ASSERT(2 == list->length);
    ASSERT(NULL == list->head->next->next);
}
void test_14_deletes_element_in_between_of_link_list(){
    int* nums = malloc(sizeof(int)*3);
    list = create();
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;
    insert(list,&nums[0], 0);
    insert(list,&nums[1], 1);
    insert(list,&nums[2], 2);
    ASSERT(deleteNode(list, 1));
    ASSERT(2 == list->length);
    ASSERT(30 == *(int*)list->head->next->data);
}

void test_fail(){
	ASSERT(0);
}
