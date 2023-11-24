#include "listdinutas.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */


void CreateListDinUtas(ListDinUtas *l, int capacity)
{
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS */

    /* ALGORITMA */
    l->capacity = capacity;
    l->nEff = 0;
    l->buffer = (Utas *)malloc(capacity * sizeof(Utas));
    l->idCount = 1;
}

void dealocateListDinUtas(ListDinUtas *l)
{
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, l.capacity=0; l.nEff=0 */
    /* KAMUS */

    /* ALGORITMA */
    int len = listDinUtasLength(*l);
    int i;

    for (i = 0; i < len; i++){
        Utas u = (*l).buffer[i];
        deleteAllUtas(&u);
    }
    l->capacity = 0;
    l->nEff = 0;
    
    free(l->buffer);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinUtasLength(ListDinUtas l)
{
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff;
}
/* *** Daya tampung container *** */
/* *** Selektor INDEKS *** */
int getListDinUtasFirstIdx(ListDinUtas l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS */

    /* ALGORITMA */
    return 0;
}
int getListDinUtasLastIdx(ListDinUtas l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isListDinUtasIdxValid(ListDinUtas l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (0 <= i && i < l.capacity);
}
boolean isListDinUtasIdxEff(ListDinUtas l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..l.nEff */
    /* KAMUS */

    /* ALGORITMA */
    return (0 <= i && i < l.nEff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinUtasEmpty(ListDinUtas l)
{
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff == 0;
}
/* *** Test list penuh *** */
boolean isListDinUtasFull(ListDinUtas l)
{
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff == l.capacity;
}

void copyListDinUtas(ListDinUtas lIn, ListDinUtas *lOut)
{
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    CreateListDinUtas(lOut, lIn.capacity);
    lOut->nEff = lIn.nEff;

    for (i = 0; i < lIn.nEff; i++)
    {
        Utas temp;
        CreateUtas(&temp);

        temp = lIn.buffer[i];

        insertLastListDinUtas(lOut, temp);
    }
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
// void readListDinUtas(ListDinUtas *l)
// {
//     /* I.S. l sembarang dan sudah dialokasikan sebelumnya */
//     /* F.S. List l terdefinisi */
//     /* Proses : membaca banyaknya elemen l dan mengisi nilainya */
//     /* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
//     /*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= l.capacity */
//     /*    Jika N tidak valid, tidak diberikan pesan kesalahan */
//     /* 2. Jika 0 < N <= l.capacity; Lakukan N kali: Baca elemen mulai dari indeks
//           0 satu per satu diakhiri enter */
//     /*    Jika N = 0; hanya terbentuk l kosong */
//     /* KAMUS */
//     int n, i;

//     /* ALGORITMA */
//     scanf("%d", &n);
//     while (n < 0 || n > CAPACITY(*l))
//     {
//         scanf("%d", &n);
//     }

//     l->nEff = n;

//     for (i = 0; i < n; i++)
//     {
//         scanf("%d", &l->buffer[i]);
//     }
// }

// void printListDinUtas(ListDinUtas l)
// {
//     /* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
//        antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
//     di tengah, atau di belakang, termasuk spasi dan enter */
//     /* I.S. l boleh kosong */
//     /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
//     /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
//     /* Jika list kosong : menulis [] */
//     /* KAMUS */
//     int i;
//     int len;

//     /* ALGORITMA */
//     len = listLength(l);

//     printf("[");
//     for (i = 0; i < len; i++)
//     {
//         printf("%d", ELMT(l, i));
//         if (i != len - 1)
//         {
//             printf(",");
//         }
//     }
//     printf("]");
// }

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */

/* ********** SEARCHING ********** */
// /* ***  Perhatian : list boleh kosong!! *** */
// int indexOfListDinUtasById(ListDinUtas l, int idUtas)
// {
//     /* Search apakah ada elemen List l yang bernilai val */
//     /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
//     /* Jika tidak ada, mengirimkan -1 */
//     /* Menghasilkan indeks tak terdefinisi (-1) jika List l kosong */
//     /* Skema Searching yang digunakan bebas */
//     /* KAMUS */
//     int i;

//     /* ALGORITMA */
//     for (i = 0; i < l.nEff; i++)
//     {
//         if (l.buffer[i].id == idUtas)
//         {
//             return i;
//         }
//     }

//     return -1;
// }

/* ********** SORTING ********** */
// void sortListDinUtasByDateTime(ListDinUtas *l, boolean asc)
// {
//     /* I.S. l boleh kosong */
//     /* F.S. Jika asc = true, l terurut membesar */
//     /*      Jika asc = false, l terurut mengecil */
//     /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//        algoritma bebas */
//     /* KAMUS */
//     int i, j;
//     Utas temp;
//     boolean tukar;
//     int len;

//     /* ALGORITMA */
//     /* bubble sort */
//     len = listDinUtasLength(*l);
//     for (i = 0; i < len - 1; i++)
//     {
//         tukar = false;
//         for (j = 0; j < len - 1 - i; j++)
//         {
//             if (asc)
//             {
//                 if (DGT(l->buffer[j].datetime, l->buffer[j + 1].datetime))
//                 {
//                     temp = l->buffer[j];
//                     l->buffer[j] = l->buffer[j+1];
//                     l->buffer[j+1] = temp;
//                     tukar = true;
//                 }
//             }
//             else
//             {
//                 if (DLT(l->buffer[j].datetime, l->buffer[j + 1].datetime))
//                 {
//                     temp = l->buffer[j];
//                     l->buffer[j] = l->buffer[j+1];
//                     l->buffer[j+1] = temp;
//                     tukar = true;
//                 }
//             }
//         }

//         if (tukar == false)
//         {
//             break;
//         }
//     }
// }

// void sortListDinUtasById(ListDinUtas *l, boolean asc)
// {
//     /* I.S. l boleh kosong */
//     /* F.S. Jika asc = true, l terurut membesar */
//     /*      Jika asc = false, l terurut mengecil */
//     /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
//        algoritma bebas */
//     /* KAMUS */
//     int i, j;
//     Utas temp;
//     boolean tukar;
//     int len;

//     /* ALGORITMA */
//     /* bubble sort */
//     len = listDinUtasLength(*l);
//     for (i = 0; i < len - 1; i++)
//     {
//         tukar = false;
//         for (j = 0; j < len - 1 - i; j++)
//         {
//             if (asc)
//             {
//                 if (l->buffer[j].id > l->buffer[j+1].id)
//                 {
//                     temp = l->buffer[j];
//                     l->buffer[j] = l->buffer[j+1];
//                     l->buffer[j+1] = temp;
//                     tukar = true;
//                 }
//             }
//             else
//             {
//                 if (l->buffer[j].id < l->buffer[j+1].id)
//                 {
//                     temp = l->buffer[j];
//                     l->buffer[j] = l->buffer[j+1];
//                     l->buffer[j+1] = temp;
//                     tukar = true;
//                 }
//             }
//         }

//         if (tukar == false)
//         {
//             break;
//         }
//     }
// }

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinUtas(ListDinUtas *l, Utas val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */

    /* ALGORITMA */
    if (l->nEff < l->capacity)
    {
        l->buffer[l->nEff] = val;
        l->nEff++;
    } else {
        expandListDinUtas(l, l->capacity);
        l->buffer[l->nEff] = val;
        l->nEff++;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinUtas(ListDinUtas *l, Utas *val)
{
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS */

    /* ALGORITMA */
    *val = l->buffer[getListDinUtasLastIdx(*l)];
    l->nEff--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinUtas(ListDinUtas *l, int num)
{
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS */
    // ListDinUtas lnew;
    // int i;

    // /* ALGORITMA */
    // CreateListDinUtas(&lnew, l->capacity + num);

    // for (i = 0; i < l->nEff; i++)
    // {
    //     lnew.buffer[i] = l->buffer[i];
    // }

    // lnew.nEff = l->nEff;

    // dealocateListDinUtas(l);

    // copyListDinUtas(lnew, l);
    l->capacity = l->capacity + num;
    l->buffer = (Utas *)realloc(l->buffer, l->capacity *sizeof(Utas));
}

void shrinkListDinUtas(ListDinUtas *l, int num)
{
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS */
    ListDinUtas lnew;
    int i;

    /* ALGORITMA */
    CreateListDinUtas(&lnew, l->capacity - num);

    for (i = 0; i < l->nEff; i++)
    {
        lnew.buffer[i] = l->buffer[i];
    }
    lnew.nEff = l->nEff;

    dealocateListDinUtas(l);

    copyListDinUtas(lnew, l);
}

void compressListDinUtas(ListDinUtas *l)
{
    /* Proses : Mengubah capacity sehingga capacity = nEff */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran capacity = nEff */
    /* KAMUS */
    ListDinUtas lnew;
    int i;

    /* ALGORITMA */
    CreateListDinUtas(&lnew, l->nEff);

    for (i = 0; i < l->nEff; i++)
    {
        lnew.buffer[i] = l->buffer[i];
    }

    lnew.nEff = l->nEff;

    dealocateListDinUtas(l);

    copyListDinUtas(lnew, l);
}
