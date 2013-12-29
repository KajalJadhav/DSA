#include "testUtils.h"
#include "merge_sort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void* a, void* b){
    return (*(int*)a < *(int*)b);
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
    int actual[8] = {1,8,3,5,4,6,7,2};
    int expected[8] = {1,2,3,4,5,6,7,8};
    int i;
    mergeSort(actual, 0, 7,sizeof(int),compareInts);
    for (i = 0; i < 8; ++i){
        ASSERT(expected[i] == actual[i]);
    }
}

void test_fail(){
	ASSERT(0);
}
