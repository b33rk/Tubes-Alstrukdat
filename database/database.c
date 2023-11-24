#include "database.h"

Disjointsetunion dsu;
ListUser listUser;
User *currentUser;
GraphFriendship graphFriendship;
ListDinKicau listKicauan;
ListDinUtas listUtas;


void initDatabase()
{
    initDSU(&dsu);
    CreateListUser(&listUser);
    currentUser = NULL;
    CreateGraphFriendship(&graphFriendship);
    CreateListDinKicau(&listKicauan, 3);
    CreateListDinUtas(&listUtas, 1);

}

void clearDatabase(){
    dealocateListDinKicau(&listKicauan);
    dealocateListDinUtas(&listUtas);
}