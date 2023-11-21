#ifndef UTASFEATURE_H
#define UTASFEATURE_H

#include "../boolean.h"
#include <stdio.h>
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"
#include "../../database/database.h"
#include "../datetime.h"

void makeUtas(int idKicau);

void cetakUtas(int idUtas);

void sambungUtas(int idUtas, int index);
void hapusUtas(int idUtas, int index);

#endif