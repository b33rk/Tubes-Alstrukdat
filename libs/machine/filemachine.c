#include "filemachine.h"

boolean EndFile;
Line currentLine;
LineDin currentLineDin;


void STARTREADFILE(FILE *file)
{
    STARTFILE(file);
    NEXTLINE();
}

void NEXTLINEDIN()
{
    IgnoreNewLineFile();

    while (!(currentFileChar == '\n' || currentFileChar == '\r'))
    {
        insertLastListLinierChar(&(currentLineDin.TabString), currentFileChar);
        ADVFILE();
    }
}

void NEXTLINE()
{
    int length;

    /* ALGORITMA */
    length = 0;
    IgnoreNewLineFile();
    while (!(currentFileChar == '\n' || currentFileChar == '\r'))
    {
        if (length < 300)
        {
            currentLine.TabWord[length++] = currentFileChar;
        }
        ADVFILE();
    }

    currentLine.Length = length;
    currentLine.TabWord[length] = '\0';
}

void IgnoreNewLineFile()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentFileChar sembarang
       F.S. : currentFileChar ≠ BLANK atau currentFileChar = MARK */
    /* KAMUS */

    /* ALGORITMA */
    if (currentFileChar == '\r')
    {
        ADVFILE();
        ADVFILE();
    } else if (currentFileChar == '\n'){
        ADVFILE();
    }
}

void deallocateCurrentLineDin()
{
    deleteAllListLinierChar(&(currentLineDin.TabString));
    free(currentLineDin.TabString);
}