#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

const int INSERT_SUCCESSFUL = 1;

int compareInt(void *a,void *b){
	return *(int*)a - *(int*)b;
}

void test_inserts_root_node(){
	Tree tree = createTree(compareInt);
	int data = 2;
	int result = insertIntoTree(&tree, NULL, &data);
	ASSERT(INSERT_SUCCESSFUL == result);
}

void test_inserts_node_under_root_node(){
	Tree tree = createTree(compareInt);
	int data[] = {2,3,5};
	Iterator result;
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[0], &data[2]);
	result = getChildren(&tree, &data);
	ASSERT(5 == *(int*)result.next(&result));
	ASSERT(3 == *(int*)result.next(&result));
}

void test_inserts_under_child_node(){
	Tree tree = createTree(compareInt);
	int data[] = {2,3,5};
	Iterator result;
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[1], &data[2]);
	result = getChildren(&tree, &data[1]);
	ASSERT(5 == *(int*)result.next(&result));
}

void test_inserts_under_second_child(){
	Tree tree = createTree(compareInt);
	int data0 = 2;
	int data1[] = {3,5};
	int data2 = 9;
	Iterator result;
	insertIntoTree(&tree, NULL, &data0);
	insertIntoTree(&tree, &data0, &data1[0]);
	insertIntoTree(&tree, &data0, &data1[1]);
	insertIntoTree(&tree, &data1[1], &data2);
	result = getChildren(&tree, &data1[1]);
	ASSERT(9 == *(int*)result.next(&result));
}

void test_inserts_nodes_at_different_level(){
	Tree tree = createTree(compareInt);
	Iterator it;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertIntoTree(&tree, NULL, &data[0]));
	ASSERT(insertIntoTree(&tree, &data[0], &data[1]));
	ASSERT(insertIntoTree(&tree, &data[1], &data[2]));
	ASSERT(insertIntoTree(&tree, &data[2], &data[3]));
	ASSERT(insertIntoTree(&tree, &data[3], &data[4]));
	ASSERT(insertIntoTree(&tree, &data[4], &data[5]));
}

void test_deletes_node_under_root_node_from_tree(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[2] = {10,23};
	ASSERT(insertIntoTree(&tree, NULL, &data));
	ASSERT(insertIntoTree(&tree, &data, &data[1]));
	ASSERT(deleteFromTree(&tree,&data[1]));
	result = getChildren(&tree, &data);
	ASSERT(0 == result.hasNext(&result));
}

void test_deletes_root_node_from_tree(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[2] = {10,23};
	ASSERT(insertIntoTree(&tree, NULL, &data));
}

void test_deletes_nodes_from_different_level(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[1], &data[2]);
	insertIntoTree(&tree, &data[2], &data[3]);
	insertIntoTree(&tree, &data[3], &data[4]);
	insertIntoTree(&tree, &data[4], &data[5]);
	ASSERT(deleteFromTree(&tree, &data[5]));
	result = getChildren(&tree, &data[4]);
	ASSERT(0 == result.hasNext(&result));
}

void test_searches_element_in_the_tree(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[1], &data[2]);
	insertIntoTree(&tree, &data[2], &data[3]);
	insertIntoTree(&tree, &data[3], &data[4]);
	insertIntoTree(&tree, &data[4], &data[5]);
	ASSERT(searchInTree(&tree,&data[4]));
	ASSERT(searchInTree(&tree,&data[2]));
	ASSERT(searchInTree(&tree,&data[0]));
}

void test_search_element_which_is_not_present_in_the_tree(){
	Tree tree = createTree(compareInt);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[1], &data[2]);
	insertIntoTree(&tree, &data[2], &data[3]);
	insertIntoTree(&tree, &data[3], &data[4]);
	insertIntoTree(&tree, &data[4], &data[5]);
	ASSERT(searchInTree(&tree,&data[4]));
	ASSERT(searchInTree(&tree,&data[2]));
	ASSERT(0 == searchInTree(&tree,&data[7]));
}