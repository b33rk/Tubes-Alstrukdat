#ifndef USER_H
#define USER_H

#include "boolean.h"
#include "machine/wordmachine.h"
#include "profilepicture.h"
#include "machine/stringdinmachine.h"

typedef struct
{
    int id;
    char name[21];
    char password[21];
    char bio[136];
    char weton[7];
    StringDin phoneNumber;
    boolean isPublic;
    ProfilePicture profilePicture;
} User;

void CreateUser(User *u);

void setUserName(User* user, char* name);

void setUserPassword(User* user, char* pass);

void setUserBio(User* user, char* bio);

void setUserWeton(User* user, char* weton);

void setUserPhoneNumber(User* user, StringDin phoneNumber);

void printUser(User user);

#endif