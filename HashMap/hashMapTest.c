#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

const int SUCCESS = 1;
const int FAIL = 0;

int compareKeys(void* one,void* two){
    return *(int*)one - *(int*)two;
}

int keyGenerator(void* key){
	return *(int*)key;
}

void test_put_one_element_into_hashmap(){
	Hashmap hashmap = createHashmap(&compareKeys, &keyGenerator);
    int value = 20;
    int key = 2;
    ASSERT(putValue(&hashmap,&key,&value) == SUCCESS);
}

void test_put_two_elements_in_same_slot_of_hashMap(){
	Hashmap hashmap = createHashmap(&compareKeys, &keyGenerator);
	int values[] = {100,200};
	int keys[] = {11,21};
	ASSERT(putValue(&hashmap,&keys[0],&values[0]) == SUCCESS);
	ASSERT(putValue(&hashmap,&keys[1],&values[1]) == SUCCESS);
}

void test_put_multiple_elements_in_different_slots_of_hashMap(){
	Hashmap hashmap = createHashmap(&compareKeys, &keyGenerator);
	int values[] = {100,200,300,400,500};
	int keys[] = {11,12,13,14,15};
	ASSERT(putValue(&hashmap,&keys[0],&values[0]) == SUCCESS);
	ASSERT(putValue(&hashmap,&keys[1],&values[1]) == SUCCESS);
	ASSERT(putValue(&hashmap,&keys[2],&values[2]) == SUCCESS);
	ASSERT(putValue(&hashmap,&keys[3],&values[3]) == SUCCESS);
	ASSERT(putValue(&hashmap,&keys[4],&values[4]) == SUCCESS);
}

void test_do_not_put_when_hashmap_is_NULL(){
	int value = 20;
	int key = 2;
	ASSERT(putValue(NULL,&key,&value) == FAIL);
}

void test_do_not_put_when_key_is_NULL(){
	Hashmap hashmap = createHashmap(&compareKeys, &keyGenerator);
	int value = 20;
	ASSERT(putValue(&hashmap,NULL,&value) == FAIL);
}