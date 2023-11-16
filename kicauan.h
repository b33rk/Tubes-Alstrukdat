#ifndef KICAUAN_H
#define KICAUAN_H

#include <time.h>

#define MAX_CHARACTERS 280
#define MAX_KICAUAN 1000

typedef struct
{
    int id;
    char author[50];
    char text[MAX_CHARACTERS];
    int like;
    time_t datetime;
} Kicauan;

Kicauan kicauans[MAX_KICAUAN];
int kicauanCount = 0;

void publishKicauan(char *author, char *text);
void displayKicauan();
void likeKicauan(int id);
void updateKicauan(int id, char *newText);
void getCurrentDatetime(char *datetime);

#endif