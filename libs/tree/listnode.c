// #ifndef LISTDIN_H
// #define LISTDIN_H

#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListNode(ListNode *l){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    LISTNODE_NEFF(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listNodeLength(ListNode l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return LISTNODE_NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getListNodeFirstIdx(ListNode l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return LISTNODE_IDX_MIN;
}

IdxType getListNodeLastIdx(ListNode l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return LISTNODE_NEFF(l) - 1;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListNodeEmpty(ListNode l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return LISTNODE_NEFF(l) == 0;
}
/* *** Test list penuh *** */
boolean isListNodeFull(ListNode l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return LISTNODE_NEFF(l) == LISTNODE_CAPACITY;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListNodeEqual(ListNode l1, ListNode l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */  
    if (LISTNODE_NEFF(l1) != LISTNODE_NEFF(l2)){
        return false;
    }
    else{
        int i;
        for(i = 0; i <= getListNodeLastIdx(l1); i++){
            if (LISTNODE_ELMT(l1, i) != LISTNODE_ELMT(l2, i)){
                return false;
            }
        };
        return true;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType listNodeIndexOf(ListNode l, int Id){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    int i = 0;
    boolean found = false;
    while(!found && i <= getListNodeLastIdx(l)){
        if (NODEBALASAN_ID(LISTNODE_ELMT(l, i)) == Id){
            found = true;
        }
        else{i++;}
    }
    if (found) {return i;}
    else {return LISTNODE_IDX_UNDEF;}
}

/* ********** OPERASI LAIN ********** */
void copyListNode(ListNode lIn, ListNode *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int nEff = LISTNODE_NEFF(lIn);
    int i;
    CreateListNode(lOut);
    for(i = 0; i <= nEff - 1; i++){
        LISTNODE_ELMT(*lOut, i) = LISTNODE_ELMT(lIn, i);
    };
    LISTNODE_NEFF(*lOut) = nEff;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertListNode(ListNode *l, ListNodeElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    LISTNODE_ELMT(*l, getListNodeLastIdx(*l) + 1) = val;
    LISTNODE_NEFF(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteListNode(ListNode *l, int Id){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    int id = listNodeIndexOf(*l, Id);
    int i;
    for(i = id; i < getListNodeLastIdx(*l); i++){
        LISTNODE_ELMT(*l, i) = LISTNODE_ELMT(*l, i + 1);
    }
    LISTNODE_NEFF(*l)--;
}

NodeBalasanAddress getNodeFromId(ListNode l, int Id){
    return LISTNODE_ELMT(l, listNodeIndexOf(l, Id));
}

void dealokasiListNode(ListNode *l){
    free(LISTNODE_BUFFER(*l));
    free(l);
}