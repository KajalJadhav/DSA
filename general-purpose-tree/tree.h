#include "tree_iterator.h"
#include "include/iterator.h"

typedef int comparator(void* nodeData,void* parentData);

typedef struct{
    void* root;
    comparator *comp;
} Tree;

Tree createTree(comparator* areEqual);

int insertInTree(Tree *tree, void *parentData, void *data);

void* getRootData(Tree *tree);

Iterator getChildren(Tree *tree, void *parentData);

int search(Tree *tree,void* elementToSearch);

int deleteFromTree(Tree *tree,void* dataToRemove);

void disposeTree(Tree* tree);