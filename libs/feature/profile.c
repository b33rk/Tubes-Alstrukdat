#include "profile.h"

void seeProfile(Word name)
{
    int index = listUserIndexOfWithName(listUser, name.TabWord);
    User userProfile = listUser.contents[index];

    if (index == -1)
    {
        printf("User dengan nama tersebut tidak ada!!\n\n");
        return;
    }

    if (!userProfile.isPublic)
    {
        if (!isHasRelation(graphFriendship, currentUser->id, index) && !isWordEqual(stringToWord(userProfile.name), stringToWord(currentUser->name)))
        {
            printf("Wah, akun %s diprivat nih. Ikuti dulu yuk untuk bisa melihat profil %s\n\n", name.TabWord, name.TabWord);
            return;
        }
    }

    displayUserProfile(userProfile, true);
    printf("\n");
}

void changeAccountType()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk. Masuk terlebih dahulu untuk mengganti tipe akun.\n\n");
        return;
    }
    if (currentUser->isPublic)
    {
        printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat?\n");
        printf("(YA/TIDAK) ");
        STARTWORD();
        if (isWordEqual(currentWord, stringToWord("YA")))
        {
            currentUser->isPublic = false;
            printf("Akun anda sudah diubah menjadi akun Privat.\n\n");
        }
        else
        {
            printf("Akun anda tetap menjadi akun Public.\n\n");
        }
    }
    else
    {
        printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik?\n");
        printf("(YA/TIDAK) ");
        STARTWORD();
        if (isWordEqual(currentWord, stringToWord("YA")))
        {
            currentUser->isPublic = true;
            printf("Akun anda sudah diubah menjadi akun Publik.\n\n");
        }
        else
        {
            printf("Akun anda tetap menjadi akun Privat.\n\n");
        }
    }
}

void changeProfilePicture()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk. Masuk terlebih dahulu untuk mengganti foto profil.\n\n");
        return;
    }
    printf("Foto profil anda saat ini adalah\n");

    displayMatrixPicture(currentUser->profilePicture);
    printf("\n");

    printf("Masukkan foto profil yang baru\n");
    readMatrixPicture(&(currentUser->profilePicture));

    printf("\nFoto profil anda sudah berhasil diganti!\n\n");
}

void changeProfile()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk. Masuk terlebih dahulu untuk mengganti profil.\n\n");
        return;
    }

    displayUserProfile(*currentUser, false);

    boolean isBioValid = false;

    while (!isBioValid)
    {
        printf("Masukkan bio akun:\n");
        STARTTEXT();
        printf("\n");

        if (currentText.Length > 135)
        {
            printf("Bio tidak boleh lebih dari 135 karakter!!\n\n");
            continue;
        }

        isBioValid = true;
    }

    if (currentText.Length != 0) setUserBio(currentUser, currentText.TabString);

    boolean isPhoneNumberValid = false;

    while (!isPhoneNumberValid)
    {
        printf("Masukkan No HP:\n");
        STARTSTRINGDIN();
        printf("\n");

        if (!isStringDinAllNumber(currentStringDin))
        {
            printf("No HP tidak valid. Masukkan lagi yuk!\n\n");
            continue;
        }

        isPhoneNumberValid = true;
    }

    if (!isListLinierCharEmpty(currentStringDin.TabString)) setUserPhoneNumber(currentUser, currentStringDin);

    deallocateStringDin();
    boolean isWetonValid = false;

    while (!isWetonValid)
    {
        printf("Masukkan Weton:\n");
        STARTWORD();
        printf("\n");

        Word lowerCase = wordToLowerCase(currentWord);
        if (currentWord.Length > 0 && !(isWordEqual(lowerCase, stringToWord("pahing")) || isWordEqual(lowerCase, stringToWord("kliwon")) || isWordEqual(lowerCase, stringToWord("wage")) || isWordEqual(lowerCase, stringToWord("pon")) || isWordEqual(lowerCase, stringToWord("legi"))))
        {
            printf("Weton anda tidak valid!!\n\n");
            continue;
        }

        isWetonValid = true;
    }

    if (currentWord.Length != 0) setUserWeton(currentUser, currentWord.TabWord);

    printf("\nProfil Anda sudah berhasil diperbarui!\n");
}
