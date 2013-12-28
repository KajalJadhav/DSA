#include "tree.h"
#include <stdlib.h>
#include "internalTree.h"

void* getTreeNode(List* list,void* data,comparator* comp){
    Iterator it = getIterator(list);
    TreeNode *treenode;
    while(it.hasNext(&it)){
        treenode = (TreeNode*)it.next(&it);
        if(0 == comp(treenode->data,data))
            return treenode;
        if(treenode->child->head != NULL)
            return getTreeNode(treenode->child,data,comp);
    }
    return NULL;
}

TreeNode* createTreeNode(TreeNode* parent,void* data){
    TreeNode* treenode = calloc(1,sizeof(TreeNode));
    treenode->child = create();
    treenode->parent = parent;
    treenode->data = data;
    return treenode;
}

Tree createTree(comparator* comp){
    Tree tree = {NULL,comp};
    return tree;
}

void* getRootData(Tree* tree){
    TreeNode tempTree = *(TreeNode*)tree->root;
    return tempTree.data; 
}

void *nextSibling(Iterator *it){
    TreeNode *node;
    Iterator treeIterator = getIterator(it->list);
    treeIterator.position = it->position;
    node = treeIterator.next(&treeIterator);
    it->position++;
    return node->data;
}

Iterator getChildren(Tree *tree, void *parentData){
    Iterator it;
    TreeNode *parentNode,*rootNode = tree->root;
    if(tree->comp(rootNode->data,parentData)==0)
        parentNode = rootNode;
    else
        parentNode = getTreeNode(rootNode->child, parentData,tree->comp);
    it = getIterator(parentNode->child);
    it.next = &nextSibling;
    return it;
}

int insertInTree(Tree* tree, void *parentData, void *dataToInsert){
    TreeNode *parentNode, *newNode,*rootNode;
    if(tree == NULL || dataToInsert == NULL) return 0;
    if(NULL == parentData){
        tree->root = createTreeNode(NULL, dataToInsert);
        return 1;
    }
    rootNode = (TreeNode*)tree->root;
    if(0 == tree->comp(rootNode->data,parentData)){
        newNode = createTreeNode(rootNode, dataToInsert);
        return insertNode(rootNode->child,rootNode->child->length, newNode);
	}
    parentNode = getTreeNode(rootNode->child,parentData, tree->comp);
    newNode = createTreeNode(parentNode, dataToInsert);
    return insertNode(parentNode->child,parentNode->child->length, newNode);
};

int search(Tree *tree,void* elementToSearch){
    TreeNode *rootNode;
    if(tree == NULL || elementToSearch == NULL)
        return 0;
    rootNode = tree->root;
    if(tree->comp(elementToSearch,rootNode->data) == 0)
        return 1;
    if(getTreeNode(rootNode->child, elementToSearch,tree->comp) != NULL)
        return 1;
    return 0;
}

int deleteFromTree(Tree *tree,void* dataToRemove){
    TreeNode *rootNode,*nodeToDelete,*parentNode;
    Iterator it;
    if(tree == NULL || dataToRemove == NULL) return 0;
    rootNode = tree->root;
    nodeToDelete = getTreeNode(rootNode->child, dataToRemove, tree->comp);
    if(nodeToDelete == NULL || nodeToDelete->child->length != 0)        return 0;
    parentNode = nodeToDelete->parent;
    it = getIterator(parentNode->child);
    while(it.hasNext(&it)){
        if(tree->comp(it.next(&it),nodeToDelete) == 0){
            deleteNode(parentNode->child,it.position);
            break;
        }
    }
    return 1;
}

void disposeNodes(List *list){
    Iterator it ;
    List* childList;
    TreeNode *treeNode;
    it = getIterator(list);
    while(it.hasNext(&it)){
        treeNode = (TreeNode*)it.next(&it);
        childList = (List*)(treeNode->child);
        disposeNodes(childList);
    }
}

void disposeTree(Tree* tree){
    TreeNode *root = tree->root;
    if(root != NULL){
        disposeNodes(root->child);
        free(root);
    }
}