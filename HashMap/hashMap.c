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
	hashmap.bucket = createArrayList(10);
	hashmap.compare = compare;
	hashmap.hashCodeGenerator = generator;
	hashmap.keys = createList();
	assignAllSlots(&hashmap.bucket);
	return hashmap;
}

int getSlotIndex(Hashmap* hash,void* key){
	return hash->hashCodeGenerator(key) % hash->bucket.capacity;
}

List* getListFromHashMap(Hashmap* hash,void* key){
	Slot *slotOfElement;
	int slotNumber = getSlotIndex(hash,key);
	slotOfElement = get(&hash->bucket,slotNumber);
	return slotOfElement->list;
}

HashElement* getElementFromList(List *list,void* key,Compare *compare){
	HashElement *temp;
	Iterator it = getIteratorForList(list);
	while(it.hasNext(&it)){
		temp = it.next(&it);
		if(compare(temp->key , key) == 0)
			return temp;
	}
	return NULL;
}

HashElement *createHashElement(void* key,void*value){
	HashElement *hashElement = malloc(sizeof(HashElement));
	hashElement->key = key;
	hashElement->value = value;
	return hashElement;
}

int putValue(Hashmap* hash,void* key,void* value){
	List *list;
	HashElement *hashElement;
	if(hash == NULL || key == NULL) 
		return 0;
	list = getListFromHashMap(hash, key);
	hashElement = getElementFromList(list,key,hash->compare);
	
	if(hashElement != NULL){
		hashElement->value = value;
		return 1;
	}
	hashElement = createHashElement(key,value);
	return insertNode(list,list->length, hashElement);
}

void* getValue(Hashmap *hash, void *key){
	List* list;
	HashElement* element;
	if(hash == NULL || key == NULL)
		return 0;
	list = getListFromHashMap(hash,key);
	element = getElementFromList(list,key,hash->compare);
	if(element == NULL) 
		return 0;
	return element->value;
}

int getIndexFromList(List *list,void* data,Compare *compare){
    Iterator it = getIteratorForList(list);
    while(it.hasNext(&it)){
        if(compare(it.next(&it),data) == 0)
            return it.position-1;
    }
    return -1;
}

int compareKeysOfHashElements(void* element1,void* element2){
	HashElement *first,*second;
	first = (HashElement*)element1;
	second = (HashElement*)element2;
	return first->key - second->key;
}

int removeFromHashMap(Hashmap *hash,void* key){
	List* list;
	HashElement* element;
	int index;
	if(hash == NULL || key == NULL)
		return 0;
	list = getListFromHashMap(hash,key);
	element = getElementFromList(list,key,hash->compare);
	index = getIndexFromList(list,element,&compareKeysOfHashElements);
	return deleteNode(list,index);
}

Iterator keys(Hashmap *hash){
	Iterator listIT,keysIT,arrayIT;
	Slot *slot;
	List *keys = (List*)hash->keys;
	arrayIT = getIterator(&hash->bucket);
	while(arrayIT.hasNext(&arrayIT)){
		slot = arrayIT.next(&arrayIT);
		listIT = getIteratorForList(slot->list);
		while(listIT.hasNext(&listIT)){
			insertNode(keys,keys->length,listIT.next(&listIT));
		}
	}
	keysIT = getIteratorForList(keys);
	return keysIT;
}