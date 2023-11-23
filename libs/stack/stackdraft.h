#ifndef STACKDRAFT_H
#define STACKDRAFT_H

#include "../boolean.h"
#include <stdio.h>
#include "../sederhana/datetime.h"

typedef struct nodeDraft *AddressDraft;

typedef struct
{
  //   kicauan k; /* tabel penyimpan elemen */
  char text[281];
  DATETIME datetime; /* alamat TOP: elemen puncak */
} Draft;

typedef struct nodeDraft
{
  Draft info;
  AddressDraft next;
} NodeDraft;

/* Type stack dengan ciri Top: */
typedef struct
{
  AddressDraft addrTop; /* alamat Top: elemen puncak */
} StackDraft;

/* Selektor */
#define NEXT(p) (p)->next
#define INFO(p) (p)->info
#define ADDR_TOP(s) (s).addrTop
#define TOP(s) (s).addrTop->info

void CreateDraft(Draft *draft);

AddressDraft newNodeDraft(Draft d);

boolean isEmptyStackDraft(StackDraft s);

int lengthStackDraft(StackDraft s);

void CreateStackDraft(StackDraft *s);

void DisplayStackDraft(StackDraft s);

void pushStackDraft(StackDraft *s, Draft d);

void popStackDraft(StackDraft *s, Draft *d);

#endif