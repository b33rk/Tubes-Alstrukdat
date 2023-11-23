#include <stdlib.h>

typedef struct {
    int *parent; // array untuk menyimpan representatif set
    int *rank;   // array untuk menyimpan peringkat set
    int size;    // jumlah elemen dalam DSU
} DSU;

// Fungsi untuk inisialisasi DSU dengan size elemen
void initializeDSU(DSU *dsu, int size) {
    dsu->parent = (int *)malloc(size * sizeof(int));
    dsu->rank = (int *)malloc(size * sizeof(int));
    dsu->size = size;

    // Inisialisasi setiap elemen sebagai set terpisah dengan peringkat 0
    for (int i = 0; i < size; ++i) {
        dsu->parent[i] = i;
        dsu->rank[i] = 0;
    }
}

// Fungsi untuk mencari representatif (leader) dari set yang mengandung elemen x
int findSet(DSU *dsu, int x) {
    // Jika elemen x bukan merupakan representatif set itu sendiri, rekursif mencari ke atas
    if (dsu->parent[x] != x) {
        dsu->parent[x] = findSet(dsu, dsu->parent[x]); // Path compression
    }
    return dsu->parent[x];
}

// Fungsi untuk menggabungkan dua set yang mengandung elemen x dan y
void unionSets(DSU *dsu, int x, int y) {
    int rootX = findSet(dsu, x);
    int rootY = findSet(dsu, y);

    // Union berdasarkan peringkat (rank)
    if (dsu->rank[rootX] < dsu->rank[rootY]) {
        dsu->parent[rootX] = rootY;
    } else if (dsu->rank[rootX] > dsu->rank[rootY]) {
        dsu->parent[rootY] = rootX;
    } else {
        dsu->parent[rootY] = rootX;
        dsu->rank[rootX]++;
    }
}

// Fungsi untuk membebaskan memori yang dialokasikan untuk DSU
void destroyDSU(DSU *dsu) {
    free(dsu->parent);
    free(dsu->rank);
    dsu->size = 0;
}
