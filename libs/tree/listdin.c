// /* MODUL INTEGER DYNAMIC LIST */
// /* Berisi definisi dan semua primitif pemrosesan list integer */
// /* Penempatan elemen selalu rapat kiri */
// /* Versi II : dengan banyaknya elemen didefinisikan secara eksplisit,
//    memori list dinamik */

// #ifndef LISTDIN_H
// #define LISTDIN_H

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"

// /*  Kamus Umum */
// #define IDX_MIN 0
// /* Indeks minimum list */
// #define LISTDIN_IDX_UNDEF -1
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
void CreateListDin(ListDin *l, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    LISTDIN_BUFFER(*l) = (int*) malloc (capacity * sizeof(int));
    LISTDIN_CAPACITY(*l) = capacity;
    LISTDIN_NEFF(*l) = 0;
}

void dealocateListDin(ListDin *l){
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    free(LISTDIN_BUFFER(*l));
    LISTDIN_NEFF(*l) = 0;
    LISTDIN_CAPACITY(*l) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinLength(ListDin l){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return LISTDIN_NEFF(l);
}

/* *** Selektor INDEKS *** */
IdxType getListDinFirstIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return LISTDIN_IDX_MIN;
}
IdxType getListDinLastIdx(ListDin l){
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return (LISTDIN_NEFF(l) - 1); 
}

/* ********** Test Indeks yang valid ********** */
boolean isListDinIdxValid(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    int capacity = LISTDIN_CAPACITY(l);
    return (i >= 0) && (i < capacity);
}
boolean isListDinIdxEff(ListDin l, IdxType i){
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return (i >= 0) && (i < LISTDIN_NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinEmpty(ListDin l){
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return (LISTDIN_NEFF(l) == 0);
}
boolean isListDinFull(ListDin l){
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return (LISTDIN_CAPACITY(l) == LISTDIN_NEFF(l));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
    int N;
    scanf("%d", &N);
    while (N < 0 || N > LISTDIN_CAPACITY(*l)){
        scanf("%d", &N);
    }
    int i, el;
    for(i = 0; i <= N - 1; i++){
        scanf("%d", &el);
        LISTDIN_ELMT(*l, i) = el;
    };
    LISTDIN_NEFF(*l) = N;
}

void printListDin(ListDin l){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    if (isListDinEmpty(l)){
        printf("[]");
        return;
    }
    else{
        int i;
        printf("[");
        for(i = 0; i < getListDinLastIdx(l); i++){
            printf("%d,", LISTDIN_ELMT(l, i));
        };
        printf("%d]", LISTDIN_ELMT(l, getListDinLastIdx(l)));
    }
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListDinEqual(ListDin l1, ListDin l2){
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    if (LISTDIN_NEFF(l1) != LISTDIN_NEFF(l2)){
        return false;
    }
    else{
        int i;
        for(i = 0; i <= getListDinLastIdx(l1); i++){
            if (LISTDIN_ELMT(l1, i) != LISTDIN_ELMT(l2, i)){
                return false;
            }
        };
        return true;
    }
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType listDinIndexOf(ListDin l, ElType val){
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan LISTDIN_IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (LISTDIN_IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    if (isListDinEmpty(l)) {
        return LISTDIN_IDX_UNDEF;
    }
    else{
        int i;
        for(i = 0; i <= getListDinLastIdx(l); i++){
            if (LISTDIN_ELMT(l, i) == val){
                return i;
            }
        };
        return LISTDIN_IDX_UNDEF;
    }
}

/* ********** NILAI EKSTREM ********** */
void listDinExtremeValues(ListDin l, ElType *max, ElType *min){
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */
    int i, el;
    *max = LISTDIN_ELMT(l, getListDinFirstIdx(l));
    *min = LISTDIN_ELMT(l, getListDinFirstIdx(l));
    for(i = 0; i <= getListDinLastIdx(l); i++){
        el = LISTDIN_ELMT(l, i);
        if (el > *max){
            *max = el;
        }
        if (el < *min){
            *min = el;
        }
    };
}

/* ********** OPERASI LAIN ********** */
void copyListDin(ListDin lIn, ListDin *lOut){
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 
    int cap = LISTDIN_CAPACITY(lIn);
    int nEff = LISTDIN_NEFF(lIn);
    int i;
    CreateListDin(lOut, cap);
    for(i = 0; i <= nEff - 1; i++){
        LISTDIN_ELMT(*lOut, i) = LISTDIN_ELMT(lIn, i);
    };
    LISTDIN_NEFF(*lOut) = nEff;
}
ElType sumListDin(ListDin l){
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
    int sum = 0;
    int i;
    for(i = 0; i <= getListDinIdx(l); i++){
        sum += LISTDIN_ELMT(l, i);
    };
    return sum;
}
int countListDinVal(ListDin l, ElType val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    int count = 0;
    int i;
    for(i = 0; i <= getListDinLastIdx(l); i++){
        if (val == LISTDIN_ELMT(l, i)){
            count += 1;
        }
    };
    return count;
}

/* ********** SORTING ********** */
void sortListDin(ListDin *l, boolean asc){
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
    int faktor = 2*asc - 1;
    int pass = LISTDIN_NEFF(*l) - 1;
    int i, temp, outer;
    for(outer = 1; outer <= pass; outer ++){
        for(i = 0; i < getListDinLastIdx(*l); i++){
            if (faktor*LISTDIN_ELMT(*l, i) > faktor*LISTDIN_ELMT(*l, i + 1)){
                temp = LISTDIN_ELMT(*l, i);
                LISTDIN_ELMT(*l, i) = LISTDIN_ELMT(*l, i+1);
                LISTDIN_ELMT(*l, i+1) = temp;
            }
        };
    };
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDin(ListDin *l, ElType val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    LISTDIN_ELMT(*l, LISTDIN_NEFF(*l)) = val;
    LISTDIN_NEFF(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDin(ListDin *l, ElType *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = LISTDIN_ELMT(*l, LISTDIN_NEFF(*l) - 1);
    LISTDIN_ELMT(*l, LISTDIN_NEFF(*l) - 1) = 0;
    LISTDIN_NEFF(*l) -= 1;
}

void deleteElListDin(ListDin *l, ElType val){
    int i;
    boolean found = false;
    for(i = 0; i < LISTDIN_NEFF(*l) - 1; i++){
        if (LISTDIN_ELMT(*l, i) == val){
            found = true;
        }
        if (found){
            LISTDIN_ELMT(*l, i) = LISTDIN_ELMT(*l, i + 1);
        }
    }
    LISTDIN_NEFF(*l) -= found;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDin(ListDin *l, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    ListDin oldL;
    int i;
    copyListDin(*l, &oldL);
    LISTDIN_BUFFER(*l) = (int*) malloc ((LISTDIN_CAPACITY(*l) + num) * sizeof(int));
    LISTDIN_CAPACITY(*l) += num;
    for(i = 0; i <= getListDinLastIdx(oldL); i++){
        LISTDIN_ELMT(*l, i) = LISTDIN_ELMT(oldL, i);
    };
}

void doubleListDin(ListDin *l){
    expandListDin(l, LISTDIN_CAPACITY(*l));
}

void shrinkListDin(ListDin *l, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    ListDin oldL;
    int i;
    copyListDin(*l, &oldL);
    LISTDIN_BUFFER(*l) = (int*) malloc ((LISTDIN_CAPACITY(*l) - num) * sizeof(int));
    LISTDIN_CAPACITY(*l) -= num;
    for(i = 0; i <= getListDinLastIdx(oldL); i++){
        LISTDIN_ELMT(*l, i) = LISTDIN_ELMT(oldL, i);
    };
}

void compressListDin(ListDin *l){
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
    ListDin oldL;
    int i;
    copyListDin(*l, &oldL);
    LISTDIN_BUFFER(*l) = (int*) malloc (LISTDIN_NEFF(*l) * sizeof(int));
    LISTDIN_CAPACITY(*l) = LISTDIN_NEFF(*l);
    for(i = 0; i <= getListDinLastIdx(oldL); i++){
        LISTDIN_ELMT(*l, i) = LISTDIN_ELMT(oldL, i);
    };
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