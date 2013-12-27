#include "testUtils.h"
#include "bubble_sort.h"
#include "customType.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void* a, void* b){
    return (*(int*)a - *(int*)b);
}

int compareFloats(void* a, void* b){
	return (*(float*)a - *(float*)b);
}

int compareDoubles(void* a, void* b){
    return (*(double*)a - *(double*)b);
}

int compareChars(void* a, void* b){
    return (*(char*)a - *(char*)b);
}

int compareStrings(void* a,void* b){
    return (strcmp(*(String*)a,*(String*)b));
}

void test_sorts_an_array_of_integers(){
    int expected[] = {1,2,3,4,6,10};
    int actual[] = {4,3,1,2,6,10};
    bubbleSort(actual, 6, sizeof(int), compareInts);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_integers_which_are_already_sorted(){
    int expected[] = {1,2,3,4,6,10};
    int actual[] = {1,2,3,4,6,10};
    bubbleSort(actual, 6, sizeof(int), compareInts);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_floats(){
    float expected[] = {1.0,2.0,3.0,4.0};
    float actual[] = {4.0,3.0,1.0,2.0};
    bubbleSort(actual, 4, sizeof(float), compareFloats);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_floats_which_are_already_sorted(){
    float expected[] = {1.0,2.0,3.0,4.0,6.0,10.0};
    float actual[] = {1.0,2.0,3.0,4.0,6.0,10.0};
    bubbleSort(actual, 6, sizeof(float), compareFloats);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_doubles(){
    double expected[] = {1.000000,2.000000,3.000000,4.000000};
    double actual[] = {4.000000,3.000000,2.000000,1.000000};
    bubbleSort(actual, 4, sizeof(double), compareDoubles);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_doubles_which_are_already_sorted(){
    double expected[] = {1.000000,2.000000,3.0000000,4.000000};
    double actual[] = {1.000000,2.000000,3.000000,4.000000};
    bubbleSort(actual, 4, sizeof(double), compareDoubles);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_characters(){
    char expected[] = {'d','k','m','s'};
    char actual[] = {'s','m','k','d'};
    bubbleSort(actual, 4, sizeof(char), compareChars);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_characters_which_are_already_sorted(){
    char expected[] = {'a','b','c','d'};
    char actual[] = {'a','b','c','d'};
    bubbleSort(actual, 4, sizeof(char), compareChars);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_strings(){
    String expected[] = {"digvijay","kajal","manali","taj"};
    String actual[] = {"taj","manali","kajal","digvijay"};
    bubbleSort(actual, 4, sizeof(String), compareStrings);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}

void test_sorts_an_array_of_strings_which_are_already_sorted(){
    String expected[] = {"digvijay","kajal","manali","taj"};
    String actual[] ={"digvijay","kajal","manali","taj"};
    bubbleSort(actual, 4, sizeof(String), compareStrings);
    ASSERT(0 == memcmp(expected, actual, sizeof(expected)));
}
