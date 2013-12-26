#include "include/dList.h"

typedef struct treenode{
	void* data;
	struct treenode* parent;
	DoubleList children;
} TreeNode;