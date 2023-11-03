#ifndef DATABASE_H
#define DATABASE_H

#include "../libs/list/listuser.h"

extern ListUser listUser;

extern User* currentUser;

void initDatabase();

#endif