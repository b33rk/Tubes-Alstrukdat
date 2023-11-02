#include "stringmachine.h"

boolean EndString;
String currentString;

void STARTSTRING()
{
    START();
    IgnoreNewLine();
    if (currentChar == MARK)
    {
        EndString = true;
        currentString.Length = 0;
        currentString.TabString[0] = '\0';

    }
    else
    {
        EndString = false;
        int length = 0;
        while (!(currentChar == MARK))
        {

            currentString.TabString[length++] = currentChar;
            ADV();
        }

        currentString.Length = length;
        currentString.TabString[length] = '\0';
    }
}

boolean isAllBlank(String sentence)
{
    int i;
    for (i = 0; i < sentence.Length; i++)
    {
        if (sentence.TabString[i] != BLANK)
        {
            return false;
        }
    }

    return true;
}

boolean isStringEqual(String s1, String s2)
{
    if (s1.Length != s2.Length)
    {
        return false;
    }
    else
    {
        int i;
        for (i = 0; i < s1.Length; i++)
        {
            if (s1.TabString[i] != s2.TabString[i])
            {
                return false;
            }
        }
        return true;
    }
}

String charArrToString(char *c)
{
    String str;
    char curr = c[0];
    int i = 0;
    while (curr != '\0')
    {
        str.TabString[i++] = curr;
        curr = c[i];
    }

    str.Length = i;

    return str;
}

void printString(String str) {
   int i;
   for (i = 0; i < str.Length; i++) {
      printf("%c", str.TabString[i]);
   }
}

void IgnoreNewLine()
{
    while (currentChar == '\n')
    {
        ADV();
    }
}