#include "stringdinmachine.h"

boolean EndStringDin;
StringDin currentStringDin;

void STARTSTRINGDIN()
{
    deleteAllListLinierChar(&(currentStringDin.TabString));
    START();
    IgnoreNewLineStringDin();
    if (currentChar == MARK)
    {
        EndStringDin = true;
    }
    else
    {
        EndStringDin = false;
        while (!(currentChar == MARK))
        {
            insertLastListLinierChar(&(currentStringDin.TabString), currentChar);
            ADV();
        }
    }
}

boolean isStringDinAllBlank(StringDin str)
{
    AddrChar curr = str.TabString;
    while (curr != NULL)
    {
        if (curr->info != ' ')
            return false;
        curr = curr->next;
    }

    return true;
}

void printStringDin(StringDin str)
{
    AddrChar curr = str.TabString;
    while (curr != NULL)
    {
        printf("%c", curr->info);
        curr = curr->next;
    }
}

void IgnoreNewLineStringDin()
{
    while (currentChar == '\n' || currentChar == '\r')
    {
        ADV();
    }
}

boolean isStringDinAllNumber(StringDin str){
    AddrChar curr = str.TabString;
    while (curr != NULL)
    {
        if (curr->info < '0' || curr->info > '9' || curr->info == ' ') return false;
        curr = curr->next;
    }

    return true;
}