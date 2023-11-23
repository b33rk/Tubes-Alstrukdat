#include "user.h"
#include "../../database/database.h"


void CreateUser(User *u)
{
    u->id = -1;
    setUserName(u, "");
    setUserPassword(u, "");
    setUserBio(u, "");
    setUserWeton(u, "");
    CreateListLinierChar(&(u->phoneNumber.TabString));
    createMatrixPicture(&(u->profilePicture));
    u->manyFriend = 0;
    CreatePrioQueueFR(&(u->friendReq), 20);
    u->isPublic = true;
    CreateStackDraft(&u->stackDraft);
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

void setUserWeton(User *user, char *weton)
{
    int i = 0;
    while (weton[i] != '\0')
    {
        user->weton[i] = weton[i];
        i++;
    }
    user->weton[i] = '\0';
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

void displayUserProfile(User user, boolean withProfilePicture)
{
    printf("| Nama: %s\n", user.name);
    printf("| Bio Akun: %s\n", user.bio);
    printf("| No HP: ");
    printStringDin(user.phoneNumber);
    printf("\n");
    printf("| Weton: %s\n\n", user.weton);

    if (withProfilePicture)
    {
        printf("Foto profil akun %s\n", user.name);

        displayMatrixPicture(user.profilePicture);
    }
}

void setUserPhoneNumber(User *user, StringDin phoneNumber)
{
    deleteAllListLinierChar(&(user->phoneNumber.TabString));

    AddrChar curr = phoneNumber.TabString;
    while (curr != NULL)
    {
        insertLastListLinierChar(&(user->phoneNumber.TabString), curr->info);
        curr = curr->next;
    }
}

void reSortPrioQueueFR(User *user)
{
    FriendReq temp;
    PrioQueueFriendReq newQ;
    CreatePrioQueueFR(&newQ, user->friendReq.MaxEl);

    while (!IsPrioQueueFREmpty(user->friendReq))
    {
        DequeuePrioQueueFR(&user->friendReq, &temp);
        temp.manyFriend = listUser.contents[temp.idUser].manyFriend;
        EnqueuePrioQueueFR(&newQ, temp);
    }

    DeAlokasiPrioQueueFR(&user->friendReq);
    CreatePrioQueueFR(&user->friendReq, newQ.MaxEl);

    while (!IsPrioQueueFREmpty(newQ))
    {
        DequeuePrioQueueFR(&newQ, &temp);
        EnqueuePrioQueueFR(&user->friendReq, temp);
    }

    DeAlokasiPrioQueueFR(&newQ);
}