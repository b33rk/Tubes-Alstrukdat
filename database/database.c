#include "database.h"

ListUser listUser;
User *currentUser;
GraphFriendship graphFriendship;
ListDinKicau listKicauan;
ListDinUtas listUtas;


void initDatabase()
{
    CreateListUser(&listUser);
    currentUser = NULL;
    CreateGraphFriendship(&graphFriendship);
    CreateListDinKicau(&listKicauan, 3);
    CreateListDinUtas(&listUtas, 10);

}

void clearDatabase(){
    dealocateListDinKicau(&listKicauan);
    dealocateListDinUtas(&listUtas);
}