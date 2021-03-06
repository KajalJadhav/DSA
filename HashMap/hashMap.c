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
void assignBucketsAndSlots(Hashmap* hash,int capacity){
	hash->bucket = createArrayList(capacity);
	assignAllSlots(&hash->bucket);
}

Hashmap createHashmap(Comparator *compare,HashCodeGenerator *generator){
	Hashmap hashmap;
	assignBucketsAndSlots(&hashmap,10);
	hashmap.compare = compare;
	hashmap.hashCodeGenerator = generator;
	hashmap.keys = createList();
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

void putKeysInRehashedMap(Hashmap* hash,Iterator keysIT){
	HashElement* element;
	while(keysIT.hasNext(&keysIT)){
		element = keysIT.next(&keysIT);
		putValue(hash,element->key,element->value);
	}
}

void rehashIfNeeded(Hashmap* hash,void* key){
	List* list;
	Iterator Keys;
	int currentCapacity = hash->bucket.capacity;
	list = getListFromHashMap(hash,key);
	if(list->length < 2)
		return;
	Keys = keys(hash);
	disposeHashmap(hash);
	assignBucketsAndSlots(hash,currentCapacity*2);
	putKeysInRehashedMap(hash,Keys);
}

int putValue(Hashmap* hash,void* key,void* value){
	List *list;
	HashElement *element;
	if(hash == NULL || key == NULL) 
		return 0;
	rehashIfNeeded(hash,key);
	list = getListFromHashMap(hash, key);
	element = getElementFromList(list,key,hash->compare);
	
	if(element != NULL){
		element->value = value;
		return 1;
	}
	element = createHashElement(key,value);
	return insertNode(list,list->length, element);
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
	disposeList(keys);
	keys = createList();
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
	
void disposeSlot(Slot *slot){
    disposeList(slot->list);
    free(slot);
}

void disposeHashmap(Hashmap *hash){
    Iterator it = getIterator(&hash->bucket);
    Slot *slot;
    while(it.hasNext(&it)){
        slot = it.next(&it);
        disposeSlot(slot);
    }
    disposeArrayList(&hash->bucket);
}