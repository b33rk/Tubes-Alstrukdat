// #ifndef LISTDIN_H
// #define LISTDIN_H

#include <stdio.h>
#include <stdlib.h>
#include "listnode.h"

// /*  Kamus Umum */
// #define IDX_MIN 0
// /* Indeks minimum list */
// #define IDX_UNDEF -1
// /* Indeks tak terdefinisi*/

// /* Definisi elemen dan koleksi objek */
// typedef int ElType; /* type elemen list */
// typedef int IdxType;
// typedef struct
// {
//     ElType *buffer; /* memori tempat penyimpan elemen (container) */
//     int nEff;       /* >=0, banyaknya elemen efektif */
//     int capacity;   /* ukuran elemen */
// } ListDin;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDin, cara deklarasi dan akses: */
/* Deklarasi : l : ListDin */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

// /* ********** SELEKTOR ********** */
// #define NEFF(l) (l).nEff
// #define BUFFER(l) (l).buffer
// #define ELMT(l, i) (l).buffer[i]
// #define CAPACITY(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListNode(ListNode *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    LISTNODE_BUFFER(*l) = (int*) malloc (capacity * sizeof(NodeBalasan));
    LISTNODE_CAPACITY(*l) = capacity;
    LISTNODE_LENGTH(*l) = 0;
    LISTNODE_EMPTYIDX(*l) = 0;

    int i;
    for(i = 0; i < capacity; i++){
        LISTNODE_ELMT(*l, i) = NULL;
    }
}

void dealocateListNode(ListNode *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    free(LISTNODE_BUFFER(*l));
    LISTNODE_LENGTH(*l) = 0;
    LISTNODE_CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listNodeLength(ListNode l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return LISTNODE_LENGTH(l);
}

/* *** Selektor INDEKS *** */
IdxType getListNodeFirstIdx(ListNode l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    if (LISTNODE_EMPTYIDX(l) != LISTNODE_IDX_MIN){
        return LISTNODE_IDX_MIN;
    }
    else{
        int i = 0;
        boolean found = false;
        while(i < LISTNODE_LENGTH(l) && !found){
            found = LISTNODE_ELMT(l, i) != NULL;
            if (!found) {i++;}
        }
        return i - 1;
    }
}

IdxType getListNodeFirstEmptyIdx(ListNode l, IdxType start){
/* Mengirimkan indeks elemen l pertama yang kosong*/
    int i;
    for(i = start; i < LISTNODE_LENGTH(l); i++){
        if (ELMT(l, i) == NULL){
            return i;
        }
    }
    return LISTNODE_IDX_UNDEF;
}

IdxType getListNodeLastIdx(ListNode l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    int i;
    for(i = LISTNODE_LENGTH(l) - 1; i >= 0; i--){
        if (ELMT(l, i) != NULL){
            return i;
        }
    }
    return LISTNODE_IDX_UNDEF;
}

/* ********** Test Indeks yang valid ********** */
boolean isListNodeIdxValid(ListNode l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (i >= 0 && i < LISTNODE_LENGTH(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListNodeEmpty(ListNode l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    return (LISTNODE_LENGTH(l) == 0);
}
/* *** Test list penuh *** */
boolean isListNodeFull(ListNode l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (LISTNODE_LENGTH(l) == LISTNODE_CAPACITY(l));
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListNodeEqual(ListNode l1, ListNode l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    if (LISTNODE_LENGTH(l1) != LISTNODE_LENGTH(l2) || LISTNODE_CAPACITY(l1) != LISTNODE_CAPACITY(l2)){
        return false;
    }
    else{
        boolean eq = true;
        int i = 0;
        while(eq && i < LISTNODE_CAPACITY(l1)){
            eq = LISTNODE_ELMT(l1, i) == LISTNODE_ELMT(l2, i);
            i++;
        }
        return eq;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType listNodeIndexOf(ListNode l, ListNodeElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    if (isListNodeEmpty(l)) {
        return LISTDIN_IDX_UNDEF;
    }
    else{
        int i = 0;
        boolean found = false;
        while(!found && i < LISTNODE_CAPACITY(l)){
            if (LISTDIN_ELMT(l, i) == val){
                found = true;
            }
            else{
                i++;
            }
        }
        if (found) {return i;}
        else {return LISTNODE_IDX_UNDEF;}
    }
}

/* ********** OPERASI LAIN ********** */
void copyListNode(ListNode lIn, ListNode *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int cap = LISTNODE_CAPACITY(lIn);
    int i;
    CreateListNode(lOut, cap);
    for(i = 0; i < cap; i++){
        LISTNODE_ELMT(*lOut, i) = LISTNODE_ELMT(lIn, i);
    };
    LISTNODE_LENGTH(*lOut) = LISTNODE_LENGTH(lIn);
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertListNode(ListNode *l, ListNodeElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (isListNodeFull(*l)) {doubleListNode(l);}
    LISTNODE_ELMT(*l, LISTNODE_EMPTYIDX(*l)) = val;
    LISTNODE_EMPTYIDX(*l) = getListNodeFirstEmptyIdx(*l, LISTNODE_EMPTYIDX(*l));
    LISTNODE_LENGTH(*l)++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteListNode(ListNode *l, ListNodeElType *val, IdxType Idx){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = LISTNODE_ELMT(*l, Idx);
    LISTNODE_ELMT(*l, Idx) = NULL;
    LISTNODE_EMPTYIDX(*l) = (Idx < LISTNODE_EMPTYIDX(*l)) ? Idx : LISTNODE_EMPTYIDX(*l);
    LISTNODE_LENGTH(*l)--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListNode(ListNode *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    ListNode oldL;
    int i;
    copyListNode(*l, &oldL);
    LISTNODE_BUFFER(*l) = (NodeBalasanAddress) malloc ((LISTNODE_CAPACITY(*l) + num) * sizeof(NodeBalasan));
    LISTNODE_CAPACITY(*l) += num;
    for(i = 0; i < LISTNODE_CAPACITY(*l); i++){
        LISTNODE_ELMT(*l, i) = LISTNODE_ELMT(oldL, i);
    };
}

void doubleListNode(ListNode *l){
    expandListNode(l, LISTNODE_CAPACITY(*l));
}

void shrinkListNode(ListNode *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    ListNode oldL;
    int i;
    copyListNode(*l, &oldL);
    LISTNODE_BUFFER(*l) = (NodeBalasanAddress) malloc ((LISTNODE_CAPACITY(*l) - num) * sizeof(NodeBalasan));
    LISTNODE_CAPACITY(*l) -= num;
    for(i = 0; i < LISTNODE_CAPACITY(*l); i++){
        LISTNODE_ELMT(*l, i) = LISTNODE_ELMT(oldL, i);
    };
}

void halveListNode(ListNode *l){
    shrinkListNode(l, LISTNODE_CAPACITY(*l)/2);
}

// int main(){
//     ListDin L;
//     CreateListDin(&L, 100);
//     readList(&L);
//     printList(L);
//     sort(&L, true);
//     printf("\nSorted : ");
//     printList(L);
//     printf("\nList Length : %d", listLength(L));
//     printf("\nFirst id : %d", getFirstIdx(L));
//     printf("\nLast id : %d", getLastIdx(L));
//     printf("\nSum : %d", sumList(L));
//     printf("\nIs 20 valid ID : %d", isIdxValid(L, 20));
//     printf("\nIs -1 valid ID : %d", isIdxValid(L, -1));
//     printf("\nIs 100 valid ID : %d", isIdxValid(L, 100));
//     printf("\nIs 99 valid ID : %d", isIdxValid(L, 99));
//     printf("\nIs 5 Eff ID : %d", isIdxEff(L, 5));
//     printf("\nIs -1 Eff ID : %d", isIdxEff(L, -1));
//     printf("\nIs 100 Eff ID : %d", isIdxEff(L, 100));
//     printf("\nIs 99 Eff ID : %d", isIdxEff(L, 99));
//     printf("\nIs empty : %d", isEmpty(L));
//     printf("\nIs full : %d", isFull(L));
//     printf("\n0 appears %d times", countVal(L, 0));
//     int max, min;
//     extremeValues(L, &max, &min);
//     printf("\nMax : %d\nMin : %d", max, min);
//     ListDin res = plusMinusList(L, L, true);
//     printf("\n");
//     printf("Two times L: ");
//     printList(res);
//     return 0;
// }