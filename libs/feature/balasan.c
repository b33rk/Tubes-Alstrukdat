#include "balasan.h"

void displayAll(TreeOfBalasan T){
    displayNodeAll(T, 0, -2);
}

void displayNodeAll(TreeOfBalasan T, int Id, int indent){
    int i;
    NodeBalasanAddress node = getNodeInHashMap(TREE_HMP(T), Id);
    ListDin children = NODEBALASAN_CHILDREN(node);
    if (Id != 0){displayNode(node, indent);}
    for(i = 0; i < LISTDIN_NEFF(children); i++){
        displayNodeAll(T, LISTDIN_ELMT(children, i), indent + 2);
    }
}

void displayNode(NodeBalasanAddress N, int Indent){
    int i;
    int idAuthor = NODEBALASAN_IDAUTHOR(N);
    if(currentUser->id != idAuthor && !listUser.contents[idAuthor].isPublic && !isHasRelation(graphFriendship, currentUser->id, idAuthor)){
        for(i = 0; i < Indent; i++){printf(" ");}
        printf("| PRIVAT\n");
    }
    else{
        for(i = 0; i < Indent; i++){printf(" ");}
        printf("| ID = %d\n", NODEBALASAN_ID(N));
        for(i = 0; i < Indent; i++){printf(" ");}
        printf("| ");
        printText(charArrToText(listUser.contents[NODEBALASAN_IDAUTHOR(N)].name));
        printf("\n");
        for(i = 0; i < Indent; i++){printf(" ");}
        printf("| ");
        TulisDATETIME(NODEBALASAN_TIME(N));
        printf("\n");
        for(i = 0; i < Indent; i++){printf(" ");}
        printf("| ");
        printText(NODEBALASAN_TEXT(N));
        printf("\n");
    }
}

void balas(){
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    ADVWORD();
    int idKicau = wordToInt(currentWord);
    ADVWORD();
    int idBalasan = wordToInt(currentWord);

    int index = indexOfListDinKicauById(listKicauan, idKicau);
    if(index == -1){
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n\n");
    }
    else if (idBalasan != -1 && !isIdInTree(listKicauan.buffer[index].balasan, idBalasan)){
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n\n");
    }
    else{
        if (idBalasan != -1){
            int idAuthorBalasan = NODEBALASAN_IDAUTHOR(getNodeInTreeById(listKicauan.buffer[index].balasan, idBalasan));
            int idAuthorKicauers = listKicauan.buffer[index].idUser;
            if(!listUser.contents[idAuthorKicauers].isPublic && !isHasRelation(graphFriendship, currentUser->id, idAuthorKicauers)){
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n\n");
                return;
            }
            else if (!(listUser.contents[idAuthorBalasan].isPublic) && !(isHasRelation(graphFriendship, currentUser->id, idAuthorBalasan))){
                printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n\n");
                return;
            }
        }
        boolean isBalasanValid = false;
        while(!isBalasanValid){
            printf("Masukkan balasan:\n");
            STARTTEXT();
            if (currentText.Length == 0 || isTextAllBlank(currentText)){
                printf("Balasan tidak bisa berupa string kosong\n\n");
            }
            else{
                isBalasanValid = true;
            }
        }
        if (idBalasan == -1) {idBalasan = 0;}
        printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
        int idHasilBalasan = addToTreeAt(&listKicauan.buffer[index].balasan, currentText, currentUser->id, idBalasan);
        displayNode(getNodeInTreeById(listKicauan.buffer[index].balasan, idHasilBalasan), 0);
    }
}
void displayBalasan(){
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    ADVWORD();
    int idKicau = wordToInt(currentWord);
    int index = indexOfListDinKicauById(listKicauan, idKicau);
    if(index == -1){
        printf("Wah, tidak terdapat kicauan yang ingin Anda lihat!\n\n");
    }
    else{
        int idAuthor = listKicauan.buffer[index].idUser;
        if(!isHasRelation(graphFriendship, idAuthor, currentUser->id) && !listUser.contents[idAuthor].isPublic && currentUser->id != idAuthor){
            printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n\n");
        }
        else{
            if(TreeLength(listKicauan.buffer[index].balasan) == 1){
                printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n\n");
            }
            else{
                displayAll(listKicauan.buffer[index].balasan);
            }
        }
    }
}
void hapusBalasan(){
    if (currentUser == NULL)
    {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n\n");
        return;
    }

    ADVWORD();
    int idKicau = wordToInt(currentWord);
    ADVWORD();
    int idBalasan = wordToInt(currentWord);

    int index = indexOfListDinKicauById(listKicauan, idKicau);
    if(index == -1){
        printf("Kicauan tidak ditemukan\n\n");
    }
    else if (!isIdInTree(listKicauan.buffer[index].balasan, idBalasan)){
        printf("Balasan tidak ditemukan!\n\n");
    }
    else{
        int idAuthor = NODEBALASAN_IDAUTHOR(getNodeInTreeById(listKicauan.buffer[index].balasan, idBalasan));
        if (currentUser->id != idAuthor){
            printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n\n");
        }
        else{
            printf("Balasan berhasil dihapus\n\n");
            deleteTreeNodeAt(&listKicauan.buffer[index].balasan, idBalasan);
        }
    }
}