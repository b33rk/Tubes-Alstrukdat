#include "listdinkicau.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateKicauan(Kicauan *k)
{
    k->id = -1;
    k->idUser = -1;
    k->like = 0;
    k->idUtas = -1;
    createTree(&(k->balasan));
}

void CreateListDinKicau(ListDinKicau *l, int capacity)
{
    /* I.S. l sembarang, capacity > 0 */
    /* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */
    /* KAMUS */

    /* ALGORITMA */
    l->capacity = capacity;
    l->nEff = 0;
    l->buffer = (Kicauan *)malloc(capacity * sizeof(Kicauan));
}

void dealocateListDinKicau(ListDinKicau *l)
{
    /* I.S. l terdefinisi; */
    /* F.S. (l) dikembalikan ke system, l.capacity=0; l.nEff=0 */
    /* KAMUS */

    /* ALGORITMA */

    int i;
    for  (i = 0; i < l->nEff; i++)
    
    {
        dealokasiTree(&(l->buffer[i].balasan));
    }

    l->capacity = 0;
    l->nEff = 0;
    free(l->buffer);
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listDinKicauLength(ListDinKicau l)
{
    /* Mengirimkan banyaknya elemen efektif list */
    /* Mengirimkan nol jika list l kosong */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff;
}
/* *** Daya tampung container *** */
/* *** Selektor INDEKS *** */
int getListDinKicauFirstIdx(ListDinKicau l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS */

    /* ALGORITMA */
    return 0;
}
int getListDinKicauLastIdx(ListDinKicau l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isListDinKicauIdxValid(ListDinKicau l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (0 <= i && i < l.capacity);
}
boolean isListDinKicauIdxEff(ListDinKicau l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
    /* yaitu antara 0..l.nEff */
    /* KAMUS */

    /* ALGORITMA */
    return (0 <= i && i < l.nEff);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isListDinKicauEmpty(ListDinKicau l)
{
    /* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff == 0;
}
/* *** Test list penuh *** */
boolean isListDinKicauFull(ListDinKicau l)
{
    /* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return l.nEff == l.capacity;
}

void copyListDinKicau(ListDinKicau lIn, ListDinKicau *lOut)
{
    /* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
    /* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
    /* Proses : Menyalin isi lIn ke lOut */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    CreateListDinKicau(lOut, lIn.capacity);

    for (i = 0; i < lIn.nEff; i++)
    {
        Kicauan temp;
        CreateKicauan(&temp);

        temp.id = lIn.buffer[i].id;
        temp.idUser = lIn.buffer[i].idUser;
        temp.like = lIn.buffer[i].like;
        temp.datetime = lIn.buffer[i].datetime;

        int j = 0;
        while (lIn.buffer[i].text[j] != '\0')
        {
            temp.text[j] = lIn.buffer[i].text[j];
            j++;
        }
        temp.text[j] = '\0';

        insertLastListDinKicau(lOut, temp);
        lOut->nEff++;
    }
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
int indexOfListDinKicauById(ListDinKicau l, int idKicau)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
    /* Jika tidak ada, mengirimkan -1 */
    /* Menghasilkan indeks tak terdefinisi (-1) jika List l kosong */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < l.nEff; i++)
    {
        if (l.buffer[i].id == idKicau)
        {
            return i;
        }
    }

    return -1;
}

/* ********** SORTING ********** */
void sortListDinKicauByDateTime(ListDinKicau *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    /* KAMUS */
    int i, j;
    Kicauan temp;
    boolean tukar;
    int len;

    /* ALGORITMA */
    /* bubble sort */
    len = listDinKicauLength(*l);
    for (i = 0; i < len - 1; i++)
    {
        tukar = false;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (asc)
            {
                if (DGT(l->buffer[j].datetime, l->buffer[j + 1].datetime))
                {
                    // temp = l->buffer[j];
                    // int k = 0;
                    // while (l->buffer[j].text[k] != '\0')
                    // {
                    //     temp.text[k] = l->buffer[j].text[k];
                    //     k++;
                    // }

                    // temp.text[k] = '\0';

                    // l->buffer[j] = l->buffer[j + 1];
                    // k = 0;
                    // while (l->buffer[j + 1].text[k] != '\0')
                    // {
                    //     l->buffer[j].text[k] = l->buffer[j + 1].text[k];
                    //     k++;
                    // }

                    // l->buffer[j].text[k] = '\0';

                    // l->buffer[j + 1] = temp;
                    // k = 0;
                    // while (temp.text[k] != '\0')
                    // {
                    //     l->buffer[j + 1].text[k] = temp.text[k];
                    //     k++;
                    // }

                    // l->buffer[j + 1].text[k] = '\0';
                    // tukar = true;
                    temp = l->buffer[j];
                    l->buffer[j] = l->buffer[j + 1];
                    l->buffer[j + 1] = temp;
                    tukar = true;
                }
            }
            else
            {
                if (DLT(l->buffer[j].datetime, l->buffer[j + 1].datetime))
                {
                    temp = l->buffer[j];
                    l->buffer[j] = l->buffer[j + 1];
                    l->buffer[j + 1] = temp;
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

void sortListDinKicauById(ListDinKicau *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    /* KAMUS */
    int i, j;
    Kicauan temp;
    boolean tukar;
    int len;

    /* ALGORITMA */
    /* bubble sort */
    len = listDinKicauLength(*l);
    for (i = 0; i < len - 1; i++)
    {
        tukar = false;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (asc)
            {
                if (l->buffer[j].id > l->buffer[j + 1].id)
                {
                    temp = l->buffer[j];
                    l->buffer[j] = l->buffer[j + 1];
                    l->buffer[j + 1] = temp;
                    tukar = true;
                }
            }
            else
            {
                if (l->buffer[j].id < l->buffer[j + 1].id)
                {
                    temp = l->buffer[j];
                    l->buffer[j] = l->buffer[j + 1];
                    l->buffer[j + 1] = temp;
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
void insertLastListDinKicau(ListDinKicau *l, Kicauan val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir list */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */

    /* ALGORITMA */
    if (!isListDinKicauFull(*l))
    {
        l->buffer[l->nEff] = val;
        l->nEff++;
    }
    else
    {
        expandListDinKicau(l, l->capacity);
        l->buffer[l->nEff] = val;
        l->nEff++;
    }
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinKicau(ListDinKicau *l, Kicauan *val)
{
    /* Proses : Menghapus elemen terakhir list */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen list berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS */

    /* ALGORITMA */
    *val = l->buffer[getListDinKicauLastIdx(*l)];
    l->nEff--;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinKicau(ListDinKicau *l, int num)
{
    /* Proses : Menambahkan capacity l sebanyak num */
    /* I.S. List sudah terdefinisi */
    /* F.S. Ukuran list bertambah sebanyak num */
    /* KAMUS */
    // ListDinKicau lnew;
    // int i;

    l->capacity = l->capacity + num;
    l->buffer = (Kicauan *)realloc(l->buffer, l->capacity *sizeof(Kicauan));
    // /* ALGORITMA */
    // CreateListDinKicau(&lnew, l->capacity + num);

    // for (i = 0; i < l->nEff; i++)
    // {
    //     lnew.buffer[i].id = l->buffer[i].id;
    //     lnew.buffer[i].datetime = l->buffer[i].datetime;
    //     lnew.buffer[i].idUser = l->buffer[i].idUser;
    //     lnew.buffer[i].like = l->buffer[i].like;
    //     lnew.buffer[i].idUtas = l->buffer[i].idUtas;
    //     int j = 0;
    //     while (l->buffer[i].text[j] != '\0')
    //     {
    //         lnew.buffer[i].text[j] = l->buffer[i].text[j];
    //         j++;
    //     }
    //     lnew.buffer[i].text[j] = '\0';
    //     lnew.nEff++;
    // }

    // // for (i = 0; i < l->nEff; i++)
    // // {
    // //     lnew.buffer[i] = l->buffer[i];
    // // }
    // // lnew.nEff = l->nEff;

    // dealocateListDinKicau(l);

    // copyListDinKicau(lnew, l);
}

void shrinkListDinKicau(ListDinKicau *l, int num)
{
    /* Proses : Mengurangi capacity sebanyak num */
    /* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
    /* F.S. Ukuran list berkurang sebanyak num. */
    /* KAMUS */
    ListDinKicau lnew;
    int i;

    /* ALGORITMA */
    CreateListDinKicau(&lnew, l->capacity - num);

    for (i = 0; i < l->nEff; i++)
    {
        lnew.buffer[i] = l->buffer[i];
    }
    lnew.nEff = l->nEff;

    dealocateListDinKicau(l);

    copyListDinKicau(lnew, l);
}

void compressListDinKicau(ListDinKicau *l)
{
    /* Proses : Mengubah capacity sehingga capacity = nEff */
    /* I.S. List tidak kosong */
    /* F.S. Ukuran capacity = nEff */
    /* KAMUS */
    ListDinKicau lnew;
    int i;

    /* ALGORITMA */
    CreateListDinKicau(&lnew, l->nEff);

    for (i = 0; i < l->nEff; i++)
    {
        lnew.buffer[i] = l->buffer[i];
    }

    lnew.nEff = l->nEff;

    dealocateListDinKicau(l);

    copyListDinKicau(lnew, l);
}
