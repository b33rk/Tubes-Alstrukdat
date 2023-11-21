#include "utasfeature.h"

void makeUtas(int idKicau)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    int index = indexOfListDinKicauById(listKicauan, idKicau);

    if (index == -1)
    {
        printf("Kicauan tidak ditemukan\n");
        return;
    }

    if (listKicauan.buffer[index].idUtas != -1)
    {
        printf("Kicauan ini sudah menjadi utas!!\n");
        return;
    }

    if (listKicauan.buffer[index].idUser != currentUser->id)
    {
        printf("Kicauan ini bukan milik Anda!!\n");
    }

    boolean stop = false;

    Utas u;
    CreateUtas(&u);

    ElUtas elutas1;
    int j = 0;
    while (listKicauan.buffer[index].text[j] != '\0')
    {
        elutas1.text[j] = listKicauan.buffer[index].text[j];
        j++;
    }

    elutas1.text[j] = '\0';
    elutas1.id = listUtas.idCount;
    elutas1.idKicau = idKicau;
    elutas1.datetime = listKicauan.buffer[index].datetime;
    elutas1.idUser = currentUser->id;
    insertLastUtas(&u, elutas1);
    while (!stop)
    {

        boolean isUtasValid = false;
        while (!isUtasValid)
        {
            printf("\nMasukkan kicauan: \n");
            STARTTEXT();
            printf("\n");

            if (currentText.Length == 0)
            {
                printf("Kicauan tidak boleh kosong!!\n\n");
                continue;
            }


            isUtasValid = true;
        }

        ElUtas elutas;
        int j = 0;
        while (currentText.TabString[j] != '\0')
        {
            elutas.text[j] = currentText.TabString[j];
            j++;
        }

        elutas.text[j] = '\0';
        elutas.id = listUtas.idCount;
        elutas.idKicau = idKicau;

        getCurrentDateTime(&elutas.datetime);
        elutas.idUser = currentUser->id;
        insertLastUtas(&u, elutas);

        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
        STARTWORD();
        if (isWordEqual(currentWord, stringToWord("TIDAK")))
        {
            stop = true;
        }
    }

    listKicauan.buffer[index].idUtas = listUtas.idCount;

    insertLastListDinUtas(&listUtas, u);
    listUtas.idCount++;
    printf("Utas selesai\n");
}

void cetakUtas(int idUtas)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    Utas curr = listUtas.buffer[idUtas - 1];

    if (curr == NULL)
    {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    if (!listUser.contents[curr->info.idUser].isPublic)
    {
        printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
    }

    printf("| ID = %d\n", curr->info.idKicau);
    printf("| %s\n", listUser.contents[curr->info.idUser].name);
    printf("| ");
    TulisDATETIME(curr->info.datetime);
    printf("\n");
    printf("| %s\n\n", curr->info.text);

    curr = curr->next;
    int index = 1;
    while (curr != NULL)
    {
        printf("   | INDEX = %d\n", index++);
        printf("   | %s\n", listUser.contents[curr->info.idUser].name);
        printf("   | ");
        TulisDATETIME(curr->info.datetime);
        printf("\n");
        printf("   | %s\n\n", curr->info.text);
        curr = curr->next;
    }
}

void sambungUtas(int idUtas, int index)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    Utas curr = listUtas.buffer[idUtas - 1];

    if (curr == NULL)
    {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    int len = lengthUtas(curr);
    if (index > len)
    {
        printf("Index terlalu tinggi!\n");
        return;
    }

    if (curr->info.idUser != currentUser->id)
    {
        printf("Anda tidak bisa menyambung utas ini\n");
        return;
    }

    boolean isUtasValid = false;
    while (!isUtasValid)
    {
        printf("Masukkan kicauan: \n");
        STARTTEXT();
        printf("\n");

        if (currentText.Length == 0)
        {
            printf("Kicauan tidak boleh kosong!!\n\n");
            continue;
        }

        isUtasValid = true;
    }

    ElUtas elutas;
    int j = 0;
    while (currentText.TabString[j] != '\0')
    {
        elutas.text[j] = currentText.TabString[j];
        j++;
    }

    elutas.text[j] = '\0';
    elutas.id = curr->info.id;
    elutas.idKicau = curr->info.id;

    getCurrentDateTime(&elutas.datetime);
    elutas.idUser = curr->info.id;
    insertAtUtas(&listUtas.buffer[idUtas - 1], elutas, index);
    printf("Sambung utas berhasil\n");
}

void hapusUtas(int idUtas, int index)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    Utas curr = listUtas.buffer[idUtas - 1];

    if (curr == NULL)
    {
        printf("Utas tidak ditemukan!\n");
        return;
    }

    if (index == 0)
    {
        printf("Anda tidak bisa menghapus kicauan utama!\n");
        return;
    }

    int len = lengthUtas(curr);
    if (index > len)
    {
        printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        return;
    }

    if (curr->info.idUser != currentUser->id)
    {
        printf("Anda tidak bisa menghapus kicauan utas ini\n");
        return;
    }

    ElUtas elutas;

    deleteAtUtas(&listUtas.buffer[idUtas - 1], index, &elutas);

    printf("Kicauan sambungan berhasil dihapus!\n\n");

}