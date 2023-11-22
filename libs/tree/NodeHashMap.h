#ifndef NODEHMP_H
#define NODEHMP_H

#include "listNode.h"

typedef struct idnodehashmap{
    ListNode* buffer;
    int containerNum;
    int length;
} NodeHashMap;

#define INITIALHMPCAP 5

#define NODEHMP_BUFFER(H) (H).buffer
#define NODEHMP_LIST(H, idx) (H).buffer[idx]
#define NODEHMP_CONTAINER(H) (H).containerNum
#define NODEHMP_LENGTH(H) (H).length

int Hash(NodeHashMap H, int a);

void createNodeHashMap(NodeHashMap *H);

boolean isIdInHashMap(NodeHashMap H, int id);

int getIdxInHashMap(NodeHashMap H, NodeBalasanAddress Node);

ListNode getListFromId(NodeHashMap H, int id);

NodeBalasanAddress getNodeInHashMap(NodeHashMap H, int Id);

void addNodeToMap(NodeHashMap *H, NodeBalasanAddress Node);

void removeNodeFromMap(NodeHashMap *H, NodeBalasanAddress Node);

void doubleHMPSize(NodeHashMap *H);

#endif