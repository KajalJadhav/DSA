#include "testUtils.h"
#include "stack_without_memcpy.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int areEqual(stack* src,stack* expected){
    int res = (src->elementsSize == expected->elementsSize)
            && (src->size == expected->size)
            && (src->top == expected->top);
            if(!res)
                return res;
            return 0==memcmp(src->elements, expected->elements, src->size*src->elementsSize);           
};

void test_1_creates_stack(){
    int expectedArr[2] = {0,0};
    stack expected = {expectedArr,-1,4,2};
    stack* src = create(sizeof(int),2);
    ASSERT(areEqual(src, &expected));
}

void test_2_pushes_integer_element_in_stack(){
    stack* actual = create(sizeof(int),2);
    int value = 1;
    int res = push(actual,&value);
    int* data = (int*)actual->elements;
    ASSERT(data[0] == 1);
    free(actual);   
}

void test_3_pushes_float_element_in_stack(){
    stack* actual = create(sizeof(float),2);
    float value = 1.0;
    int res = push(actual,&value);
    float* data = (float*)actual->elements;
    ASSERT(data[0] == 1.0);
    free(actual);   
}

void test_4_pushes_character_element_in_stack(){
    stack* actual = create(sizeof(char),2);
    char value = 'k';
    int res = push(actual,&value);
    char* data = (char*)actual->elements;
    ASSERT(data[0]=='k');
    free(actual);   
}

void test_5_pushes_double_element_in_stack(){
    stack* actual = create(sizeof(double),2);
    double value = 2.000000;
    double res = push(actual,&value);
    double* data = (double*)actual->elements;
    ASSERT(data[0] == 2.000000);
    free(actual);   
}

void test_6_pushes_String_element_in_stack(){
    stack* actual = create(sizeof(String),2);
    String value = "kajal";
    int res = push(actual,&value);
    String* data = (String*)actual->elements;
    ASSERT(0 == strcmp((char*)data,value));
    free(actual);   
}

void test_7_pops_integer_element_from_stack(){
    int data[] = {1,2,3,4,5};
    stack* actual = create(sizeof(int),5);
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    push(actual,&data[3]);
    push(actual,&data[4]);
    ASSERT(data[0] == 1);
    ASSERT(data[1] == 2);
    ASSERT(data[2] == 3);
    ASSERT(data[3] == 4);
    ASSERT(data[4] == 5);
    ASSERT(5 ==*(int*)pop(actual));
    ASSERT(4 ==*(int*)pop(actual));
}

void test_8_pops_float_element_from_stack(){
    stack* actual = create(sizeof(float),3);
    float data[] = {1.0,2.0,3.0};
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(data[0] == 1.0);
    ASSERT(data[1] == 2.0);
    ASSERT(data[2] == 3.0);
    ASSERT(3.0 ==*(float*)pop(actual));
}

void test_9_pops_character_element_from_stack(){
    stack* actual = create(sizeof(char),5);
    char data[] = {'k','a','j','a','l'};
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    push(actual,&data[3]);
    push(actual,&data[4]);
    ASSERT(data[0] == 'k');
    ASSERT(data[1] == 'a');
    ASSERT(data[2] == 'j');
    ASSERT(data[3] == 'a');
    ASSERT(data[4] == 'l');
    ASSERT('l' ==*(char*)pop(actual));
}

void test_10_pops_double_element_from_stack(){
    stack* actual = create(sizeof(double),3);
    double data[] = {1.000000,2.000000,3.00000};
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(data[0] == 1.000000);
    ASSERT(data[1] == 2.000000);
    ASSERT(data[2] == 3.000000);
    ASSERT(3.000000 ==*(double*)pop(actual));
}

void test_11_pops_string_element_from_stack(){
    stack* actual = create(sizeof(String),3);
    String data[] = {"manali","samiksha","kajal"};
    push(actual,&data[0]);
    push(actual,&data[1]);
    push(actual,&data[2]);
    ASSERT(strcpy(data[0],"manali"));
    ASSERT(strcpy(data[1],"samiksha"));
    ASSERT(strcpy(data[2],"kajal"));
    ASSERT(0 == strcmp("kajal",*(String*)pop(actual)));
}

void test_12_gives_top_integer_element_of_stack(){
    stack* actual = create(sizeof(int),3);
    int* data = actual->elements;
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    actual->top = 2;
    ASSERT(3 ==*(int*)top(actual));
}

void test_13_gives_top_float_element_of_stack(){
    stack* actual = create(sizeof(float),3);
    float* data = actual->elements;
    data[0] = 1.0;
    data[1] = 2.0;
    data[2] = 3.0;
    actual->top = 2;
    ASSERT(3.0 ==*(float*)top(actual));
}

void test_14_gives_top_double_element_of_stack(){
    stack* actual = create(sizeof(double),3);
    double* data = actual->elements;
    data[0] = 1.000000;
    data[1] = 2.000000;
    data[2] = 3.000000;
    actual->top = 2;
    ASSERT(3.000000 ==*(double*)top(actual));
}

void test_15_gives_top_character_element_of_stack(){
    stack* actual = create(sizeof(char),5);
    char* data = actual->elements;
    data[0] = 'k';
    data[1] = 'a';
    data[2] = 'j';
    data[3] = 'a';
    data[4] = 'l';
    actual->top = 4;
    ASSERT('l' ==*(char*)top(actual));
}

void test_16_gives_top_string_element_of_stack(){
    stack* actual = create(sizeof(String),3);
    String* data = actual->elements;
    strcpy(data[0],"manali");
    strcpy(data[1],"samiksha");
    strcpy(data[2],"kajal");
    actual->top = 2;
    ASSERT(0 == strcmp("kajal",*(String*)top(actual)));
}

void test_fail(){
	ASSERT(0);
}
