#include "iterator.h"
typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef int (*compare)(void* element1, void* element2);

typedef void ForEach(void* data);

ArrayList create(int capacity);

int insert(ArrayList *list, int index, void* data);

int add(ArrayList *list, void* data);

int remove(ArrayList *list, int index);

void* get(ArrayList *list, int index);

int search(ArrayList *list, void *searchElement, compare compareFunc);

Iterator getIterator(ArrayList* list);

void iterate(ArrayList list, ForEach* forEach);

void dispose(ArrayList *list);