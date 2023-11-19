#include "database.h"

ListUser listUser;
User *currentUser;
GraphFriendship graphFriendship;
ListDinKicau listKicauan;

void initDatabase()
{
    CreateListUser(&listUser);
    currentUser = NULL;
    CreateGraphFriendship(&graphFriendship);
    CreateListDinKicau(&listKicauan, 10);

    //hanya untuk tes
    User user, user2, user3, user4;
    CreateUser(&user);
    CreateUser(&user2);
    CreateUser(&user3);
    CreateUser(&user4);

    setUserName(&user, "Bob");
    setUserName(&user2, "Carol");
    setUserName(&user3, "Dika");
    setUserName(&user4, "Adit");

    setUserPassword(&user, "Bob");
    setUserPassword(&user2, "Carol");
    setUserPassword(&user3, "Dika");
    setUserPassword(&user4, "Adit");


    user.id = 0;
    user2.id = 1;
    user3.id = 2;
    user4.id = 3;

    user.manyFriend++;
    user.manyFriend++;
    user2.manyFriend++;
    user3.manyFriend++;

    listUserInsertLast(&listUser, user);
    listUserInsertLast(&listUser, user2);
    listUserInsertLast(&listUser, user3);
    listUserInsertLast(&listUser, user4);

    addGraphFriendshipRelation(&graphFriendship, 0, 1);
    addGraphFriendshipRelation(&graphFriendship, 0, 2);
}