#ifndef USER_H
#define USER_H

#include "boolean.h"
#include "machine/wordmachine.h"

typedef struct
{
    int id;
    char name[21];
    char password[21];
    char bio[136];
    Word weton;
    Word phoneNumber;
    boolean isPublic;

} User;

void CreateUser(User *u);

void setUserName(User* user, char* name);

void setUserPassword(User* user, char* pass);
void setUserBio(User* user, char* bio);

void printUser(User user);

#endif