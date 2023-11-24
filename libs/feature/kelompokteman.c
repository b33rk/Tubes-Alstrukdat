#include "kelompokteman.h"

// void printKelompokTeman() {
//     int currentUserRoot = findSet(&dsu, currentUser->id);
//     int jumlahTeman = 0;
//     for(int i = IDX_MIN; i < CAPACITY_USER; i++) {
//         if ((findSet(&dsu, i) == currentUserRoot) && (i != currentUser->id)) {
//             jumlahTeman++;
//         }
//     }
//     printf("Terdapat %d orang dalam Kelompok Teman %s :\n", jumlahTeman, currentUser->name);
//     for (int i = IDX_MIN; i < CAPACITY_USER; i++) {
//         if ((findSet(&dsu, i) == currentUserRoot) && (i != currentUser->id)) {
//             printf("%s\n", listUser.contents[i].name);
//         }
//     }
// }

void printKelompokTeman() {
    int currentUserRoot = findSet(&dsu, currentUser->id);
    int jumlahTeman = 0;

    // Menggunakan graphFriendship untuk menemukan teman langsung
    for (int i = IDX_MIN; i < CAPACITY_USER; i++) {
        if (isHasRelation(graphFriendship, currentUser->id, listUser.contents[i].id) && (i != currentUser->id)) {
            jumlahTeman++;
        }
    }

    // Menggunakan DSU untuk menemukan teman tidak langsung
    for (int i = IDX_MIN; i < CAPACITY_USER; i++) {
        if ((findSet(&dsu, i) == currentUserRoot) && (i != currentUser->id)) {
            jumlahTeman++;
        }
    }

    printf("Terdapat %d orang dalam Kelompok Teman %s :\n", jumlahTeman, currentUser->name);

    for (int i = IDX_MIN; i < CAPACITY_USER; i++) {
        if (isHasRelation(graphFriendship, currentUser->id, listUser.contents[i].id) && (i != currentUser->id)) {
            printf("%s\n", listUser.contents[i].name);
        }
    } 

    for (int i = IDX_MIN; i < CAPACITY_USER; i++) {
        if ((findSet(&dsu, i) == currentUserRoot) && (i != currentUser->id)) {
            printf("%s\n", listUser.contents[i].name);
        }
    }   
}