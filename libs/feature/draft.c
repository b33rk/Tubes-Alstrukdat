#include "draft.h"

void buatdraft(boolean isUbah)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    boolean isDraftValid = false;

    while (!isDraftValid)
    {
        if (!isUbah) printf("Masukkan draft: \n");
        else printf("Masukkan draft yang baru: \n");
        STARTTEXT();
        printf("\n");

        if (currentText.Length == 0)
        {
            printf("Draft Kicauan tidak boleh kosong!!\n\n");
            continue;
        }

        if (isTextAllBlank(currentText))
        {
            printf("Draft Kicauan tidak boleh hanya berisi spasi!!\n");
            continue;
        }

        isDraftValid = true;
    }

    Draft draft;
    CreateDraft(&draft);

    int j = 0;
    while (currentText.TabString[j] != '\0')
    {
        draft.text[j] = currentText.TabString[j];
        j++;
    }

    draft.text[j] = '\0';

    getCurrentDateTime(&draft.datetime);

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");

    STARTWORD();

    if (isWordEqual(currentWord, stringToWord("HAPUS")))
    {
        printf("Draf telah berhasil dihapus!\n\n");
    }
    else if (isWordEqual(currentWord, stringToWord("SIMPAN")))
    {
        pushStackDraft(&(currentUser->stackDraft), draft);
        printf("Draf telah berhasil disimpan!\n\n");
    }
    else if (isWordEqual(currentWord, stringToWord("TERBIT")))
    {
        Kicauan newKicau;
        CreateKicauan(&newKicau);

        newKicau.idUser = currentUser->id;
        newKicau.like = 0;
        newKicau.id = listKicauan.idCount + 1;
        listKicauan.idCount = listKicauan.idCount + 1;
        int j = 0;
        while (currentText.TabString[j] != '\0')
        {
            newKicau.text[j] = currentText.TabString[j];
            j++;
        }

        newKicau.text[j] = '\0';

        newKicau.datetime = draft.datetime;

        insertLastListDinKicau(&listKicauan, newKicau);

        printf("Selamat! Draft kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        printf("| ID = %d\n", newKicau.id);
        printf("| %s\n", currentUser->name);
        printf("| ");
        TulisDATETIME(newKicau.datetime);
        printf("\n");
        printf("| %s\n", newKicau.text);
        printf("| Disukai: %d\n\n", newKicau.like);
    }
}
// void hapusdraft()
// {
//     pop();
// }
// void simpandraft()
// {
//     pushStack(draf, d);
//     printf("Draf telah berhasil disimpan!\n");
// }
// void terbitdraft()
// {

//     printf("Selamat! Draf draft kicauan telah diterbitkan!\n");
//     printf("Detil kicauan:\n");
//     printf("|  ID:\n");
//     printf("|  \n");
//     printf("|  \n");
//     printf("|  Detil kicauan:\n");
//     printf("|  Disukai:\n");
// }

// void ubahdraft()
// {
//     popStack(draf);
//     buatdraft(*draf);
// }

void lihatdraft()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    if (isEmptyStackDraft(currentUser->stackDraft))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");
    }
    else
    {
        Draft d;
        popStackDraft(&(currentUser->stackDraft), &d);
        printf("Ini draf terakhir anda:\n");
        printf("| ");
        TulisDATETIME(d.datetime);
        printf("\n");
        printf("| %s\n\n", d.text);

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        STARTWORD();
        if (isWordEqual(currentWord, stringToWord("HAPUS")))
        {
            printf("Draf telah berhasil dihapus!\n\n");
        }
        else if (isWordEqual(currentWord, stringToWord("UBAH")))
        {
            printf("\n");
            buatdraft(true);
        }
        else if (isWordEqual(currentWord, stringToWord("TERBIT")))
        {
            Kicauan newKicau;
            CreateKicauan(&newKicau);

            newKicau.idUser = currentUser->id;
            newKicau.like = 0;
            newKicau.id = listKicauan.idCount + 1;
            listKicauan.idCount = listKicauan.idCount + 1;
            int j = 0;
            while (currentText.TabString[j] != '\0')
            {
                newKicau.text[j] = currentText.TabString[j];
                j++;
            }

            newKicau.text[j] = '\0';

            newKicau.datetime = d.datetime;

            insertLastListDinKicau(&listKicauan, newKicau);

            printf("Selamat! Draft kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d\n", newKicau.id);
            printf("| %s\n", currentUser->name);
            printf("| ");
            TulisDATETIME(newKicau.datetime);
            printf("\n");
            printf("| %s\n", newKicau.text);
            printf("| Disukai: %d\n\n", newKicau.like);
        }
        else if (isWordEqual(currentWord, stringToWord("KEMBALI")))
        {
            pushStackDraft(&(currentUser->stackDraft), d);
        }
    }
}