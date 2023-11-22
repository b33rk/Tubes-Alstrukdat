#include "nodeBalasan.h"
#include <stdio.h>
#include <stdlib.h>

NodeBalasanAddress newNodeBalasan(int Id, Text content, int IdAuthor, NodeBalasanAddress parent){
    NodeBalasanAddress N;
    
    N = (NodeBalasanAddress) malloc (sizeof(NodeBalasan));

    NODEBALASAN_ID(N) = Id;
    NODEBALASAN_TEXT(N) = content;
    NODEBALASAN_IDAUTHOR(N) = IdAuthor;

    ListDin newChildren;
    CreateListDin(&newChildren, 1);
    NODEBALASAN_CHILDREN(N) = newChildren;
    NODEBALASAN_PARENT(N) = parent;

    DATETIME D;
    getCurrentDateTime(&D);
    NODEBALASAN_TIME(N) = D;
    return N;
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