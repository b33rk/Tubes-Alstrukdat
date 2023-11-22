#include "listlinierutas.h"

AddressUtas newNodeUtas(ElUtas val)
{
    /* Definisi Utas : */
    /* Utas kosong : l = NULL */
    /* Setiap elemen dengan AddressUtas p dapat diacu INFO(p), p->next */
    /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    /* KAMUS */

    /* ALGORITMA */
    AddressUtas p = (AddressUtas)malloc(sizeof(NodeUtas));

    if (p != NULL)
    {
        p->info.idKicau = val.idKicau;
        p->info.id = val.id;
        p->info.idUser = val.idUser;
        p->info.datetime = val.datetime;
        int i = 0;
        while (val.text[i] != '\0')
        {
            p->info.text[i] = val.text[i];
            i++;
        }
        p->info.text[i] = '\0';
        p->next = NULL;
    }

    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateUtas(Utas *l)
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
    return l == NULL;
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
    current = l;
    while (i < idx)
    {
        current = current->next;
        i++;
    }

    return current->info;
}

void setElmtUtas(Utas *l, int idx, ElUtas val)
{
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS */
    int i = 0;
    AddressUtas current;

    /* ALGORITMA */
    current = *l;
    while (i < idx)
    {
        current = current->next;
        i++;
    }

    current->info = val;
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
//     current = l;
//     while (current->next != NULL && current->info != val) {
//         current = current->next;
//         i++;
//     }

//     if (current->info != val) {
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
            newEl->next = *l;
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
            current = *l;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newEl;
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
    current = *l;
    while (i < idx - 1)
    {
        current = current->next;
        i++;
    }

    nextCurrent = current->next;
    newEl = newNodeUtas(val);
    if (newEl != NULL)
    {
        if (idx == 0)
        {
            newEl->next = *l;
            *l = newEl;
        }
        else
        {

            current->next = newEl;
            newEl->next = nextCurrent;
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
    *val = (*l)->info;
    if ((*l)->next != NULL)
    {
        firstEl = *l;
        *l = firstEl->next;
        free(firstEl);
    }
    else
    {
        free(*l);
        CreateUtas(l);
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
    current = *l;
    if (current->next != NULL)
    {
        current2 = current->next;
        while (current2->next != NULL)
        {
            current = current->next;
            current2 = current2->next;
        }

        *val = current2->info;
        current->next = NULL;
        free(current2);
    }
    else
    {
        *val = current->info;
        free(*l);
        CreateUtas(l);
    }
}

void deleteAtUtas(Utas *l, int idx, ElUtas *val)
{
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS */
    int i = 0;
    AddressUtas current, nextCurrent;

    /* ALGORITMA */

    current = *l;
    if (current->next == NULL)
    {
        *val = current->info;
        free(current);
        CreateUtas(l);
    }
    else
    {
        while (i < idx - 1)
        {
            current = current->next;
            i++;
        }

        if (idx != 0)
        {
            nextCurrent = current->next;
            *val = nextCurrent->info;
            current->next = nextCurrent->next;
            free(nextCurrent);
        }
        else
        {
            *val = current->info;
            *l = (*l)->next;
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
//     if (isEmptyUtas(l)){
//         printf("[]");
//     } else {
//         current = l;
//         printf("[%d", current->info);

//         while (current->next != NULL)
//         {
//             current = current->next;
//             printf(",%d", current->info);
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
    if (isEmptyUtas(l))
    {
        return 0;
    }
    else
    {
        len = 1;
        for (current = l; current->next != NULL; current = current->next)
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
//     // if (!isEmptyUtas(l1)){
//     //     FIRST(l3) = FIRST(l1);

//     //     for (current = FIRST(l3); current->next != NULL; current = current->next){

//     //     }
//     //     current->next = FIRST(l2);

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
//     CreateUtas(&l3);
//     current = FIRST(l1);
//     while (current != NULL)
//     {
//         insertLast(&l3, current->info);
//         current = current->next;
//     }

//     current = FIRST(l2);
//     while (current != NULL)
//     {
//         insertLast(&l3, current->info);
//         current = current->next;
//     }

//     FIRST(l1) = NULL;
//     FIRST(l2) = NULL;

//     return l3;

// }

// boolean fSearch(Utas l, AddressUtas p) {
//     boolean found = false;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     while (current != NULL && !found) {
//         if (current->info == INFO(p)) {
//             found = true;
//         }
//         current = current->next;
//     }

//     return found;
// }

// AddressUtas searchPrec(Utas l, ElUtas x) {
//     boolean found = false;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     if (current->info == x){
//         return NULL;
//     }
//     while (current->next != NULL && !found) {
//         if (INFO(current->next) == x) {
//             found = true;
//         }
//         current = current->next;
//     }

//     if (found) return current;
//     else return NULL;
// }

// ElUtas maxValue(Utas l) {
//     int max;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     max = current->info;
//     current = current->next;
//     while (current != NULL) {
//         if (current->info > max) {
//             max = current->info;
//         }
//         current = current->next;
//     }

//     return max;
// }

// AddressUtas adrMax(Utas l) {
//     AddressUtas max;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     max = current;
//     current = current->next;
//     while (current != NULL) {
//         if (current->info > INFO(max)) {
//             max = current;
//         }
//         current = current->next;
//     }

//     return max;
// }

// ElUtas minValue(Utas l) {
//     int min;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     min = current->info;
//     current = current->next;
//     while (current != NULL) {
//         if (current->info < min) {
//             min = current->info;
//         }
//         current = current->next;
//     }

//     return min;
// }

// AddressUtas adrMin(Utas l) {
//     AddressUtas min;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     min = current;
//     current = current->next;
//     while (current != NULL) {
//         if (current->info < INFO(min)) {
//             min = current;
//         }
//         current = current->next;
//     }

//     return min;
// }

// float average(Utas l) {
//     float total = 0;
//     AddressUtas current;

//     /* ALGORITMA */
//     current = l;
//     while (current != NULL) {
//         total += (float) current->info;
//         current = current->next;
//     }

//     float mean = total / (float) length(l);

//     return mean;
// }

void deleteAllUtas(Utas* l) {
    ElUtas temp;
    while (!isEmptyUtas(*l)){
        deleteFirstUtas(l, &temp);
    }
}

// void copyList(Utas* l1, Utas* l2) {
//     CreateUtas(l2);
//     FIRST(*l2) = FIRST(*l1);
// }

// void inverseList(Utas *l) {
//     AddressUtas current;

//     Utas l2;
//     CreateUtas(&l2);
//     current = *l;
//     while (current != NULL)
//     {
//         insertFirst(&l2, current->info);
//         current = current->next;
//     }
//     AddressUtas temp = *l;
//     *l = FIRST(l2);
//     deleteAll(&temp);
//     free(temp);

// }