#include "database.h"

ListUser listUser;
User currentUser;

void initDatabase(){
    CreateListUser(&listUser);
    CreateUser(&currentUser);
}