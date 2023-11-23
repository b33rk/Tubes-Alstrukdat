#include "profilepicture.h"

void createMatrixPicture(ProfilePicture *m)
{

    createMatrixChar(&(m->color), 5, 5);
    createMatrixChar(&(m->symbol), 5, 5);
    (*m).isSetup = false;
}

void readMatrixPicture(ProfilePicture *m)
{

    int i = 0;
    int j = 0;
    char color, symbol;

    START();
    while (currentChar != MARK)
    {
        while (currentChar == ' ' || currentChar == '\n'){
            ADV();
        }
        color = currentChar;
        m->color.mem[i][j] = color;
        ADV();
        while (currentChar == ' ' || currentChar == '\n'){
            ADV();
        }
        symbol = currentChar;
        m->symbol.mem[i][j] = symbol;
        i++;
        if (i == 5){
            j++;
            i = 0;
        }
        ADV();
    }

    m->isSetup = true;
}
void displayMatrixPicture(ProfilePicture m)
{

    int i, j;

    /*ALGORITMA*/
    if (m.isSetup)
    {

        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                char color = m.color.mem[i][j];
                if (color == 'R')
                {
                    print_red(m.symbol.mem[i][j]);
                }
                else if (color == 'G')
                {
                    print_green(m.symbol.mem[i][j]);
                }
                else if (color == 'B')
                {
                    print_blue(m.symbol.mem[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("\n");
    }
}
