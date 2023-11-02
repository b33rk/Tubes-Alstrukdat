#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanksAndNewLine()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    /* KAMUS */

    /* ALGORITMA */
    while (currentChar == BLANK || currentChar == '\n')
    {
        ADV();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : EndWord = true, dan currentChar = MARK;
              atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */

    /* KAMUS */

    /* ALGORITMA */
    START();
    IgnoreBlanksAndNewLine();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, EndWord = true.
       Proses : Akuisisi kata menggunakan procedure SalinWord */
    /* KAMUS */

    /* ALGORITMA */
    IgnoreBlanksAndNewLine();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        IgnoreBlanksAndNewLine();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    /* KAMUS */
    int length;

    /* ALGORITMA */
    length = 0;
    while (!(currentChar == BLANK || currentChar == MARK))
    {
        if (length < NMax)
        {
            currentWord.TabWord[length++] = currentChar;
        }
        ADV();
    }

    currentWord.Length = length;
}

void printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

Word stringToWord(char* str){
    Word word;
    char curr = str[0];
    int i = 0;
    while (curr != '\0') {
        word.TabWord[i++] = curr;
        curr = str[i];
    }

    word.Length = i;

    return word;
}

boolean isWordEqual(Word w1, Word w2){
    if (w1.Length != w2.Length) {
        return false;
    } else {
        int i;
        for (i = 0; i < w1.Length; i++){
            if (w1.TabWord[i] != w2.TabWord[i]){
                return false;
            }
        }
        return true;
    }
}

