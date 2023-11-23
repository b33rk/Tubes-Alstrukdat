/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef SENTENCEMACHINEDIN_H
#define SENTENCEMACHINEDIN_H

#include "../boolean.h"
#include "charmachine.h"
#include "../list/listlinierchar.h"
#include <stdio.h>
#include <stdlib.h>

#define BLANK ' '

typedef struct
{
   ListLinierChar TabString; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
} StringDin;

/* State Mesin Word */
extern boolean EndStringDin;
extern StringDin currentStringDin;

void STARTSTRINGDIN();


boolean isStringDinAllBlank(StringDin str);

void printStringDin(StringDin str);

void IgnoreNewLineStringDin();

boolean isStringDinAllNumber(StringDin str);

void deallocateStringDin();



#endif