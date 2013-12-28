#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

const int SUCCESS = 1;
const int FAIL = 0;

Tree tree;

int compareIntegers(void *a,void *b){
    return *(int*)a - *(int*)b;
}

void setup(){
    tree = createTree(compareIntegers);
}

void tearDown(){
    disposeTree(&tree);
}

void test_inserts_root_node(){
    int data = 10;
    ASSERT(SUCCESS == insertInTree(&tree, NULL, &data));
    ASSERT(&data == getRootData(&tree));
}

void test_inserts_node_under_root_node(){
    int numbers[] = {1,2,3};
    Iterator children;
    insertInTree(&tree, NULL, &numbers[0]);
    insertInTree(&tree, &numbers[0], &numbers[1]);
    insertInTree(&tree, &numbers[0], &numbers[2]);
    children = getChildren(&tree,&numbers[0]);
    ASSERT(*(int*)children.next(&children) == 2);
    ASSERT(*(int*)children.next(&children) == 3);
}

void test_inserts_node_under_child_node(){
    int root = 1;
    int levelOneChild = 2;
    int levelTwoChild = 3;
    Iterator childrenOflevelOne;
    insertInTree(&tree, NULL, &root);
    insertInTree(&tree, &root, &levelOneChild);
    insertInTree(&tree, &levelOneChild, &levelTwoChild);  
    childrenOflevelOne = getChildren(&tree,&levelOneChild);
    ASSERT(*(int*)childrenOflevelOne.next(&childrenOflevelOne) == 3);
}

void test_inserts_node_under_second_child_node(){
    int root = 1;
    int levelOneChildren[] = {2,3};
    int levelTwoChildren[] = {4,5};
    Iterator children;
    insertInTree(&tree, NULL, &root);
    insertInTree(&tree, &root, &levelOneChildren[0]);
    insertInTree(&tree, &root, &levelOneChildren[1]);
    insertInTree(&tree, &levelOneChildren[1], &levelTwoChildren[0]);  
    insertInTree(&tree, &levelOneChildren[1], &levelTwoChildren[1]);  
    children = getChildren(&tree,&levelOneChildren[1]);
    ASSERT(*(int*)children.next(&children) == 4);
    ASSERT(*(int*)children.next(&children) == 5);
}

void test_inserts_when_tree_is_NULL(){
    int root = 1;
    ASSERT(0 == insertInTree(NULL, NULL, &root));
}

void test_inserts_when_data_to_insert_is_NULL(){
    ASSERT(0 == insertInTree(&tree, NULL, NULL));
}

void test_removes_Node_from_tree(){
    int root = 1;
    int child = 2;
    Iterator children;
    insertInTree(&tree, NULL, &root);
    insertInTree(&tree, &root, &child);
    ASSERT(SUCCESS == deleteFromTree(&tree, &child));
}

void test_removes_when_node_is_not_present(){
    int root = 1;
    int child = 2;
    Iterator children;
    insertInTree(&tree, NULL, &root);
    ASSERT(FAIL == deleteFromTree(&tree, &child));
}

void test_does_not_remove_when_children_are_present(){
    int root = 1;
    int levelOneChild = 2;
    int levelTwoChild = 3;
    Iterator children;
    insertInTree(&tree, NULL, &root);
    insertInTree(&tree, &root, &levelOneChild);
    insertInTree(&tree, &levelOneChild, &levelTwoChild);
    ASSERT(FAIL == deleteFromTree(&tree, &levelOneChild));
}

void test_removes_when_tree_is_NULL(){
    int toRemove = 10;
    ASSERT(FAIL == deleteFromTree(NULL, &toRemove));
}

void test_removes_when_data_is_NULL(){
    ASSERT(FAIL == deleteFromTree(&tree, NULL));
}

void test_searches_rootNode_in_tree(){
    int root = 10;
    insertInTree(&tree, NULL, &root);
    ASSERT(1 == search(&tree,&root));
}

void test_searches_child_node_in_tree(){
    Tree tree = createTree(compareIntegers);
    int root = 1;
    int child = 2;
    insertInTree(&tree, NULL, &root);
    insertInTree(&tree, &root, &child);
    ASSERT(1 == search(&tree,&child));   
}

void test_searches_when_element_is_not_present(){
    int root = 1;
    int elementToSearch = 3;
    insertInTree(&tree, NULL, &root);
    ASSERT(0 == search(&tree,&elementToSearch));
}

void test_searches_when_tree_is_NULL(){
    int elementToSearch = 1;
    ASSERT(0 == search(NULL,&elementToSearch));
}

void test_searches_when_element_to_search_is_NULL(){
    ASSERT(0 == search(&tree,NULL));
}

