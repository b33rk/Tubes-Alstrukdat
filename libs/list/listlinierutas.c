#include "listlinierutas.h"

AddressUtas newNodeUtas(ElUtas val)
{
    /* Definisi Utas : */
    /* Utas kosong : FIRST(l) = NULL */
    /* Setiap elemen dengan AddressUtas p dapat diacu INFO(p), p->next */
    /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    /* KAMUS */

    /* ALGORITMA */
    AddressUtas p = (AddressUtas)malloc(sizeof(NodeUtas));

    if (p != NULL)
    {
        INFO(p) = val;
        p->info.id = val.id;
        p->info.idUser = val.idUser;
        int i = 0;
        while (val.text[i] != '\0')
        {
            p->info.text[i] = val.text[i];
            i++;
        }
        p->next = NULL;
    }

    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListUtas(Utas *l)
{
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    /* KAMUS */

    /* ALGORITMA */
    *l = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isEmptyUtas(Utas l)
{
    /* Mengirim true jika list kosong */
    /* KAMUS */

    /* ALGORITMA */
    return FIRST(l) == NULL;
}

/****************** GETTER SETTER ******************/
ElUtas getElmtUtas(Utas l, int idx)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS */
    int i = 0;
    AddressUtas current;

    /* ALGORITMA */
    current = FIRST(l);
    while (i < idx)
    {
        current = NEXT(current);
        i++;
    }

    return INFO(current);
}

void setElmtUtas(Utas *l, int idx, ElUtas val)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS */
    int i = 0;
    AddressUtas current;

    /* ALGORITMA */
    current = FIRST(*l);
    while (i < idx)
    {
        current = NEXT(current);
        i++;
    }

    INFO(current) = val;
}

// int indexOfUtas(Utas l, ElUtas val){
//     /* I.S. l, val terdefinisi */
//     /* F.S. Mencari apakah ada elemen list l yang bernilai val */
//     /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
//     /* Mengembalikan IDX_UNDEF jika tidak ditemukan */
//     /* KAMUS */
//     int i = 0;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     while (NEXT(current) != NULL && INFO(current) != val) {
//         current = NEXT(current);
//         i++;
//     }

//     if (INFO(current) != val) {
//         return IDX_UNDEF;
//     }

//     return i;
// }

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstUtas(Utas *l, ElUtas val)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    AddressUtas newEl;

    /* ALGORITMA */
    newEl = newNodeUtas(val);
    if (newEl != NULL)
    {
        if (!isEmptyUtas(*l))
        {
            NEXT(newEl) = FIRST(*l);
            *l = newEl;
        }
        else
        {
            *l = newEl;
        }
    }
}

void insertLastUtas(Utas *l, ElUtas val)
{
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    AddressUtas newEl, current;

    /* ALGORITMA */
    newEl = newNodeUtas(val);
    if (newEl != NULL)
    {
        if (!isEmptyUtas(*l))
        {
            current = FIRST(*l);
            while (NEXT(current) != NULL)
            {
                current = NEXT(current);
            }
            NEXT(current) = newEl;
        }
        else
        {
            *l = newEl;
        }
    }
}

void insertAtUtas(Utas *l, ElUtas val, int idx)
{
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
    /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    int i = 0;
    AddressUtas current, nextCurrent, newEl;

    /* ALGORITMA */
    current = FIRST(*l);
    while (i < idx - 1)
    {
        current = NEXT(current);
        i++;
    }

    nextCurrent = NEXT(current);
    newEl = newNode(val);
    if (newEl != NULL)
    {
        if (idx == 0)
        {
            NEXT(newEl) = FIRST(*l);
            *l = newEl;
        }
        else
        {

            NEXT(current) = newEl;
            NEXT(newEl) = nextCurrent;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstUtas(Utas *l, ElUtas *val)
{
    /* I.S. Utas l tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    AddressUtas firstEl;

    /* ALGORITMA */
    *val = INFO(FIRST(*l));
    if (NEXT(FIRST(*l)) != NULL)
    {
        firstEl = FIRST(*l);
        *l = NEXT(firstEl);
        free(firstEl);
    }
    else
    {
        free(FIRST(*l));
        CreateList(l);
    }
}
void deleteLastUtas(Utas *l, ElUtas *val)
{
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    AddressUtas current, current2;

    /* ALGORITMA */
    current = FIRST(*l);
    if (NEXT(current) != NULL)
    {
        current2 = NEXT(current);
        while (NEXT(current2) != NULL)
        {
            current = NEXT(current);
            current2 = NEXT(current2);
        }

        *val = INFO(current2);
        NEXT(current) = NULL;
        free(current2);
    }
    else
    {
        *val = INFO(current);
        free(FIRST(*l));
        CreateList(l);
    }
}

void deleteAtUtas(Utas *l, int idx, ElUtas *val)
{
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS */
    int i = 0;
    AddressUtas current, nextCurrent, newEl;

    /* ALGORITMA */

    current = FIRST(*l);
    if (NEXT(current) == NULL)
    {
        *val = INFO(current);
        free(FIRST(current));
        CreateList(l);
    }
    else
    {
        while (i < idx - 1)
        {
            current = NEXT(current);
            i++;
        }

        if (idx != 0)
        {
            nextCurrent = NEXT(current);
            *val = INFO(nextCurrent);
            NEXT(current) = NEXT(nextCurrent);
            free(nextCurrent);
        }
        else
        {
            *val = INFO(current);
            *l = NEXT(FIRST(*l));
            free(current);
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
// void displayListUtas(Utas l){
//     /* I.S. Utas mungkin kosong */
//     /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
//     /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
//     /* Jika list kosong : menulis [] */
//     /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
//     /* KAMUS */
//     AddressUtas current;

//     /* ALGORITMA */
//     if (isEmpty(l)){
//         printf("[]");
//     } else {
//         current = FIRST(l);
//         printf("[%d", INFO(current));

//         while (NEXT(current) != NULL)
//         {
//             current = NEXT(current);
//             printf(",%d", INFO(current));
//         }

//         printf("]");
//     }
// }

int lengthUtas(Utas l)
{
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS */
    AddressUtas current;
    int len;

    /* ALGORITMA */
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        len = 1;
        for (current = FIRST(l); NEXT(current) != NULL; current = NEXT(current))
        {
            len++;
        }
        return len;
    }
}

/****************** PROSES TERHADAP LIST ******************/
// Utas concatUtas(Utas l1, Utas l2) {
//     /* I.S. l1 dan l2 sembarang */
//     /* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
//     /* Konkatenasi dua buah list : l1 dan l2    */
//     /* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
//     /* Tidak ada alokasi/dealokasi pada prosedur ini */
//     // /* KAMUS */
//     // Utas l3;
//     // AddressUtas current;

//     // /* ALGORITMA */
//     // if (!isEmpty(l1)){
//     //     FIRST(l3) = FIRST(l1);

//     //     for (current = FIRST(l3); NEXT(current) != NULL; current = NEXT(current)){

//     //     }
//     //     NEXT(current) = FIRST(l2);

//     // } else {
//     //     FIRST(l3) = FIRST(l2);
//     // }

//     // FIRST(l1) = NULL;
//     // FIRST(l2) = NULL;
//     // return l3;
//     /* KAMUS */
//     Utas l3;
//     AddressUtas current;

//     /* ALGORITMA */
//     CreateList(&l3);
//     current = FIRST(l1);
//     while (current != NULL)
//     {
//         insertLast(&l3, INFO(current));
//         current = NEXT(current);
//     }

//     current = FIRST(l2);
//     while (current != NULL)
//     {
//         insertLast(&l3, INFO(current));
//         current = NEXT(current);
//     }

//     FIRST(l1) = NULL;
//     FIRST(l2) = NULL;

//     return l3;

// }

// boolean fSearch(Utas l, AddressUtas p) {
//     boolean found = false;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     while (current != NULL && !found) {
//         if (INFO(current) == INFO(p)) {
//             found = true;
//         }
//         current = NEXT(current);
//     }

//     return found;
// }

// AddressUtas searchPrec(Utas l, ElUtas x) {
//     boolean found = false;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     if (INFO(current) == x){
//         return NULL;
//     }
//     while (NEXT(current) != NULL && !found) {
//         if (INFO(NEXT(current)) == x) {
//             found = true;
//         }
//         current = NEXT(current);
//     }

//     if (found) return current;
//     else return NULL;
// }

// ElUtas maxValue(Utas l) {
//     int max;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     max = INFO(current);
//     current = NEXT(current);
//     while (current != NULL) {
//         if (INFO(current) > max) {
//             max = INFO(current);
//         }
//         current = NEXT(current);
//     }

//     return max;
// }

// AddressUtas adrMax(Utas l) {
//     AddressUtas max;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     max = current;
//     current = NEXT(current);
//     while (current != NULL) {
//         if (INFO(current) > INFO(max)) {
//             max = current;
//         }
//         current = NEXT(current);
//     }

//     return max;
// }

// ElUtas minValue(Utas l) {
//     int min;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     min = INFO(current);
//     current = NEXT(current);
//     while (current != NULL) {
//         if (INFO(current) < min) {
//             min = INFO(current);
//         }
//         current = NEXT(current);
//     }

//     return min;
// }

// AddressUtas adrMin(Utas l) {
//     AddressUtas min;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     min = current;
//     current = NEXT(current);
//     while (current != NULL) {
//         if (INFO(current) < INFO(min)) {
//             min = current;
//         }
//         current = NEXT(current);
//     }

//     return min;
// }

// float average(Utas l) {
//     float total = 0;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = FIRST(l);
//     while (current != NULL) {
//         total += (float) INFO(current);
//         current = NEXT(current);
//     }

//     float mean = total / (float) length(l);

//     return mean;
// }

// void deleteAll(Utas* l) {
//     int temp;
//     while (!isEmpty(*l)){
//         deleteFirst(l, &temp);
//     }
// }

// void copyList(Utas* l1, Utas* l2) {
//     CreateList(l2);
//     FIRST(*l2) = FIRST(*l1);
// }

// void inverseList(Utas *l) {
//     AddressUtas current;

//     Utas l2;
//     CreateList(&l2);
//     current = FIRST(*l);
//     while (current != NULL)
//     {
//         insertFirst(&l2, INFO(current));
//         current = NEXT(current);
//     }
//     AddressUtas temp = FIRST(*l);
//     *l = FIRST(l2);
//     deleteAll(&temp);
//     free(temp);

// }