#include "database.h"

ListUser listUser;
User* currentUser;

void initDatabase(){
    CreateListUser(&listUser);
    currentUser = NULL;
}