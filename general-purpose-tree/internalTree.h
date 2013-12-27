#include "include/SLList.h"

typedef struct TreeNode{
    struct TreeNode* parent;
    List *child;
    void* data;
} TreeNode;

TreeNode* createTreeNode(TreeNode* tree,void* parent);

void *nextSibling(Iterator *it);