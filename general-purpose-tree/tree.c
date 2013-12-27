#include "tree.h"
#include "internalTree.h"
#include <stdlib.h>
#include <stdio.h>

TreeNode* getTreeNode(DoubleList *list,void *dataToFind,compare cmp){
	Iterator it = getIterator(list);
	TreeNode *treenode;
	while(it.hasNext(&it)){
		treenode = (TreeNode*)it.next(&it);
		if(0 == cmp(treenode->data,dataToFind))
			return treenode;
		if(treenode->children.head)
			return getTreeNode(&treenode->children, dataToFind, cmp);
	}
	return NULL;
}

TreeNode* createTreeNode(void *data,TreeNode *parent){
	TreeNode *treenode = malloc(sizeof(TreeNode));
	treenode->data = data;
	treenode->parent = parent;
	treenode->children = create();
	return treenode;
}

Tree createTree(compare cmp){
	Tree tree = {cmp,NULL};
	return tree;
}

int insertIntoTree(Tree* tree, void* parentData, void* childData) {
	TreeNode *root;
	TreeNode *nodeToInsert, *parentNode;
	if(tree == NULL || childData == NULL)
		return 0;
	root = (TreeNode*)tree->root;
	if(NULL == tree->root){
		tree->root = createTreeNode(childData, NULL);
		return 1;
	}
	if(0 == tree->cmp(root->data,parentData)){
		parentNode = root;
		nodeToInsert = createTreeNode(childData, parentNode);
		insert(&root->children, 0, nodeToInsert);
		return 1;
	}
	parentNode = getTreeNode(&root->children, parentData, tree->cmp);
	nodeToInsert = createTreeNode(childData, parentNode);
	insert(&parentNode->children, 0, nodeToInsert);
	return 1;
}

void* treeNext(Iterator *it){
	TreeNode *node;
	Iterator treeIterator = getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position++;
	return node->data;
}

Iterator getChildren(Tree* tree, void *parent) {
	TreeNode *temp,*root = (TreeNode*)tree->root;
	Iterator it;
	if(0 == tree->cmp(root->data,parent))
		temp = root;
	else 
		temp = getTreeNode(&root->children, parent, tree->cmp);
	it = getIterator(&temp->children);
	it.next = &treeNext;
	return it;
}

int deleteFromTree(Tree *tree, void *data){
	TreeNode* root;
	TreeNode *tn,*parent;
	Iterator it;
	root = (TreeNode*)tree->root;
	tn = getTreeNode(&root->children, data, tree->cmp);
	if(0 == tn->children.length){
		parent = tn->parent;
		it = getIterator(&parent->children);
		while(it.hasNext(&it)){
			if(tree->cmp(data,it.next(&it)))
				break;
		}
		delete(&parent->children, it.position - 1);
		return 1;
	}
	return 0;
}

int searchInTree(Tree* tree, void* elementToSearch){
    TreeNode* root;
    if(tree == NULL || elementToSearch == NULL)
		return 0;
	root = (TreeNode*)tree->root;
    if(0 == tree->cmp(elementToSearch,root->data))
    	return 1;
    if(NULL != getTreeNode(&root->children,elementToSearch,tree->cmp))
        return 1;
    return 0;
}

void disposeTree(Tree* tree){
    free(tree->root);
}