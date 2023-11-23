#include "treeOfBalasan.h"
#include <stdio.h>
#include <stdlib.h>

void createTree(TreeOfBalasan *T){

    Text EmptyText = charArrToText("");

    NodeBalasanAddress origin = newNodeBalasan(0, EmptyText, 0, NULL);
    TREE_MASTER(*T) = origin;
    createNodeHashTable(&TREE_HTB(*T));
    addNodeToTable(&TREE_HTB(*T), origin);

    TREE_NEXTID(*T) = 1;
}

int TreeLength(TreeOfBalasan T){
    return NODEHTABLE_LENGTH(TREE_HTB(T));
}

NodeBalasanAddress getNodeInTreeById(TreeOfBalasan T, int Id){
    return getNodeInHashTable(TREE_HTB(T), Id);
}

boolean isIdInTree(TreeOfBalasan T, int Id){
    return isIdInNodeHashTable(TREE_HTB(T), Id);
}

int addToTreeAt(TreeOfBalasan *T, Text content, int IdAuthor, int Id){
    NodeBalasanAddress node = newNodeBalasan(TREE_NEXTID(*T), content, IdAuthor, getNodeInTreeById(*T, Id));
    addChildren(getNodeInTreeById(*T, Id), node);
    addNodeToTable(&TREE_HTB(*T), node);
    TREE_NEXTID(*T)++;
    return TREE_NEXTID(*T) - 1;
}

void deleteTreeNodeAt(TreeOfBalasan *T, int Id){
    NodeBalasanAddress node = getNodeInHashTable(TREE_HTB(*T), Id);
    ListDin *children = &NODEBALASAN_CHILDREN(node);
    while(LISTDIN_NEFF(*children) > 0){
        deleteTreeNodeAt(T, LISTDIN_ELMT(*children, 0));
    }
    removeNodeFromTable(&(TREE_HTB(*T)), node);
    removeChildren((NODEBALASAN_PARENT(node)), node);
}

void dealokasiTree(TreeOfBalasan *T){
    TREE_MASTER(*T) = NULL;
    deleteTreeNodeAt(T, 0);
    dealokasiHTABLE(&TREE_HTB(*T));
    free(T);
}
