#include "disjointsetunion.h"

void initDSU(Disjointsetunion *dsu) {
    for (IdxType i = IDX_MIN; i < CAPACITY_USER; i++) {
        dsu->parent[i] = i;
    }
}

int findSet(Disjointsetunion *dsu, IdxType x) {
    if (dsu->parent[x] == x) {
        return x;
    } else {
        dsu->parent[x] = findSet(dsu, dsu->parent[x]);
        return dsu->parent[x];
    }
}

void unionSets(Disjointsetunion *dsu, IdxType x, IdxType y) {
    IdxType rootX = findSet(dsu, x);
    IdxType rootY = findSet(dsu, y);

    if (rootX != rootY) {
        dsu->parent[rootX] = rootY;
    }
}

boolean isSameSet(Disjointsetunion *dsu, IdxType x, IdxType y) {
    return findSet(dsu, x) == findSet(dsu, y);
}