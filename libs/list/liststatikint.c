/* File : liststatik.c */
/* Body ADT LISTSTATIK */
#include "liststatikint.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatikInt(ListStatikInt *l)
{
    /* I.S. l sembarang */
    /* F.S. Terbentuk List l kosong dengan kapasitas 20 */
    /* Proses: Inisialisasi semua elemen List l dengan -99999 */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < 20; i++)
    {
        l->contents[i] = -99999;
    }
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listStatikIntLength(ListStatikInt l)
{
    /* Mengirimkan banyaknya elemen efektif List */
    /* Mengirimkan nol jika List kosong */
    /* KAMUS */
    int i;
    int length;

    /* ALGORITMA */
    length = 0;
    i = 0;

    while (i < 20 && l.contents[i] != -99999)
    {
        length++;
        i++;
    }

    return length;
}

/* *** Selektor INDEKS *** */
int getListStatikIntFirstIdx(ListStatikInt l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l pertama */
    /* KAMUS */

    /* ALGORITMA */
    return 0;
}
int getListStatikIntLastIdx(ListStatikInt l)
{
    /* Prekondisi : List l tidak kosong */
    /* Mengirimkan indeks elemen l terakhir */
    /* KAMUS */

    /* ALGORITMA */
    return listStatikIntLength(l) - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean isListStatikIntIdxValid(ListStatikInt l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
    /* yaitu antara indeks yang terdefinisi utk container*/
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < 20);
}
boolean isListStatikIntIdxEff(ListStatikInt l, int i)
{
    /* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
    /* yaitu antara 0..length(l)-1 */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i <= getListStatikIntLastIdx(l));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isListStatikIntEmpty(ListStatikInt l)
{
    /* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return (listStatikIntLength(l) == 0);
}
/* *** Test List penuh *** */
boolean isListStatikIntFull(ListStatikInt l)
{
    /* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
    /* KAMUS */

    /* ALGORITMA */
    return (listStatikIntLength(l) == 100);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readListStatikInt(ListStatikInt *l)
{
    /* I.S. l sembarang */
    /* F.S. List l terdefinisi */
    /* Proses: membaca banyaknya elemen l dan mengisi nilainya */

    /* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
    /*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= 20 */
    /*    Jika n tidak valid, tidak diberikan pesan kesalahan */
    /* 2. Jika 0 <= n <= 20; Lakukan n kali:
              Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
    /*    Jika n = 0; hanya terbentuk List kosong */
    /* KAMUS */
    int n, i;

    /* ALGORITMA */
    scanf("%d", &n);
    while (n < 0 || n > 20)
    {
        scanf("%d", &n);
    }

    CreateListStatikInt(l);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &l->contents[i]);
    }
}
void printListStatikInt(ListStatikInt l)
{
    /* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. l boleh kosong */
    /* F.S. Jika l tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika List kosong : menulis [] */
    /* KAMUS */
    int i;
    int len;

    /* ALGORITMA */
    len = listStatikIntLength(l);

    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%d", l.contents[i]);
        if (i != len - 1)
        {
            printf(",");
        }
    }
    printf("]");
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatikInt plusMinusListStatikInt(ListStatikInt l1, ListStatikInt l2, boolean plus)
{
    /* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
    /* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada
           indeks yang sama dijumlahkan */
    /* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi
           elemen l2 pada indeks yang sama */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    if (plus == true)
    {
        for (i = 0; i < listStatikIntLength(l1); i++)
        {
            l1.contents[i] += l2.contents[i];
        }
    }
    else if (plus == false)
    {
        for (i = 0; i < listStatikIntLength(l1); i++)
        {
            l1.contents[i] -= l2.contents[i];
        }
    }

    return l1;
}

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListStatikIntEqual(ListStatikInt l1, ListStatikInt l2)
{
    /* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua
        elemennya sama */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    if (listStatikIntLength(l1) != listStatikIntLength(l2))
    {
        return false;
    }
    for (i = 0; i < listStatikIntLength(l1); i++)
    {
        if (l1.contents[i] != l2.contents[i])
        {
            return false;
        }
    }

    return true;
}

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOfListStatikInt(ListStatikInt l, int val)
{
    /* Search apakah ada elemen List l yang bernilai val */
    /* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
    /* Jika tidak ada atau jika l kosong, mengirimkan -1 */
    /* Skema Searching yang digunakan bebas */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    for (i = 0; i < listStatikIntLength(l); i++)
    {
        if (l.contents[i] == val)
        {
            return i;
        }
    }

    return -1;
}

/* ********** NILAI EKSTREM ********** */
void extremeValuesListStatikInt(ListStatikInt l, int *max, int *min)
{
    /* I.S. List l tidak kosong */
    /* F.S. Max berisi nilai terbesar dalam l;
            Min berisi nilai terkecil dalam l */
    /* KAMUS */
    int i;

    /* ALGORITMA */
    *max = l.contents[0];
    *min = l.contents[0];
    for (i = 1; i < listStatikIntLength(l); i++)
    {
        if (l.contents[i] > *max)
        {
            *max = l.contents[i];
        }
        if (l.contents[i] < *min)
        {
            *min = l.contents[i];
        }
    }
}

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirstListStatikInt(ListStatikInt *l, int val)
{
    /* Proses: Menambahkan val sebagai elemen pertama List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen pertama l yang baru */
    /* KAMUS */
    int i;
    int len;

    /* ALGORITMA */
    len = listStatikIntLength(*l);
    for (i = len; i > 0; i--)
    {
        l->contents[i] = l->contents[i-1];
    }

    l->contents[0] = val;
}
/* *** Menambahkan elemen pada index tertentu *** */
void insertAtListStatikInt(ListStatikInt *l, int val, int idx)
{
    /* Proses: Menambahkan val sebagai elemen pada index idx List */
    /* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
    /* F.S. val adalah elemen yang disisipkan pada index idx l */
    /* KAMUS */
    int i;
    int len;

    /* ALGORITMA */
    len = listStatikIntLength(*l);
    for (i = len; i > idx; i--)
    {
        l->contents[i] = l->contents[i-1];
    }

    l->contents[idx] = val;
}
/* *** Menambahkan elemen terakhir *** */
void insertLastListStatikInt(ListStatikInt *l, int val)
{
    /* Proses: Menambahkan val sebagai elemen terakhir List */
    /* I.S. List l boleh kosong, tetapi tidak penuh */
    /* F.S. val adalah elemen terakhir l yang baru */
    /* KAMUS */
    int len;

    /* ALGORITMA */
    len = listStatikIntLength(*l);
    l->contents[len] = val;
}

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirstListStatikInt(ListStatikInt *l, int *val)
{
    /* Proses : Menghapus elemen pertama List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS */
    int i;
    int len;

    /* ALGORITMA */
    *val = l->contents[0];
    len = listStatikIntLength(*l);
    for (i = 0; i < len; i++)
    {
        if (i == 20 - 1)
        {
            l->contents[i] = -99999;
        }
        else
        {
            l->contents[i] = l->contents[i+1];
        }
    }
}
/* *** Menghapus elemen pada index tertentu *** */
void deleteAtListStatikInt(ListStatikInt *l, int *val, int idx)
{
    /* Proses : Menghapus elemen pada index idx List */
    /* I.S. List tidak kosong, idx adalah index yang valid di l */
    /* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS */
    int i;
    int len;

    /* ALGORITMA */
    *val = l->contents[idx];
    len = listStatikIntLength(*l);
    for (i = idx; i < len; i++)
    {
        if (i == 20 - 1)
        {
            l->contents[i] = -99999;
        }
        else
        {
            l->contents[i] = l->contents[i+1];
        }
    }
}
/* *** Menghapus elemen terakhir *** */
void deleteLastListStatikInt(ListStatikInt *l, int *val)
{
    /* Proses : Menghapus elemen terakhir List */
    /* I.S. List tidak kosong */
    /* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
    /*      Banyaknya elemen List berkurang satu */
    /*      List l mungkin menjadi kosong */
    /* KAMUS */
    int len;

    /* ALGORITMA */
    len = listStatikIntLength(*l);
    *val = l->contents[len-1];
    l->contents[len-1] = -99999;
}

/* ********** SORTING ********** */
void sortListStatikInt(ListStatikInt *l, boolean asc)
{
    /* I.S. l boleh kosong */
    /* F.S. Jika asc = true, l terurut membesar */
    /*      Jika asc = false, l terurut mengecil */
    /* Proses : Mengurutkan l dengan salah satu algoritma sorting,
       algoritma bebas */
    /* KAMUS */
    int i, j;
    int temp;
    boolean tukar;
    int len;

    /* ALGORITMA */
    /* bubble sort */
    len = listStatikIntLength(*l);
    for (i = 0; i < len - 1; i++)
    {
        tukar = false;
        for (j = 0; j < len - 1 - i; j++)
        {
            if (asc)
            {
                if (l->contents[j] > l->contents[j+1])
                {
                    temp = l->contents[j];
                    l->contents[j] = l->contents[j+1];
                    l->contents[j+1] = temp;
                    tukar = true;
                }
            }
            else
            {
                if (l->contents[j] < l->contents[j+1])
                {
                    temp = l->contents[j];
                    l->contents[j] = l->contents[j+1];
                    l->contents[j+1] = temp;
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
