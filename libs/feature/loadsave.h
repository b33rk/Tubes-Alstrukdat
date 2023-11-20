#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "../boolean.h"
#include "../../database/database.h"
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"
#include "../machine/filemachine.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#ifdef _WIN32
    #include <direct.h>
    #define mkdir(path, mode) _mkdir(path)
#else
    #include <sys/types.h>
#endif

int isDirectoryExists(const char *path);

void save();
void saveKicauan(Text rootPath);
void saveUser(Text rootPath);
void saveDraft(Text rootPath);

void load(boolean isInitiate);
void loadUser(Text rootPath);
void loadKicauan(Text rootPath);
void loadDraft(Text rootPath);



#endif