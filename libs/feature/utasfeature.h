#ifndef UTASFEATURE_H
#define UTASFEATURE_H

#include "../boolean.h"
#include <stdio.h>
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"
#include "../../database/database.h"
#include "../sederhana/datetime.h"
#include "../graph/graphfriendship.h"

void createNewUtas(int IDKicau);
void sambungUtas(int IDUtas, int index);
void hapusUtas(int IDUtas, int index);
void cetakUtas(int IDUtas);


#endif