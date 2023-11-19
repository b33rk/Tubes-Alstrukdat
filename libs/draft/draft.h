#ifndef DRAFT_H
#define DRAFT_H

#include "../boolean.h"
#include "../../kicauan.h"
#include <stdio.h>
#include "../machine/textmachine.h"
#include <time.h>

#define NIL NULL
#define Nil -1
#define MaxEl 100
#define Max 400

typedef struct node* Address;

typedef struct {
  Text k; /* tabel penyimpan elemen */
  time_t datetime;  /* alamat TOP: elemen puncak */
} Draft;

typedef Draft ElType;
typedef int address; 

typedef struct stack { 
    Draft T[MaxEl];
    address TOP;
} StackDraft; 

/* Selektor */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Teks(D) (D).k
#define Date(D) (D).datetime

void CopyText(Text k, Draft *D);

void CreateEmptyStack(StackDraft *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(StackDraft S);
/* Mengirim true jika StackDraft kosong: lihat definisi di atas */
boolean IsFullStack(StackDraft S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackDraft ************ */
void PushStack(StackDraft * S, Draft X);
/* Menambahkan X sebagai elemen StackDraft S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackDraft ************ */
void PopStack(StackDraft * S, Draft* X);
/* Menghapus X dari StackDraft S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */



#endif