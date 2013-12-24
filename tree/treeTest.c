#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_insert_root_node(){
    Tree tree = createRoot();
    int data = 2;
    Iterator* it;
    int result = insert(&tree, NULL, &data);
    const int INSERT_SUCCESSFUL = 1;
    ASSERT(INSERT_SUCCESSFUL == result);
    it = getChildren(&tree, NULL);
    next(it);
}

void test_fail(){
	ASSERT(0);
}