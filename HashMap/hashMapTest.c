#include "testUtils.h"
#include "hashMap.h"

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
