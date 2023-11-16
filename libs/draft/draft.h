#ifndef DRAFT_H
#define DRAFT_H

#include "../boolean.h"
#include <stdio.h>
#include <time.h>

#define NIL NULL

typedef struct node* Address;

typedef struct { 
//   kicauan k; /* tabel penyimpan elemen */
  int datetime;  /* alamat TOP: elemen puncak */
} Draft;

typedef Draft ElType;
typedef struct node { 
    Draft info;
    Address next;
} Node; 

/* Type stack dengan ciri Top: */
typedef struct { 
    Address addrTop; /* alamat Top: elemen puncak */
} StackDraft;

/* Selektor */
#define     NEXT(p) (p)->next
#define     INFO(p) (p)->info
#define ADDR_TOP(s) (s).addrTop
#define      TOP(s) (s).addrTop->info 

Address newNode(ElType x);

boolean isEmptyStack(StackDraft s);

int lengthStack(StackDraft s);

void CreateStack(StackDraft *s);

void DisplayStack(StackDraft s);

void pushStack(StackDraft *s, ElType x);

void popStack(StackDraft *s);

#endif