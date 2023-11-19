#include "nodeBalasan.h"
#include <stdio.h>
#include <stdlib.h>

NodeBalasanAddress newNodeBalasan(int Id, Text content, NodeBalasanAddress parent){
    NodeBalasanAddress N;
    
    N = (NodeBalasanAddress) malloc (sizeof(NodeBalasan));

    NODEBALASAN_ID(N) = Id;

    Text newContent;
    copyText(content, &newContent);
    NODEBALASAN_TEXT(N) = newContent;

    ListDin newChildren;
    CreateListDin(&newChildren, 1);
    NODEBALASAN_CHILDREN(N) = newChildren;

    NODEBALASAN_PARENT(N) = parent;
}

void addChildren(NodeBalasanAddress Nparent, NodeBalasanAddress Nchildren){
    insertLastListDin(&(NODEBALASAN_CHILDREN(Nparent)), NODEBALASAN_ID(Nchildren));
    NODEBALASAN_PARENT(Nchildren) = Nparent;
}

void removeChildren(NodeBalasanAddress Nparent, NodeBalasanAddress Nchildren){
    deleteElListDin(&NODEBALASAN_CHILDREN(Nparent), NODEBALASAN_ID(Nchildren));
    NODEBALASAN_PARENT(Nchildren) = NULL;
    free(Nchildren);
}

void displayNode(NodeBalasanAddress N, int Indent){
    int i;
    int j;
    for(i = 0; i < Indent; i++){printf(" ");}
    printf("| ID = %d\n", NODEBALASAN_ID(N));
    for(i = 0; i < Indent; i++){printf(" ");}
    printf("| ");
    printText(NODEBALASAN_TEXT(N));
    printf("\n");
}