#include "kelompokteman.h"

void kelompokTeman(){
    int numUser = listUserLength(listUser);

    DSU dsu;
    initializeDSU(&dsu, numUser);

    // Iterasi melalui matriks dan gabungkan set berdasarkan hubungan antar pengguna
    for (int i = 0; i < numUser; ++i) {
        for (int j = 0; j < numUser; ++j) {
            if (graphFriendship.matrix.mem[i][j] == 1) {
                unionSets(&dsu, i, j);
            }
        }
    }

    ListStatikInt members;
    CreateListStatikInt(&members);

    ListStatikInt countMembers;
    CreateListStatikInt(&countMembers);

    int i;
    for (i = 0; i < numUser; ++i) {
        members.contents[i] = i;
        countMembers.contents[i] = 1;
    }

    for (i = 0; i < numUser; ++i) {
        int groupLeader = findSet(&dsu, i);
        int memberIndex = countMembers.contents[groupLeader];
        members.contents[memberIndex] = i;
        countMembers.contents[groupLeader]++;
    }

    int userGroup = findSet(&dsu, currentUser->id);

    ListStatikInt members2;
    CreateListStatikInt(&members2);

    for (i = 0; i < countMembers.contents[userGroup]; ++i) {
        insertLastListStatikInt(&members2, members.contents[i]);
        printf("  Pengguna %d\n", members.contents[i]);
    }

    destroyDSU(&dsu);
    
    
}