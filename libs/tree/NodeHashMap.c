#include "NodeHashMap.h"
#include <stdlib.h>

int Hash(NodeHashMap H, int a){
    return a % (NODEHMP_CONTAINER(H));
}

void createNodeHashMap(NodeHashMap *H){
    NODEHMP_CONTAINER(*H) = INITIALHMPCAP;
    NODEHMP_BUFFER(*H) = (ListNode*) malloc (NODEHMP_CONTAINER(*H) * sizeof(ListNode));
    NODEHMP_LENGTH(*H) = 0;
    int i;
    for(i = 0; i < INITIALHMPCAP; i++){
        CreateListNode(&NODEHMP_LIST(*H, i));
    }
}

boolean isIdInHashMap(NodeHashMap H, int Id){
    return (listNodeIndexOf(NODEHMP_LIST(H, Hash(H, Id)), Id) != -1);
}

int getIdxInHashMap(NodeHashMap H, NodeBalasanAddress Node){
    return Hash(H, NODEBALASAN_ID(Node));
}

ListNode getListFromId(NodeHashMap H, int Id){
    return NODEHMP_LIST(H, Hash(H, Id));
}

ListNode* getListPointerFromId(NodeHashMap H, int Id){
    return &NODEHMP_LIST(H, Hash(H, Id));
}

NodeBalasanAddress getNodeInHashMap(NodeHashMap H, int Id){
    return getNodeFromId(getListFromId(H, Id), Id);
}

void addNodeToMap(NodeHashMap *H, NodeBalasanAddress Node){
    if (isIdInHashMap(*H, NODEBALASAN_ID(Node))){
        // Do Nothing
    }
    else{
        if (isListNodeFull(getListFromId(*H, NODEBALASAN_ID(Node)))){
            doubleHMPSize(H);
        }
        insertListNode(getListPointerFromId(*H, NODEBALASAN_ID(Node)), Node);
        NODEHMP_LENGTH(*H)++;
    }
}

void removeNodeFromMap(NodeHashMap *H, NodeBalasanAddress Node){
    if (isIdInHashMap(*H, NODEBALASAN_ID(Node))){
        deleteListNode(getListPointerFromId(*H, NODEBALASAN_ID(Node)), NODEBALASAN_ID(Node));
        NODEHMP_LENGTH(*H)--;
    }
}

void doubleHMPSize(NodeHashMap *H){
    ListNode *tempBuffer = NODEHMP_BUFFER(*H);
    int tempCont = NODEHMP_CONTAINER(*H);
    NODEHMP_CONTAINER(*H) *= 2;
    NODEHMP_BUFFER(*H) = (ListNode*) malloc (NODEHMP_CONTAINER(*H) * sizeof(ListNode));
    int i, j;
    for(i = 0; i < INITIALHMPCAP; i++){
        CreateListNode(&NODEHMP_LIST(*H, i));
    }
    for(i = 0; i < tempCont; i++){
        for(j = 0; j < LISTNODE_NEFF(tempBuffer[i]); j++){
            addNodeToMap(H, LISTNODE_ELMT(tempBuffer[i], j));
        }
    }
}

void dealokasiHMP(NodeHashMap *H){
    int i;
    for(i = 0; i < NODEHMP_CONTAINER(*H); i++){
        dealokasiListNode(&NODEHMP_LIST(*H, i));
    }
    free(H);
}