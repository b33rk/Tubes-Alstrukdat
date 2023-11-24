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

void deleteAllUtas(Utas* l) {
    ElUtas temp;
    while (!isEmptyUtas(*l)){
        deleteFirstUtas(l, &temp);
    }
}