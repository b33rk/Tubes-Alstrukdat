/* MODUL INTEGER DYNAMIC LIST */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
   memori list dinamik */

#ifndef LISTDINKICAU_H
#define LISTDINKICAU_H

#include "../boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "../datetime.h"

typedef struct
{
   int id;
   int idUser;
   char text[281];
   int like;
   DATETIME datetime;
   int idUtas;
} Kicauan;

typedef struct
{
   Kicauan *buffer; /* memori tempat penyimpan elemen (container) */
   int nEff;        /* >=0, banyaknya elemen efektif */
   int capacity;    /* ukuran elemen */
   int idCount;
} ListDinKicau;
/* Indeks yang digunakan [0..capacity-1] */
/* Jika l adalah : ListDinKicau, cara deklarasi dan akses: */
/* Deklarasi : l : ListDinKicau */
/* Maka cara akses:
   l.nEff      untuk mengetahui banyaknya elemen
   l.buffer    untuk mengakses seluruh nilai elemen list
   l.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
  list kosong: l.nEff = 0
  Definisi elemen pertama : l.buffer[i] dengan i=0
  Definisi elemen terakhir yang terdefinisi: l.buffer[i] dengan i=l.capacity */

/* ********** SELEKTOR ********** */


void CreateKicauan(Kicauan *k);

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinKicau(ListDinKicau *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocateListDinKicau(ListDinKicau *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinKicauLength(ListDinKicau l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
int getListDinKicauFirstIdx(ListDinKicau l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
int getListDinKicauLastIdx(ListDinKicau l);
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isListDinKicauIdxValid(ListDinKicau l, int i);
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isListDinKicauIdxEff(ListDinKicau l, int i);
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinKicauEmpty(ListDinKicau l);
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isListDinKicauFull(ListDinKicau l);
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListDinKicau(ListDinKicau *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void printListDinKicau(ListDinKicau l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
// boolean isListDinKicauEqual(ListDinKicau l1, ListDinKicau l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int indexOfListDinKicauById(ListDinKicau l, int idKicau);
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** OPERASI LAIN ********** */
void copyListDinKicau(ListDinKicau lIn, ListDinKicau *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

/* ********** SORTING ********** */
void sortListDinKicauByDateTime(ListDinKicau *l, boolean asc);
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinKicau(ListDinKicau *l, Kicauan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinKicau(ListDinKicau *l, Kicauan *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinKicau(ListDinKicau *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkListDinKicau(ListDinKicau *l, int num);
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compressListDinKicau(ListDinKicau *l);
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */

#endif