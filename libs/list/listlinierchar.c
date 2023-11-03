#include "listlinierchar.h"


AddrChar newNodeChar(char val){
    /* Definisi ListLinierChar : */
    /* ListLinierChar kosong : l = NULL */
    /* Setiap elemen dengan AddrChar p dapat diacu p->info, p->next */
    /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */
    /* KAMUS */

    /* ALGORITMA */
    AddrChar p = (AddrChar) malloc(sizeof(NodeChar));

    if (p != NULL) {
        p->info = val;
        p->next = NULL;
    }

    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinierChar(ListLinierChar *l){
    /* I.S. sembarang             */
    /* F.S. Terbentuk list kosong */
    /* KAMUS */

    /* ALGORITMA */
    *l = NULL;
}

/****************** TEST LIST KOSONG ******************/
boolean isListLinierCharEmpty(ListLinierChar l){
    /* Mengirim true jika list kosong */
    /* KAMUS */

    /* ALGORITMA */
    return l == NULL;
}

/****************** GETTER SETTER ******************/
char getListLinierCharElmt(ListLinierChar l, int idx) {
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengembalikan nilai elemen l pada indeks idx */
    /* KAMUS */
    int i = 0;
    AddrChar current;

    /* ALGORITMA */
    current = l;
    while (i < idx) {
        current = current->next;
        i++;
    }
    
    return current->info;
}

void setListLinierCharElmt(ListLinierChar *l, int idx, char val){
    /* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */
    /* KAMUS */
    int i = 0;
    AddrChar current;

    /* ALGORITMA */
    current = *l;
    while (i < idx) {
        current = current->next;
        i++;
    }

    current->info = val;
}

int indexOfListLinierChar(ListLinierChar l, char val){   
    /* I.S. l, val terdefinisi */
    /* F.S. Mencari apakah ada elemen list l yang bernilai val */
    /* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
    /* Mengembalikan -1 jika tidak ditemukan */
    /* KAMUS */
    int i = 0;
    AddrChar current;

    /* ALGORITMA */
    current = l;
    while (current->next != NULL && current->info != val) {
        current = current->next;
        i++;
    }

    if (current->info != val) {
        return -1;
    }
    
    return i;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstListLinierChar(ListLinierChar *l, char val){
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
    /* Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    AddrChar newEl;

    /* ALGORITMA */
    newEl = newNodeChar(val);
    if (newEl != NULL){
        if (!isListLinierCharEmpty(*l)){
            newEl->next = *l;
            *l = newEl;
        } else {
            *l = newEl;
        }
    }
}

void insertLastListLinierChar(ListLinierChar *l, char val){
    /* I.S. l mungkin kosong */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menambahkan elemen list di akhir: elemen terakhir yang baru */
    /* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    AddrChar newEl, current;

    /* ALGORITMA */
    newEl = newNodeChar(val);
    if (newEl != NULL) {
        if (!isListLinierCharEmpty(*l)){
            current = *l;
            while (current->next != NULL){
                current = current->next;
            }
            current->next = newEl;
        } else {
            *l = newEl;
        }
    }

}

void insertAtListLinierChar(ListLinierChar *l, char val, int idx){
    /* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. Melakukan alokasi sebuah elemen dan */
    /* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
    /* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    /* KAMUS */
    int i = 0;
    AddrChar current, nextCurrent, newEl;

    /* ALGORITMA */
    current = *l;
    while (i < idx - 1) {
        current = current->next;
        i++;
    }

    nextCurrent = current->next;
    newEl = newNodeChar(val);
    if(newEl != NULL){
        if (idx == 0){
            newEl->next = *l;
            *l = newEl;
        } else {

            current->next = newEl;
            newEl->next = nextCurrent;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstListLinierChar(ListLinierChar *l, char *val){
    /* I.S. ListLinierChar l tidak kosong  */
    /* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen pertama di-dealokasi */
    /* KAMUS */
    AddrChar firstEl;

    /* ALGORITMA */
    *val = (*l)->info;
    if ((*l)->next != NULL){
        firstEl = *l;
        *l = firstEl->next;
        free(firstEl);
    } else {
        free(*l);
        CreateListLinierChar(l);
    }
}
void deleteLastListLinierChar(ListLinierChar *l, char *val){
    /* I.S. list tidak kosong */
    /* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
    /*      dan alamat elemen terakhir di-dealokasi */
    /* KAMUS */
    AddrChar current, current2;

    /* ALGORITMA */
    current = *l;
    if (current->next != NULL){
        current2 = current->next;
        while(current2->next != NULL){
            current = current->next;
            current2 = current2->next;
        }

        *val = current2->info;
        current->next = NULL;
        free(current2);
    } else {
        *val = current->info;
        free(*l);
        CreateListLinierChar(l);
    }
}

void deleteAtListLinierChar(ListLinierChar *l, int idx, char *val){
    /* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
    /* F.S. val diset dengan elemen l pada indeks ke-idx. */
    /*      Elemen l pada indeks ke-idx dihapus dari l */
    /* KAMUS */
    int i = 0;
    AddrChar current, nextCurrent;

    /* ALGORITMA */
    
    current = *l;
    if (current->next == NULL){
        *val = current->info;
        free(current);
        CreateListLinierChar(l);
    } else {
        while (i < idx - 1) {
            current = current->next;
            i++;
        }

        if (idx != 0){
            nextCurrent = current->next;
            *val = nextCurrent->info;
            current->next = nextCurrent->next;
            free(nextCurrent);
        } else {
            *val = current->info;
            *l = (*l)->next;
            free(current);
            
        }
    }

}


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListLinierChar(ListLinierChar l){
    /* I.S. ListLinierChar mungkin kosong */
    /* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika list kosong : menulis [] */
    /* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    /* KAMUS */
    AddrChar current;

    /* ALGORITMA */
    if (isListLinierCharEmpty(l)){
        printf("[]");
    } else {
        current = l;
        printf("[%d", current->info);

        while (current->next != NULL)
        {
            current = current->next;
            printf(",%d", current->info);
        }

        printf("]");
    }
}

int lengthListLinierChar(ListLinierChar l){
    /* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /* KAMUS */
    AddrChar current;
    int len;

    /* ALGORITMA */
    if (isListLinierCharEmpty(l)){
        return 0;
    } else {
        len = 1;
        for (current = l; current->next != NULL; current = current->next){
            len++;
        }
        return len;
    }
}

/****************** PROSES TERHADAP LIST ******************/
ListLinierChar concatListLinierChar(ListLinierChar l1, ListLinierChar l2) {
    /* KAMUS */
    ListLinierChar l3;
    AddrChar current;

    /* ALGORITMA */
    CreateListLinierChar(&l3);
    current = l1;
    while (current != NULL)
    {
        insertLastListLinierChar(&l3, current->info);
        current = current->next;
    }

    current = FIRST(l2);
    while (current != NULL)
    {
        insertLastListLinierChar(&l3, current->info);
        current = current->next;
    }

    l1 = NULL;
    l2 = NULL;
    
    return l3;

}

boolean fSearchListLinierChar(ListLinierChar l, AddrChar p) {
    boolean found = false;
    AddrChar current;

    /* ALGORITMA */
    current = l;
    while (current != NULL && !found) {
        if (current->info == p->info) {
            found = true;
        }
        current = current->next;
    }
    
    return found;
}

AddrChar searchPrecListLinierChar(ListLinierChar l, char x) {
    boolean found = false;
    AddrChar current;

    /* ALGORITMA */
    current = l;
    if (current->info == x){
        return NULL;
    }
    while (current->next != NULL && !found) {
        if (current->next->info == x) {
            found = true;
        }
        current = current->next;
    }
    
    if (found) return current;
    else return NULL;
}

void deleteAllListLinierChar(ListLinierChar* l) {
    char temp;
    while (!isListLinierCharEmpty(*l)){
        deleteFirstListLinierChar(l, &temp);
    }
}

void copyListLinierChar(ListLinierChar* l1, ListLinierChar* l2) {
    CreateListLinierChar(l2);
    (*l2) = (*l1);
}

void inverseListLinierChar(ListLinierChar *l) {
    AddrChar current;

    ListLinierChar l2;
    CreateListLinierChar(&l2);
    current = *l;
    while (current != NULL)
    {
        insertFirstListLinierChar(&l2, current->info);
        current = current->next;
    }
    AddrChar temp = *l;
    *l = (l2);
    deleteAllListLinierChar(&temp);
    free(temp);

}