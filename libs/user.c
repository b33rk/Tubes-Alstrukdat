#include "user.h"
#include "../database/database.h"

void CreateUser(User *u)
{
    (*u).id = -1;
    setUserName(u, "");
    setUserPassword(u, "");
    setUserBio(u, "");
}

void setUserName(User *user, char *name)
{
    char curr = name[0];
    int i = 0;
    while (curr != '\0')
    {
        (*user).name[i++] = curr;
        curr = name[i];
    }
    (*user).name[i] = '\0';
}

void setUserBio(User *user, char *bio)
{
    char curr = bio[0];
    int i = 0;
    while (curr != '\0')
    {
        (*user).bio[i++] = curr;
        curr = bio[i];
    }
    (*user).bio[i] = '\0';
}

void setUserPassword(User *user, char *pass)
{
    char curr = pass[0];
    int i = 0;
    while (curr != '\0')
    {
        (*user).password[i++] = curr;
        curr = pass[i];
    }
    (*user).password[i] = '\0';
}

void printUser(User user)
{
    printf("id: %d\n", user.id);
    printf("nama: %s\n", user.name);
    printf("pass: %s\n", user.password);
}