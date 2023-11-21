#ifndef UTAS_H
#define UTAS_H

#include "../boolean.h"
#include "../machine/textmachine.h"
#include "../list/listdinkicau.h"
#include "../list/listdinutas.h"
#include "../../database/database.h"
#include "../graph/graphfriendship.h"

void createNewUtas(int IDKicau);
void sambungUtas(int IDUtas, int index);
void hapusUtas(int IDUtas, int index);
void cetakUtas(int IDUtas);

#endif