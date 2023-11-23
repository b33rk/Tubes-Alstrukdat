#include "friendshipfeature.h"

void friendlist()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    ListStatikInt relationships = getGraphFriendshipRelation(graphFriendship, currentUser->id);

    int manyRelationship = currentUser->manyFriend;

    if (manyRelationship == 0)
    {
        printf("%s belum mempunyai teman\n", currentUser->name);
        return;
    }

    printf("%s memiliki %d teman\n", currentUser->name, manyRelationship);
    printf("daftar teman %s\n", currentUser->name);

    int index = 0;
    for (index = 0; index < graphFriendship.matrix.rowEff; index++)
    {
        if (relationships.contents[index] == 1)
        {
            printf("| %s\n", listUser.contents[index].name);
        }
    }
    printf("\n");
}

void deleteFriend()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    boolean isNameValid = false;

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

    int index = listUserIndexOfWithName(listUser, currentText.TabString);

    if (index == -1)
    {
        printf("%s bukan teman Anda. \n\n", currentText.TabString);
        return;
    }

    printf("Apakah anda yakin ingin menghapus %s dari daftar teman anda?\n(YA/TIDAK) ", listUser.contents[index].name);
    STARTWORD();

    if (isWordEqual(currentWord, stringToWord("YA")))
    {
        deleteGraphFriendshipRelation(&graphFriendship, currentUser->id, listUser.contents[index].id);
        printf("\n%s berhasil dihapus dari daftar teman Anda.\n", listUser.contents[index].name);
        currentUser->manyFriend--;
        listUser.contents[index].manyFriend--;
    }
    else
    {
        printf("\nPenghapusan teman dibatalkan.\n");
    }
}