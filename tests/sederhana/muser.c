#include <stdio.h>
#include "../../libs/sederhana/user.h"

int main()
{
    User user;
    int type;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        CreateUser(&user);
        setUserBio(&user, "bombombmo");
        printf("%s\n", user.bio);
        break;
    case 2:
        CreateUser(&user);
        setUserName(&user, "Bob");
        printf("%s\n", user.name);
        break;
    case 3:
        CreateUser(&user);
        setUserPassword(&user, "Bobby");
        printf("%s\n", user.password);
        break;
    case 4:
        CreateUser(&user);
        setUserWeton(&user, "Wadidaw");
        printf("%s\n", user.weton);
        break;
    }

    return 0;
}