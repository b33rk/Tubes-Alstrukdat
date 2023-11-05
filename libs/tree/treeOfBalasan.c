#include "treeOfBalasan.h"
#include <stdio.h>
#include <stdlib.h>

void createTree(TreeOfBalasan *T){

    Text EmptyText;
    CreateText(&EmptyText, 1);
    insertLastText(&EmptyText, ' ');

    TREE_MASTER(*T) = newNodeBalasan(0, 0, EmptyText, NULL);
    CreateListNode(&TREE_LIST(*T), 1);

    TREE_NEXTID(*T) = 1;
}

void addToTreeAt(TreeOfBalasan *T, Text txt, int trueId){
}

void deleteTreeNodeAt(TreeOfBalasan *T, int trueId){
}
