// typedef struct
// {
//     int idUser;
//     int manyFriend;
//     char userName[21];
// } FriendReq;

#include <stdio.h>
#include <stdlib.h>
#include "../../libs/queue/prioqueuefriendreq.h"

int main(){

    PrioQueueFriendReq q;
    int type;
    CreatePrioQueueFR(&q, 10);

    FriendReq X1;
    FriendReq X2;
    FriendReq X3;
    FriendReq X4;
    FriendReq XTumbal;

    scanf("%d", &type);

    switch(type)
    {
    case 1:
        printf("%d %d %d\n", IsPrioQueueFREmpty(q), IsPrioQueueFRFull(q), prioQueueFRNBElmt(q));
        break;
    case 2:
        X1.idUser = 7;
        X1.manyFriend = 1;
        X2.idUser = 4;
        X2.manyFriend = 1;
        EnqueuePrioQueueFR(&q, X1);
        EnqueuePrioQueueFR(&q, X2);
        printf("%d ", prioQueueFRNBElmt(q)); // 2
        printf("%d ", q.T[q.HEAD].idUser); // 7
        DequeuePrioQueueFR(&q, &XTumbal);
        printf("%d ", XTumbal.idUser); // 7
        printf("%d\n", q.T[q.HEAD].idUser); // 4
        break;
    case 3:
        X1.idUser = 7;
        X1.manyFriend = 1;
        X2.idUser = 4;
        X2.manyFriend = 1;
        X3.idUser = 6;
        X3.manyFriend = 7;
        X4.idUser = 5;
        X4.manyFriend = 5;
        EnqueuePrioQueueFR(&q, X1);
        EnqueuePrioQueueFR(&q, X3);
        EnqueuePrioQueueFR(&q, X4);
        EnqueuePrioQueueFR(&q, X2);
        printf("%d ", q.T[q.HEAD].idUser); // 6
        DequeuePrioQueueFR(&q, &XTumbal);
        printf("%d ", q.T[q.HEAD].idUser); // 5
        DequeuePrioQueueFR(&q, &XTumbal);
        printf("%d ", q.T[q.HEAD].idUser); // 7
        DequeuePrioQueueFR(&q, &XTumbal);
        printf("%d ", q.T[q.HEAD].idUser); // 4
        DequeuePrioQueueFR(&q, &XTumbal);
        printf("%d\n", IsPrioQueueFREmpty(q)); // 1
        break;
    }

    return 0;
}