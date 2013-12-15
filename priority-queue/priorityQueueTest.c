#include "testUtils.h"
#include "priorityQueue.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}

List *q;

void tearDown(){
    free(q);
}

void test_1_creates_a_new_process(){
    List expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
};

void test_2_adds_first_element_in_queue_of_integer(){
    int value = 10;
    Queue firstNode = {&value,30,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(q->front == &firstNode);
    ASSERT(q->front->next == NULL);
};

void test_3_adds_first_element_in_queue_of_float(){
    float value = 10.0;
    Queue firstNode = {&value,30,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(q->front == &firstNode);
    ASSERT(q->front->next == NULL);
};

void test_4_adds_first_element_in_queue_of_double(){
    double value = 100.0;
    Queue firstNode = {&value,30,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(q->front == &firstNode);
    ASSERT(q->front->next == NULL);
};

void test_5_adds_first_element_in_queue_of_characters(){
    char value = 'a';
    Queue firstNode = {&value,30,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(q->front == &firstNode);
    ASSERT(q->front->next == NULL);
};

void test_6_adds_first_element_in_queue_of_string(){
    String value = "Kajal";
    Queue firstNode = {&value,30,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(q->front == &firstNode);
    ASSERT(q->front->next == NULL);
};

void test_7_adds_element_of_high_priority_rather_than_first_for_integer(){
    int value[] = {10,20};
    List expected = {NULL,0};
    Queue firstNode = {&value[0],30,NULL};
    Queue secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(q->front == &secondNode);
    ASSERT(q->front->next == &firstNode);
};

void test_8_adds_element_of_high_priority_rather_than_first_for_float(){
    float value[] = {20.0,10.0};
    List expected = {NULL,0};
    Queue firstNode = {&value[0],30,NULL};
    Queue secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(q->front == &secondNode);
    ASSERT(q->front->next == &firstNode);
};

void test_9_adds_element_of_high_priority_rather_than_first_for_character(){
    char value[] = {'a','b'};
    List expected = {NULL,0};
    Queue firstNode = {&value[0],30,NULL};
    Queue secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(q->front == &secondNode);
    ASSERT(q->front->next == &firstNode);
};

void test_10_adds_element_of_high_priority_rather_than_first_for_string(){
    String value[] = {"Kajal","Komal"};
    List expected = {NULL,0};
    Queue firstNode = {&value[0],30,NULL};
    Queue secondNode = {&value[1],20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(q->front == &secondNode);
    ASSERT(q->front->next == &firstNode);
};

void test_11_adds_element_of_priority_in_between_for_integer_queue(){
    int value = 10;
    List expected = {NULL,0};
    Queue *second,*third;
    Queue firstNode = {&value,40,NULL};
    Queue secondNode = {&value,30,NULL};
    Queue thirdNode = {&value,20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(3 == insertElement(q, &thirdNode,compareInt));
    ASSERT(q->front == &thirdNode);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &secondNode);
    ASSERT(third == &firstNode);
    ASSERT(third->next == NULL);
};

void test_12_adds_element_of_priority_in_between_for_character_queue(){
    char value[] = {'a','b','c'};
    List expected = {NULL,0};
    Queue *second,*third;
    Queue firstNode = {&value,40,NULL};
    Queue secondNode = {&value,30,NULL};
    Queue thirdNode = {&value,20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(3 == insertElement(q, &thirdNode,compareInt));
    ASSERT(q->front == &thirdNode);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &secondNode);
    ASSERT(third == &firstNode);
    ASSERT(third->next == NULL);
};

void test_13_removes_element_as_per_given_priority(){
    int value[] = {10,20,30};
    Queue *second,*third;
    Queue firstNode = {&value[0],40,NULL};
    Queue secondNode = {&value[1],30,NULL};
    Queue thirdNode = {&value[2],20,NULL};
    q = create();
    ASSERT(1 == insertElement(q, &firstNode,compareInt));
    ASSERT(2 == insertElement(q, &secondNode,compareInt));
    ASSERT(3 == insertElement(q, &thirdNode,compareInt));
    ASSERT(q->front == &thirdNode);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &secondNode);
    ASSERT(third == &firstNode);
    ASSERT(third->next == NULL);
    ASSERT(0 == removeElement(q));
    ASSERT(20 == *(int*)q->front->data);
    ASSERT(q->length == 2);
    ASSERT(0 == removeElement(q));
    ASSERT(10 == *(int*)q->front->data);
    ASSERT(q->length == 1);
    ASSERT(0 == removeElement(q));
};

void test_14_cannot_remove_an_element_from_empty_queue(){
    q = create();
    ASSERT(1 == removeElement(q));
};

void test_fail(){
	ASSERT(0);
};