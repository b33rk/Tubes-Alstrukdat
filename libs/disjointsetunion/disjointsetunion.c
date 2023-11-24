#include "disjointsetunion.h"

void initDSU(Disjointsetunion *dsu) {
    for (IdxType i = IDX_MIN; i < CAPACITY_USER; i++) {
        dsu->parent[i] = i;  // Setiap elemen awalnya merupakan himpunan yang berbeda
    }
}

int findSet(Disjointsetunion *dsu, IdxType x) {
    if (dsu->parent[x] == x) {
        return x;  // x adalah akar himpunan
    } else {
        // Rekursif untuk mencari akar himpunan dari parent x
        dsu->parent[x] = findSet(dsu, dsu->parent[x]);
        return dsu->parent[x];
    }
}

void unionSets(Disjointsetunion *dsu, IdxType x, IdxType y) {
    IdxType rootX = findSet(dsu, x);
    IdxType rootY = findSet(dsu, y);

    if (rootX != rootY) {
        // Gabungkan dua himpunan dengan membuat parent dari satu akar himpunan menjadi yang lain
        dsu->parent[rootX] = rootY;
    }
}

boolean isSameSet(Disjointsetunion *dsu, IdxType x, IdxType y) {
    return findSet(dsu, x) == findSet(dsu, y);
}

// void printTeman() {
//     int currentUserRoot = findSet(&dsu, currentUser->id);
//     int jumlahTeman = 0;
//     for(int i = IDX_MIN; i < CAPACITY_USER; i++) {
//         if (findSet(&dsu, i) == currentUserRoot) {
//             jumlahTeman++;
//         }
//     }
//     printf("Terdapat %s orang dalam Kelompok Teman A :\n\n", currentUser->name);
//     for (int i = IDX_MIN; i < CAPACITY_USER; i++) {
//         if (findSet(&dsu, i) == currentUserRoot) {
//             printf("%s\n", listUser.contents[i].name);
//             jumlahTeman++;
//         }
//         printf("\n\n");
//     }
// }