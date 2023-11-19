/* File : prioqueuechar.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen prio */

#ifndef prioqueuefriendreq_H
#define prioqueuefriendreq_H

#include "../boolean.h"
#include <stdlib.h>
#include <stdio.h>
/* Konstanta untuk mendefinisikan int tak terdefinisi */

typedef struct
{
    int idUser;
    int manyFriend;
    char userName[21];
} FriendReq;
/* Definisi elemen dan int */
/* Contoh deklarasi variabel bertype PrioQueueFriendReq : */
/* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
typedef struct
{
    FriendReq *T; /* tabel penyimpan elemen */
    int HEAD;     /* alamat penghapusan */
    int TAIL;     /* alamat penambahan */
    int MaxEl;    /* Max elemen queue */
} PrioQueueFriendReq;
/* Definisi PrioQueueFriendReq kosong: HEAD=Nil; TAIL=Nil. */
/* Catatan implementasi: T[0] tidak pernah dipakai */

/* ********* AKSES (Selektor) ********* */
/* Jika e adalah FriendReq dan Q adalah PrioQueueFriendReq, maka akses elemen : */

/* ********* Prototype ********* */
void CreatePrioQueueFR(PrioQueueFriendReq *pQueue, int Max);

boolean IsPrioQueueFREmpty(PrioQueueFriendReq Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsPrioQueueFRFull(PrioQueueFriendReq Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int prioQueueFRNBElmt(PrioQueueFriendReq Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Destruktor *** */
void DeAlokasiPrioQueueFR(PrioQueueFriendReq *Q);
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void EnqueuePrioQueueFR(PrioQueueFriendReq *Q, FriendReq X);
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void DequeuePrioQueueFR(PrioQueueFriendReq *Q, FriendReq *X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueFR(PrioQueueFriendReq Q);
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/

void PrintPrioQueueFRHead(PrioQueueFriendReq Q);

#endif