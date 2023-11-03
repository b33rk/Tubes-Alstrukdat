#include "textmachine.h"

boolean EndText;
Text currentText;

void STARTTEXT()
{
    START();
    IgnoreNewLineText();
    if (currentChar == MARK)
    {
        EndText = true;
        currentText.Length = 0;
        currentText.TabString[0] = '\0';
    }
    else
    {
        EndText = false;
        int length = 0;
        while (!(currentChar == MARK))
        {

            if (length < 280)
                currentText.TabString[length++] = currentChar;
            ADV();
        }

        currentText.Length = length;
        currentText.TabString[length] = '\0';
    }
}

boolean isTextAllBlank(Text sentence)
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

boolean isTextEqual(Text s1, Text s2)
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

Text charArrToText(char *c)
{
    Text str;
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

void printText(Text str)
{
    int i;
    for (i = 0; i < str.Length; i++)
    {
        printf("%c", str.TabString[i]);
    }
}

void IgnoreNewLineText()
{
    while (currentChar == '\n')
    {
        ADV();
    }
}