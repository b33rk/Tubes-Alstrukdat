/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charfilemachine.h"

char currentFileChar;
boolean EOPFile;

static FILE *pitaFile;
static int retvalFile;

void STARTFILE(FILE *file)
{
       /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
          Karakter pertama yang ada pada pita posisinya adalah pada jendela.
          I.S. : sembarang
          F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARK maka EOP akan padam (false).
                 Jika currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       pitaFile = file;
       ADVFILE();
}

// void STARTSTRING(char *s)
// {
//        pita = s;
//        ADV();
// }

void ADVFILE()
{
       /* Pita dimajukan satu karakter.
          I.S. : Karakter pada jendela =
                 currentChar, currentChar != MARK
          F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
                 currentChar mungkin = MARK.
                       Jika  currentChar = MARK maka EOP akan menyala (true) */

       /* Algoritma */
       retvalFile = fscanf(pitaFile, "%c", &currentFileChar);
       EOPFile = (currentFileChar == '\n' || currentFileChar == '\r');
}