#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "kicauan.h"
#include "textmachine.h"

void getCurrentDatetime(char *datetime);

void publishKicauan(char *author, char *text) {
    STARTTEXT();
    if (EndText) {
        printf("Kicauan tidak boleh hanya berisi spasi!\n");
        return;
    }
    if (kicauanCount < MAX_KICAUAN) {
        kicauans[kicauanCount].id = kicauanCount + 1;
        strcpy(kicauans[kicauanCount].author, author);
        if (currentText.Length > MAX_CHARACTERS) {
            strncpy(kicauans[kicauanCount].text, currentText.TabString, MAX_CHARACTERS);
            kicauans[kicauanCount].text[MAX_CHARACTERS] = '\0';
        }
        else {
            strcpy(kicauans[kicauanCount].text, currentText.TabString);
        }
        kicauans[kicauanCount].like = 0;
        time(&kicauans[kicauanCount].datetime);
        printf("Selamat! Kicauan telah diterbitkan!\n");
        printf("Detil kicauan:\n");
        printf("| ID = %d\n", kicauans[kicauanCount].id);
        printf("| %s\n", kicauans[kicauanCount].author);
        char datetimeStr[20];
        getCurrentDatetime(datetimeStr);
        printf("| %s\n", datetimeStr);
        printf("| %s\n", kicauans[kicauanCount].text);
        printf("| Disukai: %d\n", kicauans[kicauanCount].like);
        kicauanCount++;
    }
}

void displayKicauan() {
    printf(">> Kicauan:\n");
    for (int i = kicauanCount - 1; i >= 0; i--) {
        printf("| ID = %d\n", kicauans[i].id);
        printf("| %s\n", kicauans[i].author);
        char datetimeStr[20];
        strftime(datetimeStr, 20, "%d/%m/%Y %H:%M:%S", localtime(&kicauans[i].datetime));
        printf("| %s\n", datetimeStr);
        printf("| %s\n", kicauans[i].text);
        printf("| Disukai: %d\n\n", kicauans[i].like);
    }
}

void likeKicauan(int IDKicau) {
    int index = -1;
    for (int i = 0; i < kicauanCount; i++) {
        if (kicauans[i].id == IDKicau) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        if (index == 2) {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya\n");
        }
        else {
            kicauans[index].like++;
            printf("Selamat! Kicauan telah disukai!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d\n", kicauans[index].id);
            printf("| %s\n", kicauans[index].author);
            char datetimeStr[20];
            strftime(datetimeStr, 20, "%d/%m/%Y %H:%M:%S", localtime(&kicauans[index].datetime));
            printf("| %s\n", datetimeStr);
            printf("| %s\n", kicauans[index].text);
            printf("| Disukai: %d\n", kicauans[index].like);
        }
    }
    else {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", IDKicau);
    }
}

void updateKicauan(int id, char *newText) {
    int index = -1;
    for (int i = 0; i < kicauanCount; i++) {
        if (kicauans[i].id == id) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        if (strcmp(kicauans[index].author, currentUser) == 0) {
            strncpy(kicauans[index].text, newText, MAX_CHARACTERS);
            kicauans[index].text[MAX_CHARACTERS] = '\0';
            printf("Selamat! Kicauan telah diterbitkan!\n");
            printf("Detil kicauan:\n");
            printf("| ID = %d\n", kicauans[index].id);
            printf("| %s\n", kicauans[index].author);
            char datetimeStr[20];
            strftime(datetimeStr, 20, "%d/%m/%Y %H:%M:%S", localtime(&kicauans[index].datetime));
            printf("| %s\n", datetimeStr);
            printf("| %s\n", kicauans[index].text);
            printf("| Disukai: %d\n", kicauans[index].like);
        }
        else
        {
            printf("Kicauan dengan ID = %d bukan milikmu!\n", id);
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d\n", id);
    }
}