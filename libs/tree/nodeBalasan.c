#include "nodeBalasan.h"
#include <stdio.h>
#include <stdlib.h>

NodeBalasanAddress newNodeBalasan(int Id, int trueId, Text content, NodeBalasanAddress parent){
    NodeBalasanAddress N;
    
    N = (NodeBalasanAddress) malloc (sizeof(NodeBalasan));

    NODEBALASAN_ID(N) = Id;
    NODEBALASAN_TRUEID(N) = trueId;

    Text newContent;
    copyText(content, &newContent);
    NODEBALASAN_TEXT(N) = newContent;

    ListDin newChildren;
    CreateListDin(&newChildren, 1);
    NODEBALASAN_CHILDREN(N) = newChildren;

    NODEBALASAN_PARENT(N) = parent;
}

void addChildren(NodeBalasanAddress Nparent, int Id, int trueId, Text content){
    NodeBalasanAddress newChild = newNodeBalasan(Id, trueId, content, Nparent);
    insertLastListDin(&NODEBALASAN_CHILDREN(Nparent), trueId);
}

void removeChildren(NodeBalasanAddress Nparent, NodeBalasanAddress Nchildren){
    deleteElListDin(&NODEBALASAN_CHILDREN(Nparent), NODEBALASAN_ID(Nchildren));
    NODEBALASAN_PARENT(Nchildren) = NULL;
}