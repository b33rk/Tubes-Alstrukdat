#ifndef KICAUAN_H
#define KICAUAN_H

#include "../boolean.h"
#include "../machine/textmachine.h"
#include "../list/listdinkicau.h"
#include "../../database/database.h"

void publishKicauan();
void displayKicauan();
void likeKicauan(int idKicau);
void updateKicauan(int idKicau);
void getCurrentDatetime(char *datetime);

#endif