#include "text.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateText(Text *T, int capacity){
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    TEXT_BUFFER(*T) = (char*) malloc (capacity * sizeof(char));
    TEXT_CAPACITY(*T) = capacity;
    TEXT_NEFF(*T) = 0;
}

void dealocateText(Text *T){
/* I.S. l terdefinisi; */
/* F.S. (T) dikembalikan ke system, CAPACITY(T)=0; NEFF(T)=0 */
    free(TEXT_BUFFER(*T));
    TEXT_NEFF(*T) = 0;
    TEXT_CAPACITY(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int textLength(Text T){
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return TEXT_NEFF(T);
}

void printText(Text T){
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
    int i = 0;
    for(i = 0; i < TEXT_NEFF(T); i++){
        printf("%c", TEXT_ELMT(T, i));
    }
    printf("\n");
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isTextEqual(Text T1, Text T2){
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika nEff T1 = T2 dan semua elemennya sama */
    if (TEXT_NEFF(T1) != TEXT_NEFF(T2)){
        return false;
    }
    else{
        int i;
        for(i = 0; i < TEXT_NEFF(T1); i++){
            if (TEXT_ELMT(T1, i) != TEXT_ELMT(T2, i)){
                return false;
            }
        };
        return true;
    }
}

/* ********** OPERASI LAIN ********** */
void copyText(Text TIn, Text *TOut){
/* I.S. TIn terdefinisi tidak kosong, TOut sembarang */
/* F.S. TOut berisi salinan dari TIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi TIn ke TOut */ 
    int cap = TEXT_CAPACITY(TIn);
    int nEff = TEXT_NEFF(TIn);
    int i;
    CreateText(TOut, cap);
    for(i = 0; i <= nEff - 1; i++){
        TEXT_ELMT(*TOut, i) = TEXT_ELMT(TIn, i);
    };
    TEXT_NEFF(*TOut) = nEff;
}

int countTextVal(Text T, char val){
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
    int count = 0;
    int i;
    for(i = 0; i < TEXT_NEFF(T); i++){
        if (val == TEXT_ELMT(T, i)){
            count += 1;
        }
    };
    return count;
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */

/* *** Menambahkan elemen terakhir *** */
void insertLastText(Text *T, char val){
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    if (TEXT_CAPACITY(*T) == TEXT_NEFF(*T)) {doubleText(T);}
    TEXT_ELMT(*T, TEXT_NEFF(*T)) = val;
    TEXT_NEFF(*T) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastText(Text *T, char *val){
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = TEXT_ELMT(*T, TEXT_NEFF(*T) - 1);
    TEXT_ELMT(*T, TEXT_NEFF(*T) - 1) = 0;
    TEXT_NEFF(*T) -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandText(Text *T, int num){
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    Text oldT;
    int i;
    copyText(*T, &oldT);
    TEXT_BUFFER(*T) = (char*) malloc ((TEXT_CAPACITY(*T) + num) * sizeof(char));
    TEXT_CAPACITY(*T) += num;
    for(i = 0; i < TEXT_NEFF(*T); i++){
        TEXT_ELMT(*T, i) = TEXT_ELMT(oldT, i);
    }
}

void doubleText(Text *T){
    expandText(T, TEXT_CAPACITY(*T));
}

void shrinkText(Text *T, int num){
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    Text oldT;
    int i;
    copyText(*T, &oldT);
    TEXT_BUFFER(*T) = (char*) malloc ((TEXT_CAPACITY(*T) - num) * sizeof(char));
    TEXT_CAPACITY(*T) -= num;
    for(i = 0; i < TEXT_NEFF(*T); i++){
        TEXT_ELMT(*T, i) = TEXT_ELMT(oldT, i);
    }
}

// int main(){
//     Text bro;
//     CreateText(&bro, 1);
//     int n;
//     char temp;
//     scanf("%d", &n);
//     int i;
//     for(i = 0; i < n; i++){
//         scanf("%c", &temp);
//         insertLastText(&bro, temp);
//     }
//     printText(bro);
// }