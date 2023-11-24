#include "kicauan.h"

void publishKicauan()
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    boolean isKicauanValid = false;

    while (!isKicauanValid)
    {
        printf("Masukkan kicauan: \n");
        STARTTEXT();
        printf("\n");

        if (currentText.Length == 0)
        {
            printf("Kicauan tidak boleh kosong!!\n\n");
            continue;
        }

        if (isTextAllBlank(currentText))
        {
            printf("Kicauan tidak boleh hanya berisi spasi!!\n");
            continue;
        }

        isKicauanValid = true;
    }

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

    getCurrentDateTime(&newKicau.datetime);

    insertLastListDinKicau(&listKicauan, newKicau);

    printf("Selamat! Kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    printf("| ID = %d\n", newKicau.id);
    printf("| %s\n", currentUser->name);
    printf("| ");
    TulisDATETIME(newKicau.datetime);
    printf("\n");
    printf("| %s\n", newKicau.text);
    printf("| Disukai: %d\n\n", newKicau.like);
}

void displayKicauan()
{
    sortListDinKicauByDateTime(&listKicauan, false);

    int i;
    int count = 0;
    for (i = 0; i < listKicauan.nEff; i++){
        if (listKicauan.buffer[i].idUser == currentUser->id || isHasRelation(graphFriendship ,currentUser->id, listKicauan.buffer[i].idUser)){
            printf("| ID = %d\n", listKicauan.buffer[i].id);
            printf("| %s\n", listUser.contents[listKicauan.buffer[i].idUser].name);
            printf("| ");
            TulisDATETIME(listKicauan.buffer[i].datetime);
            printf("\n");
            printf("| %s\n", listKicauan.buffer[i].text);
            printf("| Disukai: %d\n\n", listKicauan.buffer[i].like);
            count++;
        }
    }

    if (count == 0){
        printf("Tidak ada kicauan!!\n\n");
    }
}

void likeKicauan(int idKicau)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    int index = indexOfListDinKicauById(listKicauan, idKicau);

    if (index != -1)
    {
        if (listUser.contents[listKicauan.buffer[index].idUser].isPublic)
        {

            listKicauan.buffer[index].like++;
            printf("Selamat! Kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d\n", listKicauan.buffer[index].id);
            printf("| %s\n", listUser.contents[listKicauan.buffer[index].idUser].name);
            printf("| ");
            TulisDATETIME(listKicauan.buffer[index].datetime);
            printf("\n");
            printf("| %s\n", listKicauan.buffer[index].text);
            printf("| Disukai: %d\n\n", listKicauan.buffer[index].like);
        }
        else
        {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n\n");
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicau);
    }
}

void updateKicauan(int idKicau)
{
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    int index = indexOfListDinKicauById(listKicauan, idKicau);

    if (index != -1)
    {

        if (listKicauan.buffer[index].idUser == currentUser->id)
        {
            boolean isKicauanValid = false;

            while (!isKicauanValid)
            {
                printf("Masukkan kicauan: \n");
                STARTTEXT();
                printf("\n");

                if (currentText.Length == 0)
                {
                    printf("Kicauan tidak boleh kosong!!\n\n");
                    continue;
                }

                if (isTextAllBlank(currentText))
                {
                    printf("Kicauan tidak boleh hanya berisi spasi!!\n");
                    continue;
                }

                isKicauanValid = true;
            }

            int j = 0;
            while (currentText.TabString[j] != '\0')
            {
                listKicauan.buffer[index].text[j] = currentText.TabString[j];
                j++;
            }

            listKicauan.buffer[index].text[j] = '\0';


            printf("Selamat! Kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d\n", idKicau);
            printf("| %s\n", listUser.contents[listKicauan.buffer[index].idUser].name);
            printf("| ");
            TulisDATETIME(listKicauan.buffer[index].datetime);
            printf("\n");
            printf("| %s\n", listKicauan.buffer[index].text);
            printf("| Disukai: %d\n\n", listKicauan.buffer[index].like);
        }
        else
        {
            printf("Kicauan dengan ID = %d bukan milikmu!\n\n", idKicau);
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", idKicau);
    }
}