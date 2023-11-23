#ifndef NODEBALASAN_H
#define NODEBALASAN_H

#include "../list/listdin.h"
#include "../machine/wordmachine.h"
#include "../machine/textmachine.h"
#include "../sederhana/datetime.h"

/* Definisi elemen dan koleksi objek */

typedef struct nodebalasan* NodeBalasanAddress;
typedef struct nodebalasan {
    int Id;
    int IdAuthor;
    Text content;
    DATETIME time;
    ListDin Children;
    NodeBalasanAddress Parent;
} NodeBalasan;

/* ********** SELEKTOR ********** */
#define NODEBALASAN_ID(N) (N)->Id
#define NODEBALASAN_TEXT(N) (N)->content
#define NODEBALASAN_IDAUTHOR(N) (N)->IdAuthor
#define NODEBALASAN_TIME(N) (N)->time
#define NODEBALASAN_CHILDREN(N) (N)->Children
#define NODEBALASAN_PARENT(N) (N)->Parent

NodeBalasanAddress newNodeBalasan(int Id, Text content, int IdAuthor, NodeBalasanAddress parent);

void addChildren(NodeBalasanAddress Nparent, NodeBalasanAddress Nchildren);

void removeChildren(NodeBalasanAddress Nparent, NodeBalasanAddress Nchildren);

void dealokasiNodeBalasan(NodeBalasanAddress Node);

#endif