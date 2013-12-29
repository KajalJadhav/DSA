#include "testUtils.h"
#include "merge_sort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void* a, void* b){
    return (*(int*)a < *(int*)b);
}

int compareFloats(void* a, void* b){
    return (*(float*)a < *(float*)b);
}

int compareDoubles(void* a, void* b){
    return (*(double*)a < *(double*)b);
}

void test_sorts_an_array_of_integers(){
    int actual[8] = {1,4,3,8,6,7,2,5};
    int expected[8] = {1,2,3,4,5,6,7,8};
    int i;
    mergeSort(actual, 0, 7,sizeof(int),compareInts);
    for (i = 0; i < 8; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}

void test_sorts_an_array_of_integers_which_is_already_sorted(){
    int actual[8] = {1,2,3,4,5,6,7,8};
    int expected[8] = {1,2,3,4,5,6,7,8};
    int i;
    mergeSort(actual, 0, 7,sizeof(int),compareInts);
    for (i = 0; i < 8; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}

void test_sorts_an_array_of_floats(){
    float actual[8] = {1.0,4.0,3.0,8.0,6.0,7.0,2.0,5.0};
    float expected[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    int i;
    mergeSort(actual, 0, 7,sizeof(float),compareFloats);
    for (i = 0; i < 8; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}

void test_sorts_an_array_of_floats_which_is_already_sorted(){
    float actual[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    float expected[8] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0};
    int i;
    mergeSort(actual, 0, 7,sizeof(float),compareFloats);
    for (i = 0; i < 8; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}

void test_sorts_an_array_of_doubles(){
    double actual[6] = {1.000000,4.000000,3.000000,8.000000,6.000000,7.000000};
    double expected[6] = {1.000000,3.000000,4.000000,6.000000,7.000000,8.000000};
    int i;
    mergeSort(actual, 0, 5,sizeof(double),compareDoubles);
    for (i = 0; i < 6; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}

void test_sorts_an_array_of_doubles_which_is_already_sorted(){
    double actual[6] = {1.000000,2.000000,3.000000,4.000000,5.000000,6.000000};
    double expected[6] = {1.000000,2.000000,3.000000,4.000000,5.000000,6.000000};
    int i;
    mergeSort(actual, 0, 5,sizeof(double),compareDoubles);
    for (i = 0; i < 6; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}