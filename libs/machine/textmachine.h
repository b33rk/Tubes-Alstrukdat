/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef SENTENCEMACHINE_H
#define SENTENCEMACHINE_H

#include "../boolean.h"
#include "charmachine.h"
#include <stdio.h>

#define BLANK ' '

typedef struct
{
   char TabString[281]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Text;

/* State Mesin Word */
extern boolean EndText;
extern Text currentText;

void STARTTEXT();

boolean isTextAllBlank(Text str);

boolean isTextEqual(Text s1, Text s2);

Text charArrToText(char* c);

Text appendText(Text t1, Text t2);

void printText(Text str);

void IgnoreNewLineText();

// void STARTTEXT2(char* s);



#endif