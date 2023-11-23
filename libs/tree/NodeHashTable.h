#ifndef NODEHTABLE_H
#define NODEHTABLE_H

#include "listnode.h"

typedef struct idnodehashtable{
    ListNode* buffer;
    int containerNum;
    int length;
} NodeHashTable;

#define INITIALHTABLECAP 5

#define NODEHTABLE_BUFFER(H) (H).buffer
#define NODEHTABLE_LIST(H, idx) (H).buffer[idx]
#define NODEHTABLE_CONTAINER(H) (H).containerNum
#define NODEHTABLE_LENGTH(H) (H).length

int Hash(NodeHashTable H, int a);

void createNodeHashTable(NodeHashTable *H);

boolean isIdInNodeHashTable(NodeHashTable H, int id);

int getIdxInNodeHashTable(NodeHashTable H, NodeBalasanAddress Node);

ListNode getListFromId(NodeHashTable H, int id);

NodeBalasanAddress getNodeInHashTable(NodeHashTable H, int Id);

void addNodeToTable(NodeHashTable *H, NodeBalasanAddress Node);

void removeNodeFromTable(NodeHashTable *H, NodeBalasanAddress Node);

void doubleHTABLESize(NodeHashTable *H);

void dealokasiHTABLE(NodeHashTable *H);

#endif