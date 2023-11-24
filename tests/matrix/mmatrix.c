#include <stdio.h>
#include "../../libs/matrix/matrixchar.h"

int main()
{
    MatrixChar matriks;
    int type;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        readMatrixChar(&matriks, 5, 5);
        displayMatrixChar(matriks);
        break;
    }

    return 0;
}