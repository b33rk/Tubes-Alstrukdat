#ifndef DATABASE_H
#define DATABASE_H

#include "../libs/list/listuser.h"
#include"../libs/graph/graphfriendship.h"

extern ListUser listUser;

extern User* currentUser;

extern GraphFriendship graphFriendship;

void initDatabase();

#endif