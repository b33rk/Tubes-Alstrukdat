#include "listdin.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity)
{
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
}

void dealocateList(ListDin *l)
{
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
    /* KAMUS */

    /* ALGORITMA */
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
    free(BUFFER(*l));
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListDin l)
{
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l);
}
/* *** Daya tampung container *** */
/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListDin l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS */

    /* ALGORITMA */
    return IDX_MIN;
}
IdxType getLastIdx(ListDin l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (0 <= i && i < CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..NEFF(l) */
    /* KAMUS */

    /* ALGORITMA */
    return (0 <= i && i < NEFF(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l)
{
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) == 0;
}
/* *** Test list penuh *** */
boolean isFull(ListDin l)
{
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return NEFF(l) == CAPACITY(l);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l)
{
    /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
    /* F.S. List l terdefinisi */
    /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
    /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
    /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
    /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
          0 satu per satu diakhiri enter */
    /*    Jika N = 0; hanya terbentuk l kosong */
    /* KAMUS */
    IdxType n, i;

    /* ALGORITMA */
    scanf("%d", &n);
    while (n < 0 || n > CAPACITY(*l))
    {
        scanf("%d", &n);
    }

    NEFF(*l) = n;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ELMT(*l, i));
    }
}

void printList(ListDin l)
{
    /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
       antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
    di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* KAMUS */
    IdxType i;
    int len;

    /* ALGORITMA */
    len = listLength(l);

    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%d", ELMT(l, i));
        if (i != len - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus)
{
    /* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */
    /* KAMUS */
    IdxType i;
    ListDin lnew;

    /* ALGORITMA */
    CreateListDin(&lnew, NEFF(l1));
    NEFF(lnew) = NEFF(l1);
    if (plus == true)
    {
        for (i = 0; i < NEFF(l1); i++)
        {
            ELMT(lnew, i) = ELMT(l1, i) + ELMT(l2, i);
        }
    }
    else if (plus == false)
    {
        for (i = 0; i < NEFF(l1); i++)
        {
            ELMT(lnew, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    return lnew;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2)
{
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    if (listLength(l1) != listLength(l2))
    {
        return false;
    }
    for (i = 0; i < listLength(l1); i++)
    {
        if (ELMT(l1, i) != ELMT(l2, i))
        {
            return false;
        }
    }

    return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
    /* Jika tidak ada, mengirimkan IDX_UNDEF */
    /* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMT(l, i) == val)
        {
            return i;
        }
    }

    return IDX_UNDEF;
}

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut)
{
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut) = NEFF(lIn);

    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}

int countVal(ListDin l, ElType val)
{
    /* Menghasilkan berapa banyak kemunculan val di l */
    /* Jika l kosong menghasilkan 0 */
    /* KAMUS */
    IdxType i;
    int count;

    /* ALGORITMA */
    count = 0;

    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMT(l, i) == val)
            count++;
    }

    return count;
}

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    /* KAMUS */
    IdxType i, j;
    ElType temp;
    boolean tukar;
    int len;

    /* ALGORITMA */
    /* bubble sort */
    len = listLength(*l);
    for (i = 0; i < len - 1; i++)
    {
        tukar = false;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (asc)
            {
                if (ELMT(*l, j) > ELMT(*l, j + 1))
                {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                    tukar = true;
                }
            }
            else
            {
                if (ELMT(*l, j) < ELMT(*l, j + 1))
                {
                    temp = ELMT(*l, j);
                    ELMT(*l, j) = ELMT(*l, j + 1);
                    ELMT(*l, j + 1) = temp;
                    tukar = true;
                }
            }
        }

        if (tukar == false)
        {
            break;
        }
    }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */

    /* ALGORITMA */
    ELMT(*l, NEFF(*l)) = val;
    NEFF(*l)
    ++;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val)
{
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS */

    /* ALGORITMA */
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)
    --;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandList(ListDin *l, int num)
{
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS */
    ListDin lnew;
    IdxType i;

    /* ALGORITMA */
    CreateListDin(&lnew, CAPACITY(*l) + num);

    for (i = 0; i < NEFF(*l); i++)
    {
        ELMT(lnew, i) = ELMT(*l, i);
    }

    NEFF(lnew) = NEFF(*l);

    dealocateList(l);

    copyList(lnew, l);
}

void shrinkList(ListDin *l, int num)
{
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS */
    ListDin lnew;
    IdxType i;

    /* ALGORITMA */
    CreateListDin(&lnew, CAPACITY(*l) - num);

    for (i = 0; i < NEFF(*l); i++)
    {
        ELMT(lnew, i) = ELMT(*l, i);
    }
    NEFF(lnew) = NEFF(*l);

    dealocateList(l);

    copyList(lnew, l);
}

void compressList(ListDin *l)
{
    /* Proses : Mengubah capacity sehingga capacity = nEff */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran capacity = nEff */
    /* KAMUS */
    ListDin lnew;
    IdxType i;

    /* ALGORITMA */
    CreateListDin(&lnew, NEFF(*l));

    for (i = 0; i < NEFF(*l); i++)
    {
        ELMT(lnew, i) = ELMT(*l, i);
    }

    NEFF(lnew) = NEFF(*l);

    dealocateList(l);

    copyList(lnew, l);
}
