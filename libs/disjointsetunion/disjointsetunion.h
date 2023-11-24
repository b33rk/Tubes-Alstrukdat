#ifndef DSU_H
#define DSU_H

#include <stdio.h>
#include "../sederhana/user.h"
#include "../list/listuser.h"
#include "../boolean.h"
// #include "../../database/database.h"

typedef struct disjointsetunion {
    int parent[20];
} Disjointsetunion;

void initDSU(Disjointsetunion *dsu);
int findSet(Disjointsetunion *dsu, IdxType x);
void unionSets(Disjointsetunion *dsu, IdxType x, IdxType y);
boolean isSameSet(Disjointsetunion *dsu, IdxType x, IdxType y);

#endif