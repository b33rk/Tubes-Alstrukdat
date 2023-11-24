#ifndef DATABASE_H
#define DATABASE_H

#include "../libs/disjointsetunion/disjointsetunion.h"
#include "../libs/list/listuser.h"
#include "../libs/list/listdinkicau.h"
#include "../libs/list/listdinutas.h"
#include"../libs/graph/graphfriendship.h"

extern Disjointsetunion dsu;

extern ListUser listUser;

extern User* currentUser;

extern GraphFriendship graphFriendship;

extern ListDinKicau listKicauan;

extern ListDinUtas listUtas;

void initDatabase();

void clearDatabase();

#endif