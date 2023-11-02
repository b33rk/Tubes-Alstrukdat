/* File: wordmachine.h */
/* Definisi Mesin Word: Model Akuisisi Versi I */

#ifndef SENTENCEMACHINE_H
#define SENTENCEMACHINE_H

#include "../boolean.h"
#include "charmachine.h"
#include <stdio.h>

#define BLANK ' '
#define Nmax 280

typedef struct
{
   char TabString[280]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} String;

/* State Mesin Word */
extern boolean EndString;
extern String currentString;

void STARTSTRING();

boolean isAllBlank(String str);

boolean isStringEqual(String s1, String s2);

String charArrToString(char* c);

void printString(String str);

void IgnoreNewLine();


#endif