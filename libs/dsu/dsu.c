#include "dsu.h"

void initializeDSU(DSU *dsu, int size) {
    dsu->parent = (int *)malloc(size * sizeof(int));
    dsu->rank = (int *)malloc(size * sizeof(int));
    dsu->size = size;

    for (int i = 0; i < size; ++i) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
}

int findSet(DSU *dsu, int x) {
    if (dsu->parent[x] != x) {
        dsu->parent[x] = findSet(dsu, dsu->parent[x]); 
    }
    return dsu->parent[x];
}

void unionSets(DSU *dsu, int x, int y) {
    int rootX = findSet(dsu, x);
    int rootY = findSet(dsu, y);

    if (dsu->rank[rootX] < dsu->rank[rootY]) {
        dsu->parent[rootX] = rootY;
    } else if (dsu->rank[rootX] > dsu->rank[rootY]) {
        dsu->parent[rootY] = rootX;
    } else {
        dsu->parent[rootY] = rootX;
        dsu->rank[rootX]++;
    }
}

void destroyDSU(DSU *dsu) {
    free(dsu->parent);
    free(dsu->rank);
    dsu->size = 0;
}


