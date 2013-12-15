#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(Queue* src,Queue* expected){
	int res = (src->capacity == expected->capacity)
		&& (src->size == expected->size)
		&& (src->rear == expected->rear);
		if(!res)
			return res;
		return 0 == memcmp(src->elements, expected->elements, src->size*src->capacity);			
}

void test_create_queue_for_integer_value(){
	int expectedArr[2]={0,0};
	Queue expected = {2,sizeof(int),-1,expectedArr};
	Queue* src = create(2,sizeof(int));
	ASSERT(areEqual(src, &expected));
}

void test_create_queue_for_float_value(){
	float expectedArr[2]={0.0,0.0};
	Queue expected = {2,sizeof(float),-1,expectedArr};
	Queue* src = create(2,sizeof(float));
	ASSERT(areEqual(src, &expected));
}

void test_create_queue_for_character_value(){
	char expectedArr[2]={0,0};
	Queue expected = {2,sizeof(char),-1,expectedArr};
	Queue* src = create(2,sizeof(char));
	ASSERT(areEqual(src, &expected));
}

void test_create_queue_for_String_value(){
	String expectedArr[2]={0,0};
	Queue expected = {2,sizeof(String),-1,expectedArr};
	Queue* src = create(2,sizeof(String));
	ASSERT(areEqual(src, &expected));
}

void test_create_queue_for_double_value(){
	double expectedArr[2]={0.0,0.0};
	Queue expected = {2,sizeof(double),-1,expectedArr};
	Queue* src = create(2,sizeof(double));
	ASSERT(areEqual(src, &expected));
}

void test_for_enqueing_integer_element_in_queue(){
	Queue* actual = create(2,sizeof(int));
	int value = 1;
	bool res = enqueue(actual,&value);
	int* data = (int*)actual->elements;
	ASSERT(data[0] == 1);
	free(actual);
}

void test_for_enqueing_float_element_in_queue(){
	Queue* actual = create(2,sizeof(float));
	float value = 89.0;
	float* data;
	int res = enqueue(actual,&value);
	data = (float*)actual->elements;
	ASSERT(data[0] == 89.0);
	free(actual);
}

void test_for_enqueing_double_element_in_queue(){
	Queue* actual = create(2,sizeof(double));
	double value = 89.0;
	double* data;
	int res = enqueue(actual,&value);
	data = (double*)actual->elements;
	ASSERT(data[0] == 89.0);
	free(actual);
}

void test_for_enqueing_string_element_in_queue(){
	Queue* actual = create(2,sizeof(String));
	String value = "shital";
	String* data;
	int res = enqueue(actual,&value);
	data = (String*)actual->elements;
	ASSERT(0 == strcmp(data[0], "shital"));
	free(actual);
}

void test_for_enqueing_character_element_in_queue(){
	Queue* actual = create(2,sizeof(char));
	char value = 'A';
	char* data;
	int res = enqueue(actual,&value);
	data = (char*)actual->elements;
	ASSERT(data[0] == 'A');
	free(actual);
}

void test_for_dequeueing_integer_element_from_queue(){
	Queue* actual = create(sizeof(int),5);
	void* result;
	int value = 3;
	int value1 = 4;
	int* data;
	enqueue(actual, &value);
	enqueue(actual, &value1);
	result = (int*)dequeue(actual);
	data = (int*)actual->elements;
	ASSERT(data[0] == 4);
	ASSERT(*(int*)result == 3);
	ASSERT(actual->rear == 0);
	free(actual);
}

void test_for_dequeueing_float_element_from_queue(){
	Queue* actual = create(sizeof(float),5);
	float value = 3;
	void* result;
	float* data;
	float value1 = 4;
	enqueue(actual, &value);
	enqueue(actual, &value1);
	result = (float*)dequeue(actual);
	data = (float*)actual->elements;
	ASSERT(data[0] == 4);
	ASSERT(*(float*)result == 3);
	ASSERT(actual->rear == 0);
}

// void test_deQueues_string_elememt_from_queue_12(){
// 	void* rearElement;
// 	String a[3]={"sumit"};
// 	String s ="sumit";
// 	String d = "suraj";
// 	Queue* actual = create(sizeof(String),3);
// 	Queue expected = {3,sizeof(String),2,a};
// 	enqueue(actual,&s);
// 	enqueue(actual,&d);
// 	rearElement = dequeue(actual);
// 	printf("kfdlsfjl:%s:hjds\n",rearElement);
// 	ASSERT(0 == strcmp(s,*(String*)rearElement));
// }

// void test_for_non_dequeueing_float_element_from_queue(){
// 	Queue* actual = create(sizeof(float),5);
// 	void* result;
// 	result = dequeue(actual);
// 	ASSERT(result == 1);
// }

// void test_for_non_enqueueing_float_element_from_queue(){
// 	Queue* actual = create(sizeof(float),4);
// 	bool result;
// 	float value = 5;
// 	actual->rear = 3;
// 	result = enqueue(actual,&value);
// 	printf("%d\n", result);
// 	ASSERT(result == 1);
// }

void test_fail(){
	ASSERT(0);
}
