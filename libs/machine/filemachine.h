/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef _FILE_MACHINE_H__
#define _FILE_MACHINE_H__

#include "../boolean.h"
#include "charfilemachine.h"
#include <stdio.h>
#include "../list/listlinierchar.h"

/* State Mesin */
typedef struct
{
   char TabWord[300]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Line;
typedef struct
{
   ListLinierChar TabString; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
} LineDin;

/* State Mesin Word */
extern LineDin currentLineDin;
extern boolean EndFile;
extern Line currentLine;


void STARTREADFILE(FILE *file);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

// void STARTSTRING(char* s);

void NEXTLINE();
void NEXTLINEDIN();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void IgnoreNewLineFile();

void deallocateCurrentLineDin();

#endif