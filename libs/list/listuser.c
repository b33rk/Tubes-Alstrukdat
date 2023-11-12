/* File : liststatik.c */
/* Body ADT LISTSTATIK */
#include "listuser.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListUser(ListUser *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
    /* Proses: Inisialisasi semua elemen List l dengan MARK */
    /* KAMUS */
    IdxType i;

    /* ALGORITMA */
    for (i = 0; i < CAPACITY_USER; i++)
    {
        User temp;
        CreateUser(&temp);
        (*l).contents[i] = temp;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listUserLength(ListUser l)
{
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    /* KAMUS */
    IdxType i;
    int length;

    /* ALGORITMA */
    length = 0;
    i = 0;

    while (i < CAPACITY_USER && l.contents[i].id != -1)
    {
        length++;
        i++;
    }

    return length;
}

/* *** Selektor INDEKS *** */
IdxType getListUserFirstIdx(ListUser l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS */

    /* ALGORITMA */
    return IDX_MIN;
}
IdxType getListUserLastIdx(ListUser l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return listUserLength(l) - 1;
}

int listUserIndexOfWithName(ListUser l, char* name){
    if (isListUserEmpty(l)){
        return -1;
    } else {
        int i;
        for (i = 0; i < listUserLength(l); i++){
            if (isTextEqual(charArrToText(name), charArrToText(l.contents[i].name))){
                return i;
            }
        }

        return -1;
    }
}

/* ********** Test Indeks yang valid ********** */
boolean isListUserIdxValid(ListUser l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (i >= IDX_MIN && i < CAPACITY_USER);
}
boolean isListUserIdxEff(ListUser l, IdxType i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= IDX_MIN && i <= getListUserLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isListUserEmpty(ListUser l)
{
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return (listUserLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isListUserFull(ListUser l)
{
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return (listUserLength(l) == CAPACITY_USER);
}

void printListUser(ListUser l)
{
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    /* KAMUS */
    IdxType i;
    int len;

    /* ALGORITMA */
    len = listUserLength(l);

    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%s", l.contents[i].name);
        printf("&");
        printf("%s", l.contents[i].password);
        if (i != len - 1)
        {
            printf(",");
        }
    }
    printf("]\n");
}


/* *** Menambahkan elemen terakhir *** */
void listUserInsertLast(ListUser *l, User val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */
    int len;

    /* ALGORITMA */
    len = listUserLength(*l);
    (*l).contents[len] = val;
}

