#ifndef BALASANTREE
#define BALASANTREE

#include "nodeBalasan.h"
#include "NodeHashTable.h"

/* Definisi elemen dan koleksi objek */
typedef struct treeofbalasan{
    NodeBalasanAddress master;
    NodeHashTable Nodes;
    int nextId;
} TreeOfBalasan;

/* ********** SELEKTOR ********** */
#define TREE_MASTER(T) (T).master
#define TREE_HTB(T) (T).Nodes
#define TREE_NEXTID(T) (T).nextId

/* ********** KONSTRUKTOR ********** */
void createTree(TreeOfBalasan *T);

int TreeLength(TreeOfBalasan T);

NodeBalasanAddress getNodeInTreeById(TreeOfBalasan T, int Id);

boolean isIdInTree(TreeOfBalasan T, int Id);

int addToTreeAt(TreeOfBalasan *T, Text content, int IdAuthor, int Id);

void deleteTreeNodeAt(TreeOfBalasan *T, int Id);

void dealokasiTree(TreeOfBalasan *T);

#endif
