#include "utasfeature.h"

void createNewUtas(int IDKicau) {
    int idx = indexOfListDinKicauById(listKicauan, IDKicau);
    if (currentUser == NULL) {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    }

    if (idx == -1) {
        printf("\nKicauan tidak ditemukan\n");
        return;
    }
    if (listKicauan.buffer[idx].idUser != currentUser->id) {
        printf("\nKicauan ini bukan milik Anda!\n");
        return;
    }
    
    if (listKicauan.buffer[idx].idUtas != -1) { // sudah ada Utas dengan IDKicau
        printf("\nTidak bisa membuat utas dengan Kicauan utama yang sama!\n");
        return;
    }
    Utas Utasan;
    CreateUtas(&Utasan);

    ElUtas tempUtas;

    tempUtas.idKicau = IDKicau;
    tempUtas.idUser = currentUser->id;
    tempUtas.datetime = listKicauan.buffer[idx].datetime;
    tempUtas.id = listUtas.idCount;
    
    int j = 0;
    while (listKicauan.buffer[idx].text[j] != '\0') {
        tempUtas.text[j] = listKicauan.buffer[idx].text[j];
        j++;
    }
    tempUtas.text[j] = '\0';

    insertLastUtas(&Utasan, tempUtas);
    printf("\nUtas berhasil dibuat!\n");
    
    boolean end = false;
    
    while (!end) {
        ElUtas tempUtas1;
        boolean isKicauanValid = false;
        while(!isKicauanValid) {
            printf("Masukkan kicauan:\n");
            STARTTEXT();
            printf("\n");
            if (currentText.Length == 0) {
                printf("Kicauan tidak boleh kosong!!\n\n");
                continue;
            }

            isKicauanValid = true;
        }
        tempUtas1.idUser = currentUser->id;
        tempUtas1.idKicau = IDKicau;
        tempUtas1.id = listUtas.idCount;

        int j = 0;
        while (currentText.TabString[j] != '\0') {
            tempUtas1.text[j] = currentText.TabString[j];
            j++;
        }
        tempUtas1.text[j] = '\0';
        
        getCurrentDateTime(&tempUtas1.datetime);

        insertLastUtas(&Utasan, tempUtas1);

        printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
        STARTWORD();
        if (isWordEqual(currentWord, stringToWord("TIDAK"))) {
            end = true;
        }
    }
    listKicauan.buffer[idx].idUtas = listUtas.idCount;

    insertLastListDinUtas(&listUtas, Utasan);
    listUtas.idCount++;
    printf("\nUtas selesai!\n");
}


void sambungUtas(int IDUtas, int index) {
    if (currentUser == NULL) {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
    }

    Utas u = listUtas.buffer[IDUtas - 1];
    if (u == NULL) {
        printf("\nUtas tidak ditemukan!\n");
        return;
    }
    if (index > lengthUtas(u)) {
        printf("\nIndex terlalu tinggi!\n");
        return;
    }
    int IDKicau = u->info.idKicau;
    int idx = indexOfListDinKicauById(listKicauan, IDKicau);
    if (listKicauan.buffer[idx].idUser != currentUser->id) {
        printf("\nUtas ini bukan milik Anda!\n");
        return;
    }

    ElUtas val; 

    boolean isKicauanValid = false;
    while(!isKicauanValid) {
        printf("Masukkan kicauan:\n");
        STARTTEXT();
        if (currentText.Length == 0) {
            printf("Kicauan tidak boleh kosong!!\n\n");
            continue;
        }

        isKicauanValid = true;
    }

    val.idUser = currentUser->id;
    val.id = listUtas.idCount;
    val.idKicau = IDKicau;

    int j = 0;
    while (currentText.TabString[j] != '\0') {
        val.text[j] = currentText.TabString[j];
        j++;
    }
    val.text[j] = '\0';

    getCurrentDateTime(&val.datetime);
    insertAtUtas(&u, val, index);
}


void hapusUtas(int IDUtas, int index) {
    if (currentUser == NULL) {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    Utas u = listUtas.buffer[IDUtas - 1];
    if (IDUtas > listUtas.idCount) {
        printf("\nUtas tidak ditemukan!\n");
        return;
    }

    if (index >= lengthUtas(u)) {
        printf("\nKicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        return;
    }

    if (u->info.idUser != currentUser->id) {
        printf("\nAnda tidak bisa menghapus kicauan dalam utas ini!\n");
        return;
    }
    if (index == 0) {
        printf("\nAnda tidak bisa menghapus kicauan utama!\n");
    } else {
        ElUtas val;
        deleteAtUtas(&u, index, &val);
        printf("\nKicauan sambungan berhasil dihapus!\n");
    }
}

void cetakUtas(int IDUtas) {
    if (currentUser == NULL) {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }
    
    Utas u = listUtas.buffer[IDUtas - 1];
    if (u == NULL) {
        printf("\nUtas tidak ditemukan!\n");
        return;
    }

    int idUser = u->info.idUser;
    if (idUser != currentUser->id) {
        if (!isHasRelation(graphFriendship, currentUser->id, idUser)) {
            if (!listUser.contents[idUser].isPublic) {
                printf("\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
            }
            return;
        }
    }

    AddressUtas p = u;

    printf("\n| ID = %d\n", IDUtas);
    printf("| %s\n", listUser.contents[idUser].name);
    printf("| "); TulisDATETIME(p->info.datetime);
    printf("\n");
    printf("| %s\n\n", p->info.text);

    p = p->next;
    int index = 1;
    while (p != NULL) {
        printf("  | INDEX = %d\n", index);
        printf("  | %s\n", listUser.contents[idUser].name);
        printf("  | "); TulisDATETIME(p->info.datetime); printf("\n");
        printf("  | %s\n\n", p->info.text);  
        p = p->next;
        index++;
    }
}