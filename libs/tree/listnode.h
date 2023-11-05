#ifndef LISTNODE_H
#define LISTNODE_H

#include "boolean.h"
#include "nodeBalasan.h"

/*  Kamus Umum */
#define LISTNODE_IDX_MIN 0
/* Indeks minimum list */
#define LISTNODE_IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef NodeBalasanAddress ListNodeElType; /* type elemen list */
typedef int IdxType;
typedef struct
{
    ListNodeElType *buffer; /* memori tempat penyimpan elemen (container) */
    int capacity;   /* ukuran elemen */
    int length;
    int emptyidx;
} ListNode;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListNode, cara deklarasi dan akses: */
/* Deklarasi : l : ListNode */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */
#define LISTNODE_LENGTH(l) (l).length
#define LISTNODE_BUFFER(l) (l).buffer
#define LISTNODE_ELMT(l, i) (l).buffer[i]
#define LISTNODE_CAPACITY(l) (l).capacity
#define LISTNODE_EMPTYIDX(l) (l).emptyidx

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListNode(ListNode *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListNode(ListNode *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listNodeLength(ListNode l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getListNodeFirstIdx(ListNode l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */

IdxType getListNodeFirstEmptyIdx(ListNode l, IdxType start);
/* Mengirimkan indeks elemen l pertama yang kosong*/

IdxType getListNodeLastIdx(ListNode l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isListNodeIdxValid(ListNode l, IdxType i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListNodeEmpty(ListNode l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isListNodeFull(ListNode l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListNodeEqual(ListNode l1, ListNode l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType listNodeIndexOf(ListNode l, ListNodeElType val);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void copyListNode(ListNode lIn, ListNode *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertListNode(ListNode *l, ListNodeElType val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteListNode(ListNode *l, ListNodeElType *val, IdxType Idx);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListNode(ListNode *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void doubleListNode(ListNode *l);

void shrinkListNode(ListNode *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void halveListNode(ListNode *l);

#endif