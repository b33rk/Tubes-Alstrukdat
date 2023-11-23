#include "prioqueuefriendreq.h"

/* ********* Prototype ********* */
void CreatePrioQueueFR(PrioQueueFriendReq *pQueue, int Max)
{
    pQueue->T = (FriendReq *)malloc(Max * sizeof(FriendReq));
    if (pQueue->T == NULL)
    {
        pQueue->MaxEl = 0;
    }
    else
    {
        pQueue->MaxEl = Max;
        pQueue->HEAD = -1;
        pQueue->TAIL = -1;
    }
}

boolean IsPrioQueueFREmpty(PrioQueueFriendReq Q)
{
    /* Mengirim true jika Q kosong: lihat definisi di atas */
    return (Q.HEAD == -1 && Q.TAIL == -1);
}
boolean IsPrioQueueFRFull(PrioQueueFriendReq Q)
{
    /* Mengirim true jika tabel penampung elemen Q sudah penuh */
    /* yaitu mengandung elemen sebanyak MaxEl */
    return prioQueueFRNBElmt(Q) == Q.MaxEl;
}
int prioQueueFRNBElmt(PrioQueueFriendReq Q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
    if (IsPrioQueueFREmpty(Q))
    {
        return 0;
    }
    else
    {
        if (Q.HEAD <= Q.TAIL)
        {
            return Q.TAIL - Q.HEAD + 1;
        }
        else
        {
            return (Q.MaxEl - Q.HEAD) + (Q.TAIL + 1);
        }
    }
}

/* *** Destruktor *** */
void DeAlokasiPrioQueueFR(PrioQueueFriendReq *Q)
{
    /* Proses: Mengembalikan memori Q */
    /* I.S. Q pernah dialokasi */
    /* F.S. Q menjadi tidak terdefinisi lagi, Q.MaxEl diset 0 */
    Q->MaxEl = 0;
    Q->HEAD = -1;
    Q->TAIL = -1;
    free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void EnqueuePrioQueueFR(PrioQueueFriendReq *Q, FriendReq X)
{
    /* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan prio */
    /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
    /* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
            TAIL "maju" dengan mekanisme circular buffer; */
    if (IsPrioQueueFREmpty(*Q))
    {
        Q->HEAD = 0;
        Q->TAIL = 0;
        Q->T[0] = X;
    }
    else
    {
        Q->TAIL = (Q->TAIL + 1) % Q->MaxEl;
        Q->T[Q->TAIL] = X;
        int i = Q->TAIL - 1 < 0 ? Q->MaxEl - 1 : Q->TAIL - 1;
        while (X.manyFriend > Q->T[i].manyFriend && (i + 1) % Q->MaxEl != Q->HEAD)
        {
            Q->T[i + 1] = Q->T[i];
            i = i - 1 < 0 ? Q->MaxEl - 1 : i - 1;
        }
        Q->T[(i + 1) % Q->MaxEl] = X;
    }
}
void DequeuePrioQueueFR(PrioQueueFriendReq *Q, FriendReq* X)
{
    /* Proses: Menghapus X pada Q dengan aturan FIFO */
    /* I.S. Q tidak mungkin kosong */
    /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
            Q mungkin kosong */
    *X = Q->T[Q->HEAD];
    if (prioQueueFRNBElmt(*Q) == 1)
    {
        Q->HEAD = -1;
        Q->TAIL = -1;
    }
    else
    {
        Q->HEAD = (Q->HEAD + 1) % Q->MaxEl;
    }
}

/* Operasi Tambahan */
void PrintPrioQueueFR(PrioQueueFriendReq Q)
{
    /* Mencetak isi queue Q ke layar */
    /* I.S. Q terdefinisi, mungkin kosong */
    /* F.S. Q tercetak ke layar dengan format:
    <prio-1> <elemen-1>
    ...
    <prio-n> <elemen-n>
    */
    FriendReq temp;
    while (!IsPrioQueueFREmpty(Q))
    {
        DequeuePrioQueueFR(&Q, &temp);
        printf("| %s\n", temp.userName);
        printf("| Jumlah teman: %d\n\n", temp.manyFriend);
    }
}

void PrintPrioQueueFRHead(PrioQueueFriendReq Q)
{
    FriendReq temp = Q.T[Q.HEAD];
    printf("| %s\n", temp.userName);
    printf("| Jumlah teman: %d\n\n", temp.manyFriend);
}


