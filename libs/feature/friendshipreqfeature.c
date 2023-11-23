#include "friendshipreqfeature.h"

void addFriend()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    if (!IsPrioQueueFREmpty(currentUser->friendReq))
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.\n\n");
        return;
    }

    boolean isNameValid = false;
    int index;

    while (!isNameValid)
    {
        printf("Masukkan nama pengguna: \n");
        STARTTEXT();
        printf("\n");
        if (currentText.Length == 0)
        {
            printf("Nama tidak boleh kosong!!\n\n");
            continue;
        }
        if (isTextAllBlank(currentText))
        {
            printf("Nama tidak boleh hanya spasi!!\n");
            continue;
        }
        if (currentText.Length > 20)
        {
            printf("Nama tidak boleh lebih dari 20 karakter!!\n\n");
            continue;
        }

        isNameValid = true;
    }

    index = listUserIndexOfWithName(listUser, currentText.TabString);


    if (index == -1)
    {
        printf("Pengguna bernama %s tidak ditemukan.\n\n", currentText.TabString);
        return;
    }

    if (index == currentUser->id)
    {
        printf("Pengguna tidak bisa berteman dengan diri sendiri.\n\n");
        return;
    }

    if (isHasRelation(graphFriendship, currentUser->id, index))
    {
        printf("Anda sudah berteman dengan %s\n\n", currentText.TabString);
        return;
    }

    if (isPending(graphFriendship, currentUser->id, index))
    {
        printf("Anda sudah mengirimkan permintaan pertemanan kepada %s. Silakan tunggu hingga permintaan Anda disetujui.\n\n", currentText.TabString);
        return;
    }

    FriendReq fR;

    fR.idUser = currentUser->id;
    fR.manyFriend = currentUser->manyFriend;
    int i = 0;

    while (currentUser->name[i] != '\0')
    {
        fR.userName[i] = currentUser->name[i];
        i++;
    }
    fR.userName[i] = '\0';

    EnqueuePrioQueueFR(&(listUser.contents[index].friendReq), fR);

    addGraphFriendshipPending(&graphFriendship, currentUser->id, index);

    printf("Permintaan pertemanan kepada %s telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.\n", listUser.contents[index].name);

    // displayMatrixInt(graphFriendship.matrix);
    // printf("\n");
}

void friendshipReqList()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    int manyReq = prioQueueFRNBElmt(currentUser->friendReq);

    if (manyReq == 0)
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n\n");
    }
    else
    {
        printf("Terdapat %d permintaan pertemanan untuk Anda. \n", manyReq);
        // reSortPrioQueueFR(currentUser);

        PrintPrioQueueFR(currentUser->friendReq);
        printf("\n");
    }
}

void acceptFrienship()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    if (prioQueueFRNBElmt(currentUser->friendReq) == 0)
    {
        printf("Tidak ada permintaan pertemanan untuk Anda. \n\n");
        return;
    }

    // reSortPrioQueueFR(currentUser);

    FriendReq fR = currentUser->friendReq.T[currentUser->friendReq.HEAD];

    printf("Permintaan pertemanan teratas dari %s\n\n", fR.userName);

    PrintPrioQueueFRHead(currentUser->friendReq);

    printf("\n");

    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? \n(YA/TIDAK) ");
    STARTWORD();

    if (isWordEqual(currentWord, stringToWord("YA")))
    {
        FriendReq temp;
        DequeuePrioQueueFR(&(currentUser->friendReq), &temp);
        currentUser->manyFriend++;
        listUser.contents[temp.idUser].manyFriend++;
        addGraphFriendshipRelation(&graphFriendship, currentUser->id, temp.idUser);
        printf("Permintaan pertemanan dari %s telah disetujui. Selamat! Anda telah berteman dengan %s.", fR.userName, fR.userName);
    }
    else
    {
        FriendReq temp;
        DequeuePrioQueueFR(&(currentUser->friendReq), &temp);
        deleteGraphFriendshipRelation(&graphFriendship, currentUser->id, temp.idUser);
        printf("Permintaan pertemanan dari %s telah ditolak.\n", fR.userName);
    }
}