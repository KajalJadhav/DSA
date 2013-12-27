#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

const int INSERT_SUCCESSFUL = 1;

int compareInts(void *a,void *b){
	return *(int*)a - *(int*)b;
}

Tree tree;

void setup(){
	tree = createTree(compareInts);
}

void tearDown(){
	disposeTree(&tree);
}

void test_inserts_root_node(){
	int root = 2;
	int result = insertIntoTree(&tree, NULL, &root);
	ASSERT(INSERT_SUCCESSFUL == result);
}

void test_inserts_node_under_root_node(){
	int root = 1;
	int levelOneChildren[] = {2,3};
	Iterator result;
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &levelOneChildren[0]);
	insertIntoTree(&tree, &root, &levelOneChildren[1]);
	result = getChildren(&tree, &root);
	ASSERT(3 == *(int*)result.next(&result));
	ASSERT(2 == *(int*)result.next(&result));
}

void test_inserts_under_child_node(){
	int root = 1;
	int levelOneChildren[] = {2,3};
	Iterator result;
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &levelOneChildren[0]);
	insertIntoTree(&tree, &levelOneChildren[0], &levelOneChildren[1]);
	result = getChildren(&tree, &levelOneChildren[0]);
	ASSERT(3 == *(int*)result.next(&result));
}

void test_insert_when_tree_is_NULL(){
	int root = 1;
	ASSERT(insertIntoTree(NULL, NULL, &root) == 0);
}

void test_insert_NULL_in_tree(){
	int root = 1;
	ASSERT(insertIntoTree(&tree, &root,NULL) == 0);
}

void test_inserts_under_second_child(){
	int root = 1;
	int levelOneChildren[] = {2,3};
	int levelTwoChildren = 4;
	Iterator result;
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &levelOneChildren[0]);
	insertIntoTree(&tree, &root, &levelOneChildren[1]);
	insertIntoTree(&tree, &levelOneChildren[1], &levelTwoChildren);
	result = getChildren(&tree, &levelOneChildren[1]);
	ASSERT(4 == *(int*)result.next(&result));
}

void test_inserts_under_second_child_in_child_nodes(){
	int root = 1;
	int levelOneChildren[] = {2,3};
	int levelTwoChildren[] = {4,5};
	Iterator result;
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &levelOneChildren[0]);
	insertIntoTree(&tree, &root, &levelOneChildren[1]);
	insertIntoTree(&tree, &levelOneChildren[1], &levelTwoChildren[0]);
	insertIntoTree(&tree, &levelOneChildren[1], &levelTwoChildren[1]);
	result = getChildren(&tree, &levelOneChildren[1]);
	ASSERT(5 == *(int*)result.next(&result));
	ASSERT(4 == *(int*)result.next(&result));
}

void test_inserts_nodes_at_different_level(){
	int root = 1;
	int differentLevelChildrens[6] = {2,3,4,5,6,7};
	ASSERT(insertIntoTree(&tree, NULL, &root));
	ASSERT(insertIntoTree(&tree, &root, &differentLevelChildrens[0]));
	ASSERT(insertIntoTree(&tree, &differentLevelChildrens[0], &differentLevelChildrens[1]));
	ASSERT(insertIntoTree(&tree, &differentLevelChildrens[1], &differentLevelChildrens[2]));
	ASSERT(insertIntoTree(&tree, &differentLevelChildrens[2], &differentLevelChildrens[3]));
	ASSERT(insertIntoTree(&tree, &differentLevelChildrens[3], &differentLevelChildrens[4]));
}

void test_deletes_node_under_root_node_from_tree(){
	Iterator result;
	int root = 1;
	int levelOneChildren = 23;
	ASSERT(insertIntoTree(&tree, NULL, &root));
	ASSERT(insertIntoTree(&tree, &root, &levelOneChildren));
	ASSERT(deleteFromTree(&tree,&levelOneChildren));
	result = getChildren(&tree, &root);
	ASSERT(0 == result.hasNext(&result));
}

void test_deletes_nodes_from_different_level(){
	Iterator result;
	int root = 1;
	int differentLevelChildrens[6] = {2,3,4,5,6,7};
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &differentLevelChildrens[0]);
	insertIntoTree(&tree, &differentLevelChildrens[0], &differentLevelChildrens[1]);
	insertIntoTree(&tree, &differentLevelChildrens[1], &differentLevelChildrens[2]);
	insertIntoTree(&tree, &differentLevelChildrens[2], &differentLevelChildrens[3]);
	insertIntoTree(&tree, &differentLevelChildrens[3], &differentLevelChildrens[4]);
	ASSERT(deleteFromTree(&tree, &differentLevelChildrens[4]));
	result = getChildren(&tree, &differentLevelChildrens[3]);
	ASSERT(0 == result.hasNext(&result));
}

void test_searches_element_in_the_tree(){
	int root = 1;
	int differentLevelChildrens[6] = {2,3,4,5,6,7};
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &differentLevelChildrens[0]);
	insertIntoTree(&tree, &differentLevelChildrens[0], &differentLevelChildrens[1]);
	insertIntoTree(&tree, &differentLevelChildrens[1], &differentLevelChildrens[2]);
	insertIntoTree(&tree, &differentLevelChildrens[2], &differentLevelChildrens[3]);
	insertIntoTree(&tree, &differentLevelChildrens[3], &differentLevelChildrens[4]);
	ASSERT(searchInTree(&tree,&differentLevelChildrens[3]));
	ASSERT(searchInTree(&tree,&differentLevelChildrens[1]));
	ASSERT(searchInTree(&tree,&root));
}

void test_search_element_which_is_not_present_in_the_tree(){
	int root = 1;
	int data[6] = {12,30,4,45,5,50};
	insertIntoTree(&tree, NULL, &root);
	insertIntoTree(&tree, &root, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[1], &data[2]);
	insertIntoTree(&tree, &data[2], &data[3]);
	insertIntoTree(&tree, &data[3], &data[4]);
	ASSERT(searchInTree(&tree,&data[3]));
	ASSERT(searchInTree(&tree,&data[1]));
	ASSERT(0 == searchInTree(&tree,&data[6]));
}

void test_search_when_tree_is_NULL(){
	int elementToSearch = 1;
	ASSERT(0 == searchInTree(NULL,&elementToSearch));
}

void test_search_an_NULL_element_in_tree(){
	ASSERT(0 == searchInTree(&tree,NULL));
}