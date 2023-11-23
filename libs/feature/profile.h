#ifndef PROFILE_H
#define PROFILE_H

#include "../boolean.h"
#include <stdio.h>
#include "../list/listuser.h"
#include "../machine/wordmachine.h"
#include "../../database/database.h"
#include "../sederhana/profilepicture.h"
#include "../machine/stringdinmachine.h"

void seeProfile(Word name);

void changeAccountType();

void changeProfilePicture();

void changeProfile();

#endif