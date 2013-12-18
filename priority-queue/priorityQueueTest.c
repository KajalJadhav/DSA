#include "testUtils.h"
#include "priorityQueue.h"
#include "customType.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void* queue;

void setup(){
    queue = createQueue();    
};

void tearDown(){
    free(queue);
};

int compareInt(void* element1,void* element2){
    return (*(int*)element1 - *(int*)element2);
}

void test_1_enqueues_an_integer_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    int value = 10;
    ASSERT(1 == enqueue(queue, &value,30,compareInt));
    ASSERT(value == *(int*)dequeue(queue));
};

void test_2_enqueues_the_integer_elements_in_queue_and_dequeue_the_top_element(){
    int value[] = {10,15};
    ASSERT(1 == enqueue(queue, &value[0],30,compareInt));
    ASSERT(1 == enqueue(queue, &value[1],20,compareInt));
    ASSERT(value[1] == *(int*)dequeue(queue));
};

void test_3_enqueues_an_float_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    float value = 10.0;
    ASSERT(1 == enqueue(queue, &value,30,compareInt));
    ASSERT(value == *(float*)dequeue(queue));
};

void test_4_enqueues_the_float_elements_in_queue_and_dequeue_the_element_with_lowest_priority(){
    float value[] = {10.0,20.0};
    enqueue(queue, &value[0],30,compareInt);
    enqueue(queue, &value[1],20,compareInt);
    ASSERT(value[1] == *(float*)dequeue(queue));
};

void test_5_enqueues_an_double_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    double value = 10.0;
    enqueue(queue, &value,30,compareInt);
    ASSERT(value == *(double*)dequeue(queue));
};

void test_6_enqueues_the_double_elements_in_queue_and_dequeue_the_element_with_lowest_priority(){
    double value1 = 10.0;
    double value2 = 20.0;
    enqueue(queue, &value1,30,compareInt);
    enqueue(queue, &value2,40,compareInt);
    ASSERT(value2 == *(double*)dequeue(queue));
};

void test_7_enqueues_an_character_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    char value = 'k';
    enqueue(queue, &value,30,compareInt);
    ASSERT(value == *(char*)dequeue(queue));
};

void test_8_enqueues_the_characters_elements_in_queue_and_dequeue_the_top_element(){
    char value1 = 'k';
    char value2 = 'a';
    enqueue(queue, &value1,30,compareInt);
    enqueue(queue, &value2,40,compareInt);
    ASSERT(value2 == *(char*)dequeue(queue));
};

void test_9_enqueues_an_String_element_in_empty_queue_and_gives_back_that_element_when_dequeued(){
    String value = "Kajal";
    enqueue(queue, &value,30,compareInt);
    ASSERT(0 == strcmp(value,*(String*)dequeue(queue)));
};

void test_10_enqueues_the_String_elements_in_queue_and_dequeue_the_top_element(){
    String value1 = "Kajal";
    String value2 = "Komal";
    enqueue(queue, &value1,30,compareInt);
    enqueue(queue, &value2,40,compareInt);
    ASSERT(value2 == *(String*)dequeue(queue));
};