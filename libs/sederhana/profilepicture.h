/* ********** Definisi TYPE Matrix dengan Index dan elemen integer ********** */

#ifndef MATRIXPICTURE_H
#define MATRIXPICTURE_H

#include "../matrix/matrixchar.h"

typedef struct
{
   MatrixChar color;
   MatrixChar symbol;
   boolean isSetup;
} ProfilePicture;

void createMatrixPicture(ProfilePicture *m);

void readMatrixPicture(ProfilePicture *m);

void displayMatrixPicture(ProfilePicture m);


#endif