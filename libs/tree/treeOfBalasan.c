#include "treeOfBalasan.h"
#include <stdio.h>
#include <stdlib.h>

void createTree(TreeOfBalasan *T){

    Text EmptyText = charArrToText("");

    NodeBalasanAddress origin = newNodeBalasan(0, EmptyText, 0, NULL);
    TREE_MASTER(*T) = origin;
    createNodeHashMap(&TREE_HMP(*T));
    addNodeToMap(&TREE_HMP(*T), origin);

    TREE_NEXTID(*T) = 1;
}

int TreeLength(TreeOfBalasan T){
    return NODEHMP_LENGTH(TREE_HMP(T));
}

NodeBalasanAddress getNodeInTreeById(TreeOfBalasan T, int Id){
    return getNodeInHashMap(TREE_HMP(T), Id);
}

boolean isIdInTree(TreeOfBalasan T, int Id){
    return isIdInHashMap(TREE_HMP(T), Id);
}

int addToTreeAt(TreeOfBalasan *T, Text content, int IdAuthor, int Id){
    NodeBalasanAddress node = newNodeBalasan(TREE_NEXTID(*T), content, IdAuthor, getNodeInTreeById(*T, Id));
    addChildren(getNodeInTreeById(*T, Id), node);
    addNodeToMap(&TREE_HMP(*T), node);
    TREE_NEXTID(*T)++;
    return TREE_NEXTID(*T) - 1;
}

void deleteTreeNodeAt(TreeOfBalasan *T, int Id){
    NodeBalasanAddress node = getNodeInHashMap(TREE_HMP(*T), Id);
    ListDin *children = &NODEBALASAN_CHILDREN(node);
    while(LISTDIN_NEFF(*children) > 0){
        deleteTreeNodeAt(T, LISTDIN_ELMT(*children, 0));
    }
    removeNodeFromMap(&(TREE_HMP(*T)), node);
    removeChildren((NODEBALASAN_PARENT(node)), node);
}

void dealokasiTree(TreeOfBalasan *T){
    TREE_MASTER(*T) = NULL;
    deleteTreeNodeAt(T, 0);
    dealokasiHMP(&TREE_HMP(*T));
    free(T);
}
