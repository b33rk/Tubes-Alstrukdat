#include "utas.h"

void getCurrentDatetime(char *datetime);

void createNewUtas(int IDKicau) {
    int idx = indexOfListDinKicauById(listKicauan, IDKicau);
    if (idx == -1) {
        printf("\nKicauan tidak ditemukan\n");
    } else {
        if (listKicauan.buffer[idx].idUser != currentUser->id) {
            printf("\nUtas ini bukan milik Anda!\n");
        } else {
            int idxUtas = indexOfListDinUtasByIDKicau(listUtas, IDKicau);
            if (idxUtas != -1) { // sudah ada Utas dengan IDKicau
                printf("\nTidak bisa membuat utas dengan Kicauan utama yang sama!\n");
            } else {
                idxUtas = listDinUtasLength(listUtas);
                Utas Utasan;
                CreateUtas(&Utasan);

                ElTypeUtas tempUtas;

                Utasan.IDKicau = IDKicau;
                tempUtas.author = listKicauan.buffer[idx].idUser;
                tempUtas.datetime = listKicauan.buffer[idx].datetime;
                
                int j = 0;
                while (listKicauan.buffer[idx].text[j] != '\0') {
                    tempUtas.text[j] = currentText.TabString[j];
                    j++;
                }
                tempUtas.text[j] = '\0';

                insertFirstUtas(&Utasan, tempUtas);

                insertLastListDinUtas(&listUtas, Utasan);
                listUtas.neff += 1;
                printf("\nUtas berhasil dibuat!\n");
                
                boolean end = false;
                
                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                ADVWORD;
                if (isWordEqual(currentWord, stringToWord("TIDAK"))) {
                    end = true;
                    printf("\nUtas selesai!\n");
                }

                while (!end) {
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
                    tempUtas.author = currentUser;
                    
                    while (currentText.TabString[j] != '\0') {
                        tempUtas.text[j] = currentText.TabString[j];
                        j++;
                    }

                    tempUtas.text[j] = '\0';
                    getCurrentDatetime(&tempUtas.datetime);

                    insertLastUtas(&Utasan, tempUtas);

                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
                    ADVWORD;
                    if (isWordEqual(currentWord, stringToWord("TIDAK"))) {
                        end = true;
                        printf("\nUtas selesai!\n");
                    }
                }
            }
        }
    }
}

void sambungUtas(int IDUtas, int index) {
    int idxUtas = IDUtas - 1; 
    if (idxUtas >= listDinUtasLength(listUtas)) {
        printf("\nUtas tidak ditemukan!\n");
    } else {
        if (index > lengthUtas(listUtas.buffer[idxUtas])) {
            printf("\nIndex terlalu tinggi!\n");
        } else {
            int IDKicau = listUtas.buffer[idxUtas].IDKicau;
            int idx = indexOfListDinKicauById(listKicauan, IDKicau);
            if (listKicauan.buffer[idx].idUser != currentUser->id) {
                printf("\nUtas ini bukan milik Anda!\n");
            } else {
                Utas utas = listUtas.buffer[idxUtas];
                ElTypeUtas val; 

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

                int j = 0;
                while (currentText.TabString[j] != '\0') {
                    val.text[j] = currentText.TabString[j];
                    j++;
                }
                val.text[j] = '\0';

                val.author = currentUser->id;
                getCurrentDateTime(&val.datetime);
                
                insertAtUtas(&utas, val, index);
            }
        }
    }
}

void hapusUtas(int IDUtas, int index) {
    int idxUtas = IDUtas - 1; 
    if (idxUtas >= listDinUtasLength(listUtas)) {
        printf("\nUtas tidak ditemukan!\n");
    } else {
        if (index > lengthUtas(listUtas.buffer[idxUtas])) {
            printf("\nKicauan sambungan dengan index %d tidak ditemukan pada utas!\n", index);
        } else {
            int IDKicau = listUtas.buffer[idxUtas].IDKicau;
            int idx = indexOfListDinKicauById(listKicauan, IDKicau);

            if (listKicauan.buffer[idx].idUser != currentUser->id) {
                printf("\nAnda tidak bisa menghapus kicauan dalam utas ini!\n");
            } else {
                if (index == 0) {
                    printf("\nAnda tidak bisa menghapus kicauan utama!\n");
                } else {
                    Utas utas = listUtas.buffer[idxUtas];
                    ElTypeUtas val;
                    deleteAtUtas(&utas, index, &val);
                    printf("\nKicauan sambungan berhasil dihapus!\n");
                }
            }
        }
    }
}

void cetakUtas(int IDUtas) {
    int idxUtas = IDUtas - 1;
    if (idxUtas >= listDinUtasLength(listUtas)) {
        printf("\nUtas tidak ditemukan!\n");
    } else {
        int IDKicau = listUtas.buffer[idxUtas].IDKicau;
        int idx = indexOfListDinKicauById(listKicauan, IDKicau);

        int idUser = listKicauan.buffer[idx].idUser;
        int idxUser = listUserIndexOfWithID(listUser, idUser);
        if (!isHasRelation(graphFriendship, currentUser->id, idUser)) {
            if (!listUser.contents[idxUser].isPublic) {
                printf("\nAkun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
            }
        } else {
            Utas utas = listUtas.buffer[idxUtas];
            AddrUtas p = utas.first;

            printf("| ID = %d\n", IDUtas);
            printf("| %s\n", listUser.contents[idxUser].name);
            printf("| "); TulisDATETIME(p->info.datetime);
            printf("\n");
            printf("| %s\n", p->info.text);

            int index = 1;
            while (p != NULL) {
                printf("  | INDEX = %d\n", index);
                printf("  | %s\n", listUser.contents[idxUser].name);
                printf("  | "); TulisDATETIME(p->info.datetime); printf("\n");
                printf("  | %s\n", p->info.text);    
            }
        }
    }
}