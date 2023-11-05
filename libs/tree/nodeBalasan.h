#ifndef NODEBALASAN_H
#define NODEBALASAN_H

#include "listdin.h"
#include "text.h"

/* Definisi elemen dan koleksi objek */

typedef struct nodebalasan* NodeBalasanAddress;
typedef struct nodebalasan {
    int Id;
    int trueId;
    Text content;
    ListDin Children;
    NodeBalasanAddress Parent;
} NodeBalasan;

/* ********** SELEKTOR ********** */
#define NODEBALASAN_ID(N) (N)->Id
#define NODEBALASAN_TRUEID(N) (N)->trueId
#define NODEBALASAN_TEXT(N) (N)->content
#define NODEBALASAN_CHILDREN(N) (N)->Children
#define NODEBALASAN_PARENT(N) (N)->Parent

NodeBalasanAddress newNodeBalasan(int Id, int trueId, Text content, NodeBalasanAddress parent);

void addChildren(NodeBalasanAddress Nparent, int Id, int trueId, Text content);

void removeChildren(NodeBalasanAddress Nparent, NodeBalasanAddress Nchildren);

#endif