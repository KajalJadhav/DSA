#include "testUtils.h"
#include "os-scheduler.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Scheduler *q;

void tearDown(){
    free(q);
}

int compareInt(void* a , void* b){
    return (*(int*)a - *(int*)b);
}

void test_1_creates_a_new_process(){
    Scheduler expected = {NULL,0};
    q = create();
    ASSERT(q->front == expected.front);
    ASSERT(q->length == expected.length);
}

void test_2_adds_front_process(){
    Scheduler expected = {NULL,0};
    Status status = {0,1,0};
    Process firstProcess = {"firstProcess",3000,status,10,NULL};
    q = create();
    ASSERT(1 == insertProcess(q, &firstProcess,compareInt));
    ASSERT(q->front == &firstProcess);
    ASSERT(q->front->next == NULL);
}

void test_3_adds_process_that_have_high_priority_rather_than_first(){
    Scheduler expected = {NULL,0};
    Status status = {0,1,0};
    Process firstProcess = {"firstProcess",3000,status,7,NULL};
    Process secondProcess = {"secondProcess",900,status,1,NULL};
    q = create();
    ASSERT(1 == insertProcess(q, &firstProcess,compareInt));
    ASSERT(2 == insertProcess(q, &secondProcess,compareInt));
    ASSERT(q->front == &secondProcess);
    ASSERT(q->front->next == &firstProcess);
}

void test_4_adds_process_with_priority_in_between_process_queue(){
    Scheduler expected = {NULL,0};
    Status status = {0,1,0};
    Process *second,*third;
    Process firstProcess = {"First Process",3000,status,7,NULL};
    Process secondProcess = {"Second Process",900,status,1,NULL};
    Process thirdProcess = {"Third Process",400,status,2,NULL};
    q = create();
    ASSERT(1 == insertProcess(q, &firstProcess,compareInt));
    ASSERT(2 == insertProcess(q, &secondProcess,compareInt));
    ASSERT(3 == insertProcess(q, &thirdProcess,compareInt));
    ASSERT(q->front == &secondProcess);
    second = q->front->next;
    third = second->next;
    ASSERT(second == &thirdProcess);
    ASSERT(third == &firstProcess);
    ASSERT(third->next == NULL);
}

void test_5_adds_process_with_very_low_priority(){
    Status statusp1 = {0,1,0};
    Process *second,*third,*fourth,*fifth;
    Process process1 = {"process1",1000,statusp1,5,NULL};
    Process process2 = {"process2",500,statusp1,1,NULL};
    Process process3 = {"process3",400,statusp1,3,NULL};
    Process process4 = {"process4",400,statusp1,2,NULL};
    Process process5 = {"pprocess5",400,statusp1,8,NULL};
    q = create();
    ASSERT(1 == insertProcess(q, &process1,compareInt));
    ASSERT(2 == insertProcess(q, &process2,compareInt));
    ASSERT(3 == insertProcess(q, &process3,compareInt));
    ASSERT(4 == insertProcess(q, &process4,compareInt));
    ASSERT(5 == insertProcess(q, &process5,compareInt));
    second = q->front->next;
    third = second->next;
    fourth = third->next;
    fifth = fourth->next;
    ASSERT(fifth == &process5);
    ASSERT(NULL == fifth->next);
}

void test_6_removes_first_which_is_only_process(){
    Status statusp1 = {0,1,0};
    Process process1 = {"process1",0,statusp1,5,NULL};
    q = create();
    insertProcess(q, &process1,compareInt);
    ASSERT(0 == removeProcess(q));
    ASSERT(NULL == q->front);
}

void test_7_removes_processes_in_middle(){
    Status statusp1 = {0,1,0};
    Process process1 = {"process1",1000,statusp1,1,NULL};
    Process process2 = {"process2",0,statusp1,5,NULL};
    Process process3 = {"process3",1000,statusp1,7,NULL};
    q = create();
    insertProcess(q, &process1,compareInt);
    insertProcess(q, &process2,compareInt);
    insertProcess(q, &process3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front->next == &process3);
}

void test_8_removes_last_process(){
    Status statusp1 = {0,1,0};
    Process process1 = {"process1",1000,statusp1,1,NULL};
    Process process2 = {"process2",10,statusp1,5,NULL};
    Process process3 = {"process3",0,statusp1,7,NULL};
    q = create();
    insertProcess(q, &process1,compareInt);
    insertProcess(q, &process2,compareInt);
    insertProcess(q, &process3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front->next->next == NULL);
}

void test_9_removes_first_process_in_many(){
    Status statusp1 = {0,1,0};
    Process process1 = {"process1",0,statusp1,1,NULL};
    Process process2 = {"process2",10,statusp1,5,NULL};
    Process process3 = {"process3",65,statusp1,7,NULL};
    q = create();
    insertProcess(q, &process1,compareInt);
    insertProcess(q, &process2,compareInt);
    insertProcess(q, &process3,compareInt);
    ASSERT(2 == removeProcess(q));
    ASSERT(q->front == &process2);
}

void test_fail(){
    ASSERT(0);
}