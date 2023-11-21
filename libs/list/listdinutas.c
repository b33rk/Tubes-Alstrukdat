#include "listdinutas.h"

AddrUtas newNodeUtas(ElTypeUtas val) {
    AddrUtas p = (AddrUtas) malloc(sizeof(NodeUtas));

    if (p != NULL) {
        p->info = val;
        p->next = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateUtas(Utas *l) {
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
    (*l).first = NULL;
    (*l).IDKicau = -1;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyUtas(Utas l) {
/* Mengirim true jika list kosong */
    return l.first == NULL;
}

/****************** GETTER SETTER ******************/
ElTypeUtas getElmtUtas(Utas l, int idxUtas) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */
    AddrUtas p = l.first;
    int ctr = 0;

    while (ctr < idxUtas) {
        p = p->next;
        ctr++;
    }
    return p->info;
}

void setElmtUtas(Utas *l, int idxUtas, ElTypeUtas val) {
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    AddrUtas p = (*l).first;
    int ctr = 0;

    while (ctr < idxUtas) {
        p = p->next;
        ctr++;
    }
    p->info = val;
}

boolean isElTypeUtasEqual(ElTypeUtas l1, ElTypeUtas l2) {
    return l1.author == l2.author && DEQ(l1.datetime, l2.datetime); // tentu datetime pasti unik
}

int indexOfUtas(Utas l, ElTypeUtas val) {
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen Utas l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */
    AddrUtas p = l.first;
    boolean found = false;
    int idx = 0;

    while (!found && p != NULL) {
        if (isElTypeUtasEqual(p->info, val)) {
            found = true;
        } else {
            idx++;
            p = NEXT(p);
        }
    }

    if (found) {
        return idx;
    } else {
        return -1;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstUtas(Utas *l, ElTypeUtas val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */
    AddrUtas p = newNodeUtas(val);

    if (p != NULL) {
        p->next = (*l).first;
        (*l).first = p;
    }
}

void insertLastUtas(Utas *l, ElTypeUtas val) {
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (isEmptyUtas(*l)) {
        insertFirstUtas(l, val);
    } else {
        AddrUtas p = newNodeUtas(val);
        if (p != NULL) {
            AddrUtas last = (*l).first;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = p;
        }
    }
}

void insertAtUtas(Utas *l, ElTypeUtas val, int idx) {
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    if (idx == 0) {
        insertFirstUtas(l, val);
    } else {
        AddrUtas p = newNodeUtas(val);
        if (p != NULL) {
            int ctr = 0;
            AddrUtas loc = (*l).first;
            while (ctr < idx - 1) {
                loc = loc->next;
                ctr++;
            }
            p->next = loc->next;
            loc->next = p;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstUtas(Utas *l, ElTypeUtas *val) {
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
    AddrUtas p = (*l).first;
    *val = INFO(p);
    (*l).first = NEXT(p);
    free(p);
}

void deleteLastUtas(Utas *l, ElTypeUtas *val) {
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */
    AddrUtas p = (*l).first;
    AddrUtas loc = NULL;
    while (p->next != NULL) {
        loc = p;
        p = p->next;
    }
    if (loc == NULL) {
        (*l).first = NULL;
    } else {
        loc->next = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAtUtas(Utas *l, int idx, ElTypeUtas *val) {
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */
    if (idx == 0) {
        deleteFirstUtas(l, val);
    } else {
        int ctr = 0;
        AddrUtas loc = (*l).first;
        while (ctr < idx - 1) {
            ctr++;
            loc = loc->next;
        }
        AddrUtas p = loc->next;
        *val = p->info;
        loc->next = p->next;
        free(p);
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
// void displayUtasAboveIdx1(Utas l) {
//     // BELUM COBA PRINT KICAU
//     AddrUtas p = l.first;

//     int idx = 1;
//     while (p != NULL) {
//         printf("\n  | INDEX = %d\n", idx);
//         printf("  | \n", p->info.author);
//         printf("  | "); TulisDATETIME(p->info.datetime); printf("\n");
//         printf("  | %s", p->info.text);

//         p = p->next;
//     }
// }

int lengthUtas(Utas l) {
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    AddrUtas p = l.first;
    int ctr = 0;
    while (p != NULL) {
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDinUtas(ListDinUtas *l, int capacity) {
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    ((*l).buffer) = (Utas*) malloc(capacity*sizeof(Utas));
    (*l).capacity = capacity;
    (*l).nEff = 0;
}

void dealocateListDinUtas(ListDinUtas *l) {
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    (*l).capacity = 0;
    (*l).nEff = 0;
    free((*l).buffer);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinUtasLength(ListDinUtas l) {
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
    return l.nEff;
}

/* *** Selektor INDEKS *** */
int getFirstIdxListDinUtas(ListDinUtas l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
    return 0;
}

int getLastIdxListDinUtas(ListDinUtas l) {
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */
    return l.nEff - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValidListDinUtas(ListDinUtas l, int i) {
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
    return (0<=i && i<=l.capacity);
}

boolean isIdxEffListDinUtas(ListDinUtas l, int i) {
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */
    return (0<=i && i<l.nEff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmptyListDinUtas(ListDinUtas l) {
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
    return l.nEff == 0;
}

boolean isFullListDinUtas(ListDinUtas l) {
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    return l.nEff == l.capacity;
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readListListDinUtas(ListDinUtas *l);
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */

void printList(ListDinUtas l);
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDinUtas plusMinusListDinUtas(ListDinUtas l1, ListDinUtas l2, boolean plus);
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqualListDinUtas(ListDinUtas l1, ListDinUtas l2);
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int indexOfListDinUtasByIDKicau(ListDinUtas l, int IDKicau) {
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */
    int i;

    if (l.nEff == 0) {
        return -1;
    } else {
        for (i=0;i<l.nEff;i++) {
            if (l.buffer[i].IDKicau == IDKicau) {
                return i;
            }
        }
    }
    return -1;
}

/* ********** NILAI EKSTREM ********** */
void extremeValuesListDinUtas(ListDinUtas l, Utas *max, Utas *min);
/* I.S. List l tidak kosong */
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyListDinUtas(ListDinUtas lIn, ListDinUtas *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */ 

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinUtas(ListDinUtas *l, Utas val) {
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
    (*l).buffer[(*l).nEff] = val;
    (*l).nEff += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinUtas(ListDinUtas *l, Utas *val) {
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
    *val = (*l).buffer[getLastIdxListDinUtas(*l)];
    (*l).nEff -= 1;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinUtas(ListDinUtas *l, int num) {
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
    (*l).capacity += num;
}

void shrinkListDinUtas(ListDinUtas *l, int num) {
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */
    (*l).capacity -= num;
}

void compressListDinUtas(ListDinUtas *l) {
/* Proses : Mengubah capacity sehingga capacity = nEff */
/* I.S. List tidak kosong */
/* F.S. Ukuran capacity = nEff */
    (*l).capacity = (*l).nEff;
}