/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* Utas adalah integer */

#ifndef listlinierutas_H
#define listlinierutas_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>

/* Definisi NodeUtas : */
typedef struct elutas
{
    int id;
    int idUser;
    char text[281];
    DATETIME datetime;
} ElUtas;
typedef struct nodeUtas *AddressUtas;
typedef struct nodeUtas
{
    ElUtas info;
    AddressUtas next;
} NodeUtas;

#define INFO(p) (p)->info
#define NEXT(p) (p)->next
typedef AddressUtas Utas;

AddressUtas newNodeUtas(ElUtas val);

/* Definisi Utas : */
/* Utas kosong : FIRST(l) = NULL */
/* Setiap elemen dengan AddressUtas p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */


/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateUtas(Utas *l);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyUtas(Utas l);
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
Utas getElmtUtas(Utas l, int idx);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtUtas(Utas *l, int idx, ElUtas val);
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

// int indexOfUtas(Utas l, Utas val);
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstUtas(Utas *l, ElUtas val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastUtas(Utas *l, ElUtas val);
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtUtas(Utas *l, ElUtas val, int idx);
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstUtas(Utas *l, ElUtas *val);
/* I.S. Utas l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLastUtas(Utas *l, ElUtas *val);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtUtas(Utas *l, int idx, ElUtas *val);
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */

// /****************** PROSES SEMUA ELEMEN LIST ******************/
// void displayList(Utas l);
// // void printInfo(Utas l);
// /* I.S. Utas mungkin kosong */
// /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
// /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
// /* Jika list kosong : menulis [] */
// /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthUtas(Utas l);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
// Utas concat(Utas l1, Utas l2) ;
// /* I.S. l1 dan l2 sembarang */
// /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
// /* Konkatenasi dua buah list : l1 dan l2    */
// /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
// /* Tidak ada alokasi/dealokasi pada prosedur ini */
#endif