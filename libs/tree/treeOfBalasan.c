#include "treeOfBalasan.h"
#include <stdio.h>
#include <stdlib.h>

void createTree(TreeOfBalasan *T){

    Text EmptyText;
    CreateText(&EmptyText, 1);

    NodeBalasanAddress origin = newNodeBalasan(0, EmptyText, NULL);
    TREE_MASTER(*T) = origin;
    createNodeHashMap(&TREE_HMP(*T));
    addNodeToMap(&TREE_HMP(*T), origin);

    TREE_NEXTID(*T) = 1;
}

NodeBalasanAddress getNodeInTreeById(TreeOfBalasan T, int Id){
    getNodeInHashMap(TREE_HMP(T), Id);
}

void addToTreeAt(TreeOfBalasan *T, Text txt, int Id){
    NodeBalasanAddress node = newNodeBalasan(TREE_NEXTID(*T), txt, getNodeInTreeById(*T, Id));
    addChildren(getNodeInTreeById(*T, Id), node);
    addNodeToMap(&TREE_HMP(*T), node);
    TREE_NEXTID(*T)++;
}

void deleteTreeNodeAt(TreeOfBalasan *T, int Id){
    int i;
    NodeBalasanAddress node = getNodeInHashMap(TREE_HMP(*T), Id);
    ListDin children = NODEBALASAN_CHILDREN(node);
    for(i = 0; i < LISTDIN_NEFF(children); i++){
        deleteTreeNodeAt(T, LISTDIN_ELMT(children, i));
    }
    removeNodeFromMap(&(TREE_HMP(*T)), node);
    removeChildren(NODEBALASAN_PARENT(node), node);
}

void displayAll(TreeOfBalasan T){
    displayNodeAll(T, 0, -2);
}

void displayNodeAll(TreeOfBalasan T, int Id, int indent){
    int i;
    NodeBalasanAddress node = getNodeInHashMap(TREE_HMP(T), Id);
    ListDin children = NODEBALASAN_CHILDREN(node);
    if (Id != 0){displayNode(node, indent);}
    for(i = 0; i < LISTDIN_NEFF(children); i++){
        displayNodeAll(T, LISTDIN_ELMT(children, i), indent + 2);
    }
}
