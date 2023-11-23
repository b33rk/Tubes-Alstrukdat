#include "loadsave.h"

int isDirectoryExists(const char *path)
{
    struct stat info;

    if (stat(path, &info) == 0)
    {
        if (S_ISDIR(info.st_mode))
        {
            return 1;
        }
    }

    return 0;
}

void save()
{
    boolean isInputValid = false;

    while (!isInputValid)
    {
        printf("Masukkan nama folder: \n");
        STARTTEXT();
        printf("\n");

        if (currentText.Length == 0)
        {
            printf("Nama folder tidak boleh kosong!!\n\n");
            continue;
        }

        if (isTextAllBlank(currentText))
        {
            printf("Nama folder tidak boleh hanya berisi spasi!!\n");
            continue;
        }

        isInputValid = true;
    }

    // printf("%s\n", currentText.TabString);

    Text w = appendText(charArrToText("config/"), currentText);

    // printText(currentText);
    // printf("  tes1\n");
    // printText(w);
    // printf("  tes2\n");

    if (isDirectoryExists(w.TabString) == 0)
    {
        printf("Belum terdapat %s. Akan dilakukan pembuatan %s terlebih dahulu.\n\n", currentText.TabString, currentText.TabString);
        printf("Mohon tunggu...\n");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n");
#ifndef _WIN32
        int status = mkdir(w.TabString, 0777);
#else
        int status = _mkdir(w.TabString);
#endif

        // printf("  tes3\n");

        if (status != 0)
        {
            printf("Gagal membuat directory\n");
            return;
        }

        printf("%s sudah berhasil dibuat.\n", currentText.TabString);
    }

    // printf("%d\n", status);
    saveUser(w);
    saveKicauan(w);
    saveDraft(w);
    saveBalasan(w);
    saveUtas(w);

    printf("Mohon tunggu...\n");
    printf("1...\n");
    printf("2...\n");
    printf("3...\n");
    printf("Penyimpanan telah berhasil dilakukan!\n\n");
}

void saveUtas(Text rootPath)
{
    Text wUtas = appendText(rootPath, charArrToText("/utas.config"));

    FILE *futas = fopen(wUtas.TabString, "w");

    int countKicauan = listDinUtasLength(listUtas);
    fprintf(futas, "%d\n", countKicauan);

    int i;
    for (i = 0; i < countKicauan; i++)
    {
        Utas u = listUtas.buffer[i];
        fprintf(futas, "%d\n", u->info.idKicau);

        int countUtas = lengthUtas(u) - 1;

        fprintf(futas, "%d\n", countUtas);

        u = u->next;
        while (u != NULL)
        {
            fprintf(futas, "%s\n", u->info.text);
            fprintf(futas, "%s\n", listUser.contents[u->info.idUser].name);
            TulisDATETIMEFile(u->info.datetime, futas);
            fprintf(futas, "\n");
            u = u->next;
        }
    }
    fclose(futas);
}

void saveDraft(Text rootPath)
{
    Text wDraft = appendText(rootPath, charArrToText("/draft.config"));

    FILE *fdraft = fopen(wDraft.TabString, "w");
    int count = 0;
    int i;
    for (i = 0; i < listUserLength(listUser); i++)
    {
        if (!isEmptyStackDraft(listUser.contents[i].stackDraft))
        {
            count++;
        }
    }
    fprintf(fdraft, "%d\n", count);

    for (i = 0; i < listUserLength(listUser); i++)
    {
        if (!isEmptyStackDraft(listUser.contents[i].stackDraft))
        {
            int len = lengthStackDraft(listUser.contents[i].stackDraft);
            fprintf(fdraft, "%s %d\n", listUser.contents[i].name, len);
            AddressDraft ad = listUser.contents[i].stackDraft.addrTop;
            while (ad != NULL)
            {
                fprintf(fdraft, "%s\n", ad->info.text);
                TulisDATETIMEFile(ad->info.datetime, fdraft);
                fprintf(fdraft, "\n");
                ad = ad->next;
            }
        }
    }
    fclose(fdraft);
}

void saveKicauan(Text rootPath)
{
    Text wKicau = appendText(rootPath, charArrToText("/kicauan.config"));

    FILE *fkicau = fopen(wKicau.TabString, "w");
    fprintf(fkicau, "%d\n", listKicauan.nEff);

    int i;
    for (i = 0; i < listKicauan.nEff; i++)
    {
        Kicauan k = listKicauan.buffer[i];
        fprintf(fkicau, "%d\n", k.id);
        fprintf(fkicau, "%s\n", k.text);
        fprintf(fkicau, "%d\n", k.like);
        fprintf(fkicau, "%s\n", listUser.contents[k.idUser].name);
        TulisDATETIMEFile(k.datetime, fkicau);
        fprintf(fkicau, "\n");
    }

    fclose(fkicau);
}

void saveUser(Text rootPath)
{
    Text wUser = appendText(rootPath, charArrToText("/pengguna.config"));
    // printText(wUser);
    // printf("  tes3\n");

    FILE *fuser = fopen(wUser.TabString, "w");

    int manyUser = listUserLength(listUser);

    // printf("%d\n", manyUser);

    fprintf(fuser, "%d\n", manyUser);

    if (fuser == NULL)
    {
        perror("Error opening file");
        return;
    }
    int i;
    for (i = 0; i < manyUser; i++)
    {
        fprintf(fuser, "%s\n", listUser.contents[i].name);
        fprintf(fuser, "%s\n", listUser.contents[i].password);
        fprintf(fuser, "%s\n", listUser.contents[i].bio);
        AddrChar curr = listUser.contents[i].phoneNumber.TabString;
        while (curr != NULL)
        {
            fprintf(fuser, "%c", curr->info);
            curr = curr->next;
        }
        fprintf(fuser, "\n");
        fprintf(fuser, "%s\n", listUser.contents[i].weton);
        if (listUser.contents[i].isPublic)
        {
            fprintf(fuser, "%s\n", "Public");
        }
        else
        {
            fprintf(fuser, "%s\n", "Privat");
        }

        if (!listUser.contents[i].profilePicture.isSetup)
        {
            fprintf(fuser, "\n\n\n\n\n");
        }
        else
        {
            int k, j;
            for (k = 0; k < 5; k++)
            {
                for (j = 0; j < 5; j++)
                {
                    if (j != 4)
                        fprintf(fuser, "%c %c ", listUser.contents[i].profilePicture.color.mem[k][j], listUser.contents[i].profilePicture.symbol.mem[k][j]);
                    else
                        fprintf(fuser, "%c %c", listUser.contents[i].profilePicture.color.mem[k][j], listUser.contents[i].profilePicture.symbol.mem[k][j]);
                }
                fprintf(fuser, "\n");
            }
        }
    }

    int k, j;
    for (k = 0; k < manyUser; k++)
    {
        for (j = 0; j < manyUser; j++)
        {
            if (j != manyUser - 1)
                fprintf(fuser, "%d ", graphFriendship.matrix.mem[j][k] != 1 ? 0 : 1);
            else
                fprintf(fuser, "%d", graphFriendship.matrix.mem[j][k] != 1 ? 0 : 1);
        }
        fprintf(fuser, "\n");
    }

    int pending = countPending(graphFriendship);
    // printf("pending %d\n", pending);
    fprintf(fuser, "%d\n", pending);
    for (k = 0; k < manyUser; k++)
    {
        if (listUser.contents[k].friendReq.HEAD != -1)
        {
            for (j = listUser.contents[k].friendReq.HEAD; j <= listUser.contents[k].friendReq.TAIL; j++)
            {
                FriendReq f = listUser.contents[k].friendReq.T[j];
                // printf("%d %d %d\n", f.idUser, k, f.manyFriend);
                fprintf(fuser, "%d %d %d\n", f.idUser, k, f.manyFriend);
            }
        }
    }

    fclose(fuser);
}

void saveBalasan(Text rootPath){
    Text wBalasan = appendText(rootPath, charArrToText("/balasan.config"));

    FILE *fbalasan = fopen(wBalasan.TabString, "w");

    int kicauanWithBalasan = 0;

    int i;
    for(i = 0; i < listKicauan.nEff; i++){
        if(TreeLength(listKicauan.buffer[i].balasan) > 1){
            kicauanWithBalasan++;
        }
    }
    fprintf(fbalasan, "%d\n", kicauanWithBalasan);

    ListNode currentProcessedNode;
    ListNode nextProcessedNode;

    for(i = 0; i < listKicauan.nEff; i++){

        if(TreeLength(listKicauan.buffer[i].balasan) > 1){
            // For Nodes that have balasan

            CreateListNode(&currentProcessedNode);

            // print first 2 lines
            fprintf(fbalasan, "%d\n", listKicauan.buffer[i].id);
            fprintf(fbalasan, "%d\n", TreeLength(listKicauan.buffer[i].balasan) - 1);

            // Examine Tree Of Balasan of current kicauan
            TreeOfBalasan currentBalasanTree = listKicauan.buffer[i].balasan;

            // BFS
            insertListNode(&currentProcessedNode, TREE_MASTER(currentBalasanTree));

            while(!isListNodeEmpty(currentProcessedNode)){
                CreateListNode(&nextProcessedNode);
                int j;
                for(j = 0; j < LISTNODE_NEFF(currentProcessedNode); j++){
                    NodeBalasanAddress currentBalasanNode = currentProcessedNode.buffer[j];

                    // Print Information
                    int idSelf = NODEBALASAN_ID(currentBalasanNode);
                    if(idSelf != 0){
                        int idParent = NODEBALASAN_ID(NODEBALASAN_PARENT(currentBalasanNode));
                        if(idParent == 0){idParent = -1;}
                        fprintf(fbalasan, "%d %d\n", idParent, idSelf);
                        fprintf(fbalasan, "%s\n", NODEBALASAN_TEXT(currentBalasanNode).TabString);
                        fprintf(fbalasan, "%s\n", listUser.contents[NODEBALASAN_IDAUTHOR(currentBalasanNode)].name);
                        fprintf(fbalasan, "%.2d/%.2d/%.4d %.2d:%.2d:%.2d\n", 
                        NODEBALASAN_TIME(currentBalasanNode).DD,
                        NODEBALASAN_TIME(currentBalasanNode).MM,
                        NODEBALASAN_TIME(currentBalasanNode).YYYY,
                        NODEBALASAN_TIME(currentBalasanNode).T.HH,
                        NODEBALASAN_TIME(currentBalasanNode).T.MM,
                        NODEBALASAN_TIME(currentBalasanNode).T.SS);
                    }

                    // For each Children, get node from tree then add to queue
                    int k;
                    for(k = 0; k < LISTDIN_NEFF(NODEBALASAN_CHILDREN(currentBalasanNode)); k++){
                        insertListNode(&nextProcessedNode, 
                        getNodeInTreeById(currentBalasanTree, NODEBALASAN_CHILDREN(currentBalasanNode).buffer[k]));
                    }
                }
                currentProcessedNode = nextProcessedNode;
            }

        }
    }

    // for (i = 0; i < listKicauan.nEff; i++)
    // {
    //     Kicauan k = listKicauan.buffer[i];
    //     fprintf(fbalasan, "%d\n", k.id);
    //     fprintf(fbalasan, "%s\n", k.text);
    //     fprintf(fbalasan, "%d\n", k.like);
    //     fprintf(fbalasan, "%s\n", listUser.contents[k.idUser].name);
    //     TulisDATETIMEFile(k.datetime, fbalasan);
    //     fprintf(fbalasan, "\n");
    // }

    fclose(fbalasan);
}



boolean load(boolean isInitiate)
{
    if (currentUser != NULL)
    {
        printf("Anda harus keluar terlebih dahulu untuk melakukan pemuatan.\n\n");
        return false;
    }
    if (!isInitiate) {
        clearDatabase();
        initDatabase();
    }
    boolean isInputValid = false;

    while (!isInputValid)
    {
        if (!isInitiate)
            printf("Masukkan nama folder yang hendak dimuat: \n");
        else
            printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
        STARTTEXT();
        printf("%s\n", currentText.TabString);

        if (currentText.Length == 0)
        {
            printf("Nama folder tidak boleh kosong!!\n\n");
            continue;
        }

        if (isTextAllBlank(currentText))
        {
            printf("Nama folder tidak boleh hanya berisi spasi!!\n");
            continue;
        }

        isInputValid = true;
    }

    if (currentUser != NULL)
    {
        printf("Anda harus keluar terlebih dahulu!!\n");
        return false;
    }

    Text w = appendText(charArrToText("config/"), currentText);

    if (isDirectoryExists(w.TabString) == 0)
    {
        printf("Tidak ada folder yang dimaksud!\n");
        return false;
    }
    if (!isInitiate)
    {
        printf("Anda akan melakukan pemuatan dari %s.\n\n", currentText.TabString);
        printf("Mohon tunggu...\n");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n\n");
    }

    loadUser(w);
    loadKicauan(w);
    loadDraft(w);
    loadUtas(w);
    loadBalasan(w);
    if (!isInitiate)
    {
        printf("Pemuatan selesai!\n\n");
    }
    else
    {
        printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n\n");
    }

    return true;

}

void loadUtas(Text rootPath)
{
    Text wUtas = appendText(rootPath, charArrToText("/utas.config"));

    FILE *futas = fopen(wUtas.TabString, "r");
    STARTREADFILE(futas);

    int manyKicauWithUtas = wordToInt(stringToWord(currentLine.TabWord));
    NEXTLINE();

    int i;
    for (i = 0; i < manyKicauWithUtas; i++)
    {
        int idKicau = wordToInt(stringToWord(currentLine.TabWord));
        int index = indexOfListDinKicauById(listKicauan, idKicau);

        listKicauan.buffer[index].idUtas = listUtas.idCount;
        NEXTLINE();

        Utas u;
        CreateUtas(&u);
        ElUtas elutas1;
        int l = 0;
        while (listKicauan.buffer[index].text[l] != '\0')
        {
            elutas1.text[l] = listKicauan.buffer[index].text[l];
            l++;
        }

        elutas1.text[l] = '\0';
        elutas1.id = listUtas.idCount;
        elutas1.idKicau = idKicau;
        elutas1.datetime = listKicauan.buffer[index].datetime;
        elutas1.idUser = listKicauan.buffer[index].idUser;
        insertLastUtas(&u, elutas1);

        int manyUtas = wordToInt(stringToWord(currentLine.TabWord));
        NEXTLINE();
        int j;

        for (j = 0; j < manyUtas; j++)
        {
            ElUtas elutas;
            int k = 0;
            while (currentLine.TabWord[k] != '\0')
            {
                elutas.text[k] = currentLine.TabWord[k];
                k++;
            }

            elutas.text[k] = '\0';
            elutas.id = listUtas.idCount;
            elutas.idKicau = idKicau;
            NEXTLINE();
            int idUser = listUserIndexOfWithName(listUser, currentLine.TabWord);

            elutas.idUser = idUser;

            NEXTLINE();

            char tanggal[3];
            char bulan[3];
            char tahun[5];
            char jam[3];
            char menit[3];
            char detik[3];

            tanggal[0] = currentLine.TabWord[0];
            tanggal[1] = currentLine.TabWord[1];
            tanggal[2] = '\0';

            bulan[0] = currentLine.TabWord[3];
            bulan[1] = currentLine.TabWord[4];
            bulan[2] = '\0';

            tahun[0] = currentLine.TabWord[6];
            tahun[1] = currentLine.TabWord[7];
            tahun[2] = currentLine.TabWord[8];
            tahun[3] = currentLine.TabWord[9];
            tahun[4] = '\0';

            jam[0] = currentLine.TabWord[11];
            jam[1] = currentLine.TabWord[12];
            jam[2] = '\0';

            menit[0] = currentLine.TabWord[14];
            menit[1] = currentLine.TabWord[15];
            menit[2] = '\0';

            detik[0] = currentLine.TabWord[17];
            detik[1] = currentLine.TabWord[18];
            detik[2] = '\0';

            int d = wordToInt(stringToWord(tanggal));
            int m = wordToInt(stringToWord(bulan));
            int y = wordToInt(stringToWord(tahun));
            int h = wordToInt(stringToWord(jam));
            int mi = wordToInt(stringToWord(menit));
            int s = wordToInt(stringToWord(detik));

            DATETIME datetime;
            CreateDATETIME(&datetime, d, m, y, h, mi, s);
            elutas.datetime = datetime;

            insertLastUtas(&u, elutas);
            NEXTLINE();
        }

        insertLastListDinUtas(&listUtas, u);
        listUtas.idCount++;
    }
}

void loadDraft(Text rootPath)
{
    Text wDraft = appendText(rootPath, charArrToText("/draft.config"));

    FILE *fdraft = fopen(wDraft.TabString, "r");
    STARTREADFILE(fdraft);

    int manyUser = wordToInt(stringToWord(currentLine.TabWord));
    NEXTLINE();

    int i;

    for (i = 0; i < manyUser; i++)
    {
        int j;
        int s;
        for (j = currentLine.Length - 1; j >= 0; j--)
        {
            if (currentLine.TabWord[j] < '0' || currentLine.TabWord[j] > '9')
            {
                s = j + 1;
                break;
            }
        }
        char name[21];
        for (j = 0; j < s - 1; j++)
        {
            name[j] = currentLine.TabWord[j];
        }
        name[j] = '\0';
        char num[200];
        int a = 0;
        for (j = s; j < currentLine.Length; j++)
        {
            num[a++] = currentLine.TabWord[j];
        }
        num[j] = '\0';

        int manyDraft = wordToInt(stringToWord(num));
        int idUser = listUserIndexOfWithName(listUser, name);
        int k;
        NEXTLINE();
        StackDraft sd;
        CreateStackDraft(&sd);
        for (k = 0; k < manyDraft; k++)
        {
            Draft d;
            CreateDraft(&d);
            int r = 0;
            while (currentLine.TabWord[r] != '\0')
            {
                d.text[r] = currentLine.TabWord[r];
                r++;
            }

            d.text[r] = '\0';
            NEXTLINE();
            char tanggal[3];
            char bulan[3];
            char tahun[5];
            char jam[3];
            char menit[3];
            char detik[3];

            tanggal[0] = currentLine.TabWord[0];
            tanggal[1] = currentLine.TabWord[1];
            tanggal[2] = '\0';

            bulan[0] = currentLine.TabWord[3];
            bulan[1] = currentLine.TabWord[4];
            bulan[2] = '\0';

            tahun[0] = currentLine.TabWord[6];
            tahun[1] = currentLine.TabWord[7];
            tahun[2] = currentLine.TabWord[8];
            tahun[3] = currentLine.TabWord[9];
            tahun[4] = '\0';

            jam[0] = currentLine.TabWord[11];
            jam[1] = currentLine.TabWord[12];
            jam[2] = '\0';

            menit[0] = currentLine.TabWord[14];
            menit[1] = currentLine.TabWord[15];
            menit[2] = '\0';

            detik[0] = currentLine.TabWord[17];
            detik[1] = currentLine.TabWord[18];
            detik[2] = '\0';

            int da = wordToInt(stringToWord(tanggal));
            int m = wordToInt(stringToWord(bulan));
            int y = wordToInt(stringToWord(tahun));
            int h = wordToInt(stringToWord(jam));
            int mi = wordToInt(stringToWord(menit));
            int s = wordToInt(stringToWord(detik));

            DATETIME datetime;
            CreateDATETIME(&datetime, da, m, y, h, mi, s);
            d.datetime = datetime;
            pushStackDraft(&sd, d);
            NEXTLINE();
        }

        while (!isEmptyStackDraft(sd))
        {
            Draft temp;
            popStackDraft(&sd, &temp);
            pushStackDraft(&listUser.contents[idUser].stackDraft, temp);
        }
    }

    fclose(fdraft);
}

void loadKicauan(Text rootPath)
{
    Text wKicau = appendText(rootPath, charArrToText("/kicauan.config"));

    FILE *fkicau = fopen(wKicau.TabString, "r");
    STARTREADFILE(fkicau);

    int manyKicau = wordToInt(stringToWord(currentLine.TabWord));
    NEXTLINE();
    int i;
    for (i = 0; i < manyKicau; i++)
    {
        Kicauan kicau;
        CreateKicauan(&kicau);

        kicau.id = wordToInt(stringToWord(currentLine.TabWord));
        NEXTLINE();

        int j = 0;
        while (currentLine.TabWord[j] != '\0')
        {
            kicau.text[j] = currentLine.TabWord[j];
            j++;
        }

        kicau.text[j] = '\0';

        NEXTLINE();
        kicau.like = wordToInt(stringToWord(currentLine.TabWord));

        NEXTLINE();

        kicau.idUser = listUserIndexOfWithName(listUser, currentLine.TabWord);

        NEXTLINE();
        char tanggal[3];
        char bulan[3];
        char tahun[5];
        char jam[3];
        char menit[3];
        char detik[3];

        tanggal[0] = currentLine.TabWord[0];
        tanggal[1] = currentLine.TabWord[1];
        tanggal[2] = '\0';

        bulan[0] = currentLine.TabWord[3];
        bulan[1] = currentLine.TabWord[4];
        bulan[2] = '\0';

        tahun[0] = currentLine.TabWord[6];
        tahun[1] = currentLine.TabWord[7];
        tahun[2] = currentLine.TabWord[8];
        tahun[3] = currentLine.TabWord[9];
        tahun[4] = '\0';

        jam[0] = currentLine.TabWord[11];
        jam[1] = currentLine.TabWord[12];
        jam[2] = '\0';

        menit[0] = currentLine.TabWord[14];
        menit[1] = currentLine.TabWord[15];
        menit[2] = '\0';

        detik[0] = currentLine.TabWord[17];
        detik[1] = currentLine.TabWord[18];
        detik[2] = '\0';

        int d = wordToInt(stringToWord(tanggal));
        int m = wordToInt(stringToWord(bulan));
        int y = wordToInt(stringToWord(tahun));
        int h = wordToInt(stringToWord(jam));
        int mi = wordToInt(stringToWord(menit));
        int s = wordToInt(stringToWord(detik));

        DATETIME datetime;
        CreateDATETIME(&datetime, d, m, y, h, mi, s);
        kicau.datetime = datetime;

        insertLastListDinKicau(&listKicauan, kicau);
        NEXTLINE();
    }

    listKicauan.idCount = manyKicau;

    sortListDinKicauByDateTime(&listKicauan, false);
    fclose(fkicau);
}

void loadUser(Text rootPath)
{
    Text wUser = appendText(rootPath, charArrToText("/pengguna.config"));

    FILE *fuser = fopen(wUser.TabString, "r");

    STARTREADFILE(fuser);

    int manyUser = wordToInt(stringToWord(currentLine.TabWord));

    NEXTLINE();

    int i;
    for (i = 0; i < manyUser; i++)
    {
        User temp;
        CreateUser(&temp);
        temp.id = i;
        setUserName(&temp, currentLine.TabWord);

        NEXTLINE();
        setUserPassword(&temp, currentLine.TabWord);

        NEXTLINE();
        if (currentLine.Length != 0)
            setUserBio(&temp, currentLine.TabWord);

        NEXTLINEDIN();
        StringDin s;
        CreateListLinierChar(&s.TabString);
        AddrChar curr = currentLineDin.TabString;
        while (curr != NULL)
        {
            insertLastListLinierChar(&s.TabString, curr->info);
            curr = curr->next;
        }

        deallocateCurrentLineDin();
        if (s.TabString != NULL)
            setUserPhoneNumber(&temp, s);
        deleteAllListLinierChar(&s.TabString);

        NEXTLINE();
        if (currentLine.Length != 0)
            setUserWeton(&temp, currentLine.TabWord);

        NEXTLINE();
        Word kata = stringToWord(currentLine.TabWord);
        if (isWordEqual(kata, stringToWord("Privat")))
        {
            temp.isPublic = false;
        }
        else
        {
            temp.isPublic = true;
        }

        NEXTLINE();
        if (currentLine.Length == 0)
        {
            temp.profilePicture.isSetup = false;

            NEXTLINE();
            NEXTLINE();
            NEXTLINE();
            NEXTLINE();
            NEXTLINE();
        }
        else
        {
            int j, k;
            int rColor = 0;
            int rSymbol = 0;

            for (k = 0; k < 5; k++)
            {
                rColor = 0;
                rSymbol = 0;
                for (j = 0; j < currentLine.Length; j++)
                {
                    if (currentLine.TabWord[j] == ' ')
                    {
                        continue;
                    }
                    else if (currentLine.TabWord[j] == 'R' || currentLine.TabWord[j] == 'G' || currentLine.TabWord[j] == 'B')
                    {
                        temp.profilePicture.color.mem[rColor++][k] = currentLine.TabWord[j];
                    }
                    else
                    {
                        temp.profilePicture.symbol.mem[rSymbol++][k] = currentLine.TabWord[j];
                    }
                }

                NEXTLINE();
            }
            temp.profilePicture.isSetup = true;
        }

        listUserInsertLast(&listUser, temp);
    }

    int x, y;
    int t = 0;
    for (x = 0; x < manyUser; x++)
    {
        t = 0;
        for (y = 0; y < currentLine.Length; y++)
        {
            if (currentLine.TabWord[y] == ' ')
            {
                continue;
            }
            else
            {
                graphFriendship.matrix.mem[t++][x] = currentLine.TabWord[y] - '0';
            }
        }
        NEXTLINE();
    }

    for (x = 0; x < manyUser; x++)
    {
        int count = countGraphFriendshipRelation(graphFriendship, x);
        listUser.contents[x].manyFriend = count;
    }

    int manyFriendReq = wordToInt(stringToWord(currentLine.TabWord));
    NEXTLINE();

    int a;
    for (a = 0; a < manyFriendReq; a++)
    {
        int from = currentLine.TabWord[0] - '0';
        int to = currentLine.TabWord[2] - '0';
        int manyFriend = currentLine.TabWord[4] - '0';

        addGraphFriendshipPending(&graphFriendship, from, to);
        FriendReq fR;

        fR.idUser = from;
        fR.manyFriend = manyFriend;
        int b = 0;

        while (listUser.contents[from].name[b] != '\0')
        {
            fR.userName[b] = listUser.contents[from].name[b];
            b++;
        }
        fR.userName[b] = '\0';
        EnqueuePrioQueueFR(&listUser.contents[to].friendReq, fR);
        NEXTLINE();
    }
    fclose(fuser);
}

void loadBalasan(Text rootPath){
    Text wBalasan = appendText(rootPath, charArrToText("/balasan.config"));

    FILE *fuser = fopen(wBalasan.TabString, "r");

    STARTREADFILE(fuser);
    int manyBalasan = wordToInt(stringToWord(currentLine.TabWord));

    int i;
    NEXTLINE();
    for(i = 0; i < manyBalasan; i++){
        int IdKicau = wordToInt(stringToWord(currentLine.TabWord));
        int indexKicau = indexOfListDinKicauById(listKicauan, IdKicau);
        NEXTLINE();
        int manyBalasanKicau = wordToInt(stringToWord(currentLine.TabWord));
        int j;
        NEXTLINE();
        int maxId = 0;
        for(j = 0; j < manyBalasanKicau; j++){

            char id1[200];
            char id2[200];
            char content[281];
            char author[281];
            
            int k = 0;
            int idOfId = 0;
            boolean pastWhitespace = false;
            while(currentLine.TabWord[k] != '\0'){
                if (currentLine.TabWord[k] == ' '){
                    id1[idOfId] = '\0';
                    idOfId = 0;
                    pastWhitespace = true;
                }
                else{
                    if (pastWhitespace){
                        id2[idOfId] = currentLine.TabWord[k];
                    }
                    else{
                        id1[idOfId] = currentLine.TabWord[k];
                    }
                    idOfId++;
                }
                k++;
            }
            id2[idOfId] = '\0';

            NEXTLINE();
            k = 0;
            while (currentLine.TabWord[k] != '\0')
            {
                content[k] = currentLine.TabWord[k];
                k++;
            }
            content[k] = '\0';

            NEXTLINE();
            k = 0;
            while(currentLine.TabWord[k] != '\0'){
                author[k] = currentLine.TabWord[k];
                k++;
            }
            author[k] = '\0';

            NEXTLINE();
            char wDate[3];
            char wMonth[3];
            char wYear[5];
            char wHour[3];
            char wMinute[3];
            char wSecond[3];

            wDate[0] = currentLine.TabWord[0];
            wDate[1] = currentLine.TabWord[1];
            wDate[2] = '\0';

            wMonth[0] = currentLine.TabWord[3];
            wMonth[1] = currentLine.TabWord[4];
            wMonth[2] = '\0';

            wYear[0] = currentLine.TabWord[6];
            wYear[1] = currentLine.TabWord[7];
            wYear[2] = currentLine.TabWord[8];
            wYear[3] = currentLine.TabWord[9];
            wYear[4] = '\0';

            wHour[0] = currentLine.TabWord[11];
            wHour[1] = currentLine.TabWord[12];
            wHour[2] = '\0';

            wMinute[0] = currentLine.TabWord[14];
            wMinute[1] = currentLine.TabWord[15];
            wMinute[2] = '\0';

            wSecond[0] = currentLine.TabWord[17];
            wSecond[1] = currentLine.TabWord[18];
            wSecond[2] = '\0';

            Text nodeContent = charArrToText(content);
            Text nodeAuthor = charArrToText(author);
            int nodeId = wordToInt(stringToWord(id2));
            int idAddedTo = wordToInt(stringToWord(id1));

            int Date = wordToInt(stringToWord(wDate));
            int Month = wordToInt(stringToWord(wMonth));
            int Year = wordToInt(stringToWord(wYear));
            int Hour = wordToInt(stringToWord(wHour));
            int Minute = wordToInt(stringToWord(wMinute));
            int Second = wordToInt(stringToWord(wSecond));

            DATETIME nodeDatetime;
            CreateDATETIME(&nodeDatetime, Date, Month, Year, Hour, Minute, Second);

            int idAuthor = listUserIndexOfWithName(listUser, nodeAuthor.TabString);

            NodeBalasanAddress balasan;
            if (idAddedTo == -1){idAddedTo = 0;}
            balasan = newNodeBalasan(nodeId, 
            nodeContent, idAuthor, getNodeInTreeById(listKicauan.buffer[indexKicau].balasan, idAddedTo));
            NODEBALASAN_TIME(balasan) = nodeDatetime;
            addNodeToMap(&TREE_HMP(listKicauan.buffer[indexKicau].balasan), balasan);
            addChildren(getNodeInTreeById(listKicauan.buffer[indexKicau].balasan, idAddedTo), balasan);

            maxId = nodeId > maxId ? nodeId : maxId;

            NEXTLINE();
        }
        TREE_NEXTID(listKicauan.buffer[indexKicau].balasan) = maxId + 1; 
    }
}