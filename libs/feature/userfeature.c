#include "userfeature.h"

void registerUser()
{

    if (isListUserFull(listUser))
    {
        printf("User sudah penuh!!\n\n");
        return;
    }

    if (currentUser != NULL)
    {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n\n");
        return;
    }

    boolean isNameValid = false;
    int index;

    while (!isNameValid)
    {
        printf("Masukkan nama: \n");
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
        index = listUserIndexOfWithName(listUser, currentText.TabString);

        if (index != -1)
        {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n\n");
            continue;
        }

        isNameValid = true;
    }

    User newUser;
    CreateUser(&newUser);
    newUser.id = listUserLength(listUser);

    setUserName(&newUser, currentText.TabString);

    boolean isPassValid = false;

    while (!isPassValid)
    {
        printf("Masukkan password: \n");
        STARTTEXT();
        printf("\n");
        if (currentText.Length == 0)
        {
            printf("Password tidak boleh kosong!!\n\n");
            continue;
        }
        if (isTextAllBlank(currentText))
        {
            printf("Password tidak boleh hanya spasi!!\n");
            continue;
        }
        if (currentText.Length > 20)
        {
            printf("Password tidak boleh lebih dari 20 karakter!!\n\n");
            continue;
        }

        isPassValid = true;
    }

    setUserPassword(&newUser, currentText.TabString);

    listUserInsertLast(&listUser, newUser);

    printf("\nPengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
}

void loginUser()
{
    if (currentUser != NULL)
    {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!\n\n");
        return;
    }
    boolean isNameValid = false;
    int index;

    while (!isNameValid)
    {
        printf("Masukkan nama: \n");
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

        index = listUserIndexOfWithName(listUser, currentText.TabString);

        if (index == -1)
        {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
            continue;
        }

        isNameValid = true;
    }

    boolean isPassValid = false;
    boolean isPassCorrect = false;

    while (!isPassValid)
    {
        printf("Masukkan password: \n");
        STARTTEXT();
        printf("\n");
        if (currentText.Length == 0)
        {
            printf("Passwird tidak boleh kosong!!\n\n");
            continue;
        }
        if (isTextAllBlank(currentText))
        {
            printf("Password tidak boleh hanya spasi!!\n");
            continue;
        }
        if (currentText.Length > 20)
        {
            printf("Password tidak boleh lebih dari 20 karakter!!\n\n");
            continue;
        }
        isPassCorrect = isTextEqual(charArrToText(listUser.contents[index].password), charArrToText(currentText.TabString));

        if (!isPassCorrect)
        {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n\n");
            continue;
        }
        isPassValid = true;
    }

    currentUser = &(listUser.contents[index]);

    printf("Anda telah berhasil masuk dengan nama pengguna %s. Mari menjelajahi BurBir bersama Ande-Ande Lumut!", listUser.contents[index].name);
}

void logoutUser()
{
    if (currentUser->id == -1)
    {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    currentUser = NULL;

    printf("Anda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
}