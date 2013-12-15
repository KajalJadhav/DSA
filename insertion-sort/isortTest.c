#include "testUtils.h"
#include "isort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef char String[256];

int compareInt (void* a, void* b){
    return (*(int*)a - *(int*)b);
}

int compareDoubles(void* a, void* b){
    return (*(double*)a - *(double*)b);
}

int compareChars(void* a, void* b){
    return (*(char*)a - *(char*)b);
}

int compareStrings(void* a, void* b){
    return strcmp((char*)a, (char*)b);
}

int areArrayEqual(void* a,void* b, int length, int size){
    return 0 == memcmp(a, b, length*size);
}

//************************************************************************************

void test_1_sorts_collections_of_Integers(){
    int nums[5] = {30,20,10,40,50};
    int expected[5] = {10,20,30,40,50};
    isort(nums, 5, sizeof(int), compareInt);
    ASSERT(areArrayEqual(nums, expected, 5, sizeof(int)));
}

void test_2_sorts_collections_of_Doubles(){
    double nums[5] = {1.0,2.0,5.0,3.0,7.0};
    double expected[5] = {1.0,2.0,3.0,5.0,7.0};
    isort(nums, 5, sizeof(double), compareDoubles);
    ASSERT(areArrayEqual(nums, expected, 5, sizeof(double)));
}

void test_3_sorts_collections_of_Characters(){
    char chars[5] = {'e','a','d','c','b'};
    char expected[5] = {'a','b','c','d','e'};
    isort(chars, 5, sizeof(char), compareChars);
    ASSERT(areArrayEqual(chars, expected, 5, sizeof(char)));
}

void test_4_sorts_collections_of_String(){
    String names[5] = {"kajal","laxit","anant","jadhav","vaidehi"};
    String expected[5] = {"anant","jadhav","kajal","laxit","vaidehi"};
    isort(names, 5, sizeof(String), compareStrings);
    ASSERT(areArrayEqual(names, expected, 5, sizeof(String)));
}

void test_fail(){
	ASSERT(0);
}
