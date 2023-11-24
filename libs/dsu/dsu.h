
#ifndef DSU_H
#define DSU_H

#include <stdlib.h>
typedef struct
{
    int *parent; 
    int *rank;   
    int size;    
} DSU;

void initializeDSU(DSU *dsu, int size);

int findSet(DSU *dsu, int x);

void unionSets(DSU *dsu, int x, int y);

void destroyDSU(DSU *dsu);

#endif
