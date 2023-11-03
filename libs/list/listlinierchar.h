/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* char adalah integer */

#ifndef listlinierchar_H
#define listlinierchar_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi NodeChar : */
typedef struct nodeChar* AddrChar;
typedef struct nodeChar {
    char info;
    AddrChar next;
} NodeChar;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next

AddrChar newNodeChar(char val);

/* Definisi ListLinierChar : */
/* ListLinierChar kosong : FIRST(l) = NULL */
/* Setiap elemen dengan AddrChar p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

typedef AddrChar ListLinierChar;

#define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinierChar(ListLinierChar *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isListLinierCharEmpty(ListLinierChar l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
char getListLinierCharElmt(ListLinierChar l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setListLinierCharElmt(ListLinierChar *l, int idx, char val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfListLinierChar(ListLinierChar l, char val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstListLinierChar(ListLinierChar *l, char val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastListLinierChar(ListLinierChar *l, char val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtListLinierChar(ListLinierChar *l, char val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstListLinierChar(ListLinierChar *l, char *val);
/* I.S. ListLinierChar l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastListLinierChar(ListLinierChar *l, char *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtListLinierChar(ListLinierChar *l, int idx, char *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListLinierChar(ListLinierChar l);
// void printInfo(ListLinierChar l);
/* I.S. ListLinierChar mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthListLinierChar(ListLinierChar l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
ListLinierChar concatListLinierChar(ListLinierChar l1, ListLinierChar l2) ;
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void inverseListLinierChar(ListLinierChar *l);
void copyListLinierChar(ListLinierChar* l1, ListLinierChar* l2);
void deleteAllListLinierChar(ListLinierChar* l);
AddrChar searchPrecListLinierChar(ListLinierChar l, char x) ;
boolean fSearchListLinierChar(ListLinierChar l, AddrChar p) ;
#endif