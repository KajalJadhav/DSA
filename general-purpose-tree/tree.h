#include "tree_iterator.h"
#include "include/iterator.h"

#ifndef _COMPARE_
#define _COMPARE_

typedef int (*compare)(void* element1, void* element2);

#endif

typedef struct {
	compare cmp;
	void *root;
} Tree;

Tree createTree(compare cmp);
int insertIntoTree(Tree* tree, void* parentData, void* data);
Iterator getChildren(Tree* tree, void* parentData);
int deleteFromTree(Tree* tree, void* data);
int searchInTree(Tree* tree, void* data);