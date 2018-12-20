#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(void)
{
    TreeNode tree = init(tree, 8);
    Insert(tree,3);

    Insert(tree,10);
    Insert(tree,12);
    Insert(tree, 9);
    deleteNode(tree, 8);
    inOrder(tree);

    
    return 0;
}