#include "nodeBalasan.h"
#include "listnode.h"

/* Definisi elemen dan koleksi objek */
typedef struct treeofbalasan{
    NodeBalasanAddress master;
    NodeList ListNode;
    int nextId;
} TreeOfBalasan;

/* ********** SELEKTOR ********** */
#define TREE_MASTER(T) (T).master
#define TREE_LIST(T) (T).ListNode
#define TREE_NODE_BY_ID(T, id) LISTNODE_ELMT(TREE_LIST(T), id)
#define TREE_NEXTID(T) (T).nextId

/* ********** KONSTRUKTOR ********** */
void createTree(TreeOfBalasan *T);

void addToTreeAt(TreeOfBalasan *T, Text txt, int trueId);

void deleteTreeNodeAt(TreeOfBalasan *T, int trueId);

