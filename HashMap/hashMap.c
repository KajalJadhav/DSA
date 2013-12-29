#include "hashMap.h"
#include "privateHashMap.h"
#include <stdlib.h>

Slot* createSlot(){
	Slot *slot = malloc(sizeof(Slot));
	slot->list = createList();
	return slot;
}

void assignAllSlots(ArrayList *list){
	int counter = 0;
	while(counter < list->capacity){
		add(list, createSlot());
		counter++;
	}
}

Hashmap createHashmap(Comparator *compare,HashCodeGenerator *generator){
	Hashmap hashmap;
	hashmap.bucket = create(10);
	hashmap.compare = compare;
	hashmap.hashCodeGenerator = generator;
	assignAllSlots(&hashmap.bucket);
	return hashmap;
}