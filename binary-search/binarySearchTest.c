#include "testUtils.h"
#include "binarySearch.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

// --------------------------- Compare Functions ------------------------------------

int compareInteger (void* a, void* b){
    return (*(int*)a - *(int*)b);
}
int compareDouble (void* a, void* b){
    return (*(double*)a - *(double*)b);
}
int compareString(void *a, void *b){ 
    return (strcmp((char *)a,(char *)b));
}
int compareCharacter(void* a, void* b){
    return (*(char*)a - *(char*)b);
}

//-------------------------------------------------------------------------------------

void test_1_searches_8_in_integer_array(){
    int elements[5] = {4,6,7,8,2};
    int key = 8;
    int* result = bSearch(elements,&key, 5, sizeof(int), compareInteger);
    ASSERT(8 == *result);
    ASSERT(&elements[3] == result);
};

void test_2_searches_9_in_integer_array_which_is_not_present(){
    int elements[5] = {4,6,7,8,2};
    int key = 9;
    int* result = bSearch(elements,&key, 5, sizeof(int), compareInteger);
    ASSERT((int*)result == NULL);
};

void test_3_searches_1st_element_in_integer_array(){
    int elements[5] = {4,6};
    int key = 4;
    int* result = bSearch(elements,&key, 2, sizeof(int), compareInteger);
    ASSERT(4 == *result);
    ASSERT(&elements[0] == result);
};

void test_4_searches_middle_element_in_integer_array(){
    int elements[5] = {4,6,7,8,2};
    int key = 7;
    int* result = bSearch(elements,&key, 5, sizeof(int), compareInteger);
    ASSERT(7 == *result);
    ASSERT(&elements[2] == result);
};

void test_5_searches_last_element_in_integer_array(){
    int elements[] = {4,6,7,8,9};
    int key = 9;
    int* result = bSearch(elements,&key, 5, sizeof(int), compareInteger);
    ASSERT(9 == *result);
    ASSERT(&elements[4] == result);
};

void test_6_searches_element_in_float_array(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 6.4f;
    float* result = bSearch(elements,&key, 5, sizeof(float), compareInteger);
    ASSERT(6.4f == *result);
    ASSERT(&elements[1] == result);
};

void test_7_searches_element_in_float_array_which_is_not_present(){
    float elements[5] = {4.7f,6.4f,7.3f,8.5f,2.2f};
    float key = 4.6f;
    float* result = bSearch(elements,&key, 5, sizeof(float), compareInteger);
    ASSERT(NULL == (float*)result);
};

void test_8_searches_element_in_double_array(){
    double elements[5] = {1.0,2.0,3.0,4.0,5.0};
    double key = 3.0;
    double* result = bSearch(elements,&key, 5, sizeof(double), compareDouble);
    ASSERT(3.0 == *result);
    ASSERT(&elements[2] == result);
};

void test_9_searches_a_in_character_array(){
    char elements[5] = {'k','a','j','a','l'};
    char key = 'a';
    char* result = bSearch(elements,&key, 3, sizeof(char), compareCharacter);
    ASSERT('a' == *result);
    ASSERT(&elements[1] == result);
};

void test_10_searches_m_in_character_array_which_is_not_present(){
    char elements[5] = {'k','a','j','a','l'};
    char key = 'm';
    char* result = bSearch(elements,&key, 3, sizeof(char), compareCharacter);
    ASSERT(NULL == (char*)result);
};

void test_11_searches_first_element_in_character_array_with_similar_characters(){
    char elements[5] = {'k','k','k','k','k'};
    char key = 'k';
    char* result = bSearch(elements,&key, 2, sizeof(char), compareCharacter);
    ASSERT('k' == *result);
    ASSERT(&elements[0] == result);
};

void test_12_searches_last_element_in_character_array_with_similar_and_diiferent_charaters(){
    char elements[3] = {'m','m','a'};
    char key = 'm';
    char* result = bSearch(elements,&key, 3, sizeof(char), compareCharacter);
    ASSERT('m' == *result);
    ASSERT(&elements[1] == result);
};

void test_13_searches_kajal_in_String_array(){
    String elements[3] = {"kajal","kashish","komal"};
    String key = "kajal";
    String* result = bSearch(elements,&key, 3, sizeof(String), compareString);
    ASSERT(!(strcmp("kajal",*result)));
    ASSERT(&elements[0] == result);
};

void test_14_searches_shital_in_String_array_which_is_not_present(){
    String elements[3] = {"kajal","kashish","komal"};
    String key = "shital";
    String* result = bSearch(elements,&key, 3, sizeof(String), compareString);
    ASSERT(NULL == (String*)result);
};

void test_fail(){
	ASSERT(0);
}
