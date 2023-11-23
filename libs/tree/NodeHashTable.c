#include "NodeHashTable.h"
#include <stdlib.h>

int Hash(NodeHashTable H, int a){
    return a % (NODEHTABLE_CONTAINER(H));
}

void createNodeHashTable(NodeHashTable *H){
    NODEHTABLE_CONTAINER(*H) = INITIALHTABLECAP;
    NODEHTABLE_BUFFER(*H) = (ListNode*) malloc (NODEHTABLE_CONTAINER(*H) * sizeof(ListNode));
    NODEHTABLE_LENGTH(*H) = 0;
    int i;
    for(i = 0; i < INITIALHTABLECAP; i++){
        CreateListNode(&NODEHTABLE_LIST(*H, i));
    }
}

boolean isIdInNodeHashTable(NodeHashTable H, int Id){
    return (listNodeIndexOf(NODEHTABLE_LIST(H, Hash(H, Id)), Id) != -1);
}

int getIdxInNodeHashTable(NodeHashTable H, NodeBalasanAddress Node){
    return Hash(H, NODEBALASAN_ID(Node));
}

ListNode getListFromId(NodeHashTable H, int Id){
    return NODEHTABLE_LIST(H, Hash(H, Id));
}

ListNode* getListPointerFromId(NodeHashTable H, int Id){
    return &NODEHTABLE_LIST(H, Hash(H, Id));
}

NodeBalasanAddress getNodeInHashTable(NodeHashTable H, int Id){
    return getNodeFromId(getListFromId(H, Id), Id);
}

void addNodeToTable(NodeHashTable *H, NodeBalasanAddress Node){
    if (isIdInNodeHashTable(*H, NODEBALASAN_ID(Node))){
        // Do Nothing
    }
    else{
        if (isListNodeFull(getListFromId(*H, NODEBALASAN_ID(Node)))){
            doubleHTABLESize(H);
        }
        insertListNode(getListPointerFromId(*H, NODEBALASAN_ID(Node)), Node);
        NODEHTABLE_LENGTH(*H)++;
    }
}

void removeNodeFromTable(NodeHashTable *H, NodeBalasanAddress Node){
    if (isIdInNodeHashTable(*H, NODEBALASAN_ID(Node))){
        deleteListNode(getListPointerFromId(*H, NODEBALASAN_ID(Node)), NODEBALASAN_ID(Node));
        NODEHTABLE_LENGTH(*H)--;
    }
}

void doubleHTABLESize(NodeHashTable *H){
    ListNode *tempBuffer = NODEHTABLE_BUFFER(*H);
    int tempCont = NODEHTABLE_CONTAINER(*H);
    NODEHTABLE_CONTAINER(*H) *= 2;
    NODEHTABLE_BUFFER(*H) = (ListNode*) malloc (NODEHTABLE_CONTAINER(*H) * sizeof(ListNode));
    int i, j;
    for(i = 0; i < INITIALHTABLECAP; i++){
        CreateListNode(&NODEHTABLE_LIST(*H, i));
    }
    for(i = 0; i < tempCont; i++){
        for(j = 0; j < LISTNODE_NEFF(tempBuffer[i]); j++){
            addNodeToTable(H, LISTNODE_ELMT(tempBuffer[i], j));
        }
    }
}

void dealokasiHTABLE(NodeHashTable *H){
    int i;
    for(i = 0; i < NODEHTABLE_CONTAINER(*H); i++){
        dealokasiListNode(&NODEHTABLE_LIST(*H, i));
    }
    free(H);
}