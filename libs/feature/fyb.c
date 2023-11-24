#include "fyb.h"

void FYB()
{

    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    int len = listDinKicauLength(listKicauan);
    int len2 = len;

    if (len > 4)
    {
        len2 = 4;
    }
    printf("\nBerikut %d kicauan dengan like tertinggi di FYB\n", len2);

    MaxHeap heap;
    initMaxHeap(&heap);
    int i;
    for (i = 0; i < len; i++)
    {
        insert(&heap, listKicauan.buffer[i]);
    }

    for (i = 0; i < len2; i++)
    {
        Kicauan k = deleteMax(&heap);
        printf("Kicauan %d:\n", i + 1);
        printf("| ID = %d\n", k.id);
        printf("| %s\n", listUser.contents[k.idUser].name);
        printf("| ");
        TulisDATETIME(k.datetime);
        printf("\n");
        printf("| %s\n", k.text);
        printf("| Disukai: %d\n\n", k.like);
    }
}