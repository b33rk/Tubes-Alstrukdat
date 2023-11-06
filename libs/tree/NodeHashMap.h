#include "listNode.h"

typedef struct idnodehashmap{
    ListNode* buffer;
    int containerNum;
} NodeHashMap;

#define INITIALHMPCAP 5

#define NODEHMP_BUFFER(H) (H).buffer
#define NODEHMP_LIST(H, idx) (H).buffer[idx]
#define NODEHMP_CONTAINER(H) (H).containerNum

int Hash(NodeHashMap H, int a);

void createNodeHashMap(NodeHashMap *H);

int getIdxInHashMap(NodeHashMap H, NodeBalasanAddress Node);

ListNode getListFromId(NodeHashMap H, int id);

NodeBalasanAddress getNodeInHashMap(NodeHashMap H, int Id);

void addNodeToMap(NodeHashMap *H, NodeBalasanAddress Node);

void removeNodeFromMap(NodeHashMap *H, NodeBalasanAddress Node);

void doubleHMPSize(NodeHashMap *H);