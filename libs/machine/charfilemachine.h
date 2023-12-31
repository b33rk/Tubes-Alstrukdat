/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef __CHAR_FILE_MACHINE_H__
#define __CHAR_FILE_MACHINE_H__

#include "../boolean.h"
#include <stdio.h>

/* State Mesin */
extern char currentFileChar;
extern boolean EOPFile;

void STARTFILE(FILE *file);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

// void STARTSTRING(char* s);

void ADVFILE();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

#endif