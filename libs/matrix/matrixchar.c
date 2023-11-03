#include "matrixchar.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatrixChar *** */
void createMatrixChar(MatrixChar *m, int row, int col)
{
    /* Membentuk sebuah MatrixChar "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* KAMUS */

    /* ALGORITMA */
    ROW_EFF(*m) = row;
    COL_EFF(*m) = col;
}

/* *** Selektor "Dunia MatrixChar" *** */
boolean isMatrixCharIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
IdxType getMatrixCharLastIdxRow(MatrixChar m)
{
    /* Mengirimkan Index baris terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return ROW_EFF(m) - 1;
}
IdxType getMatrixCharLastIdxCol(MatrixChar m)
{
    /* Mengirimkan Index kolom terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return COL_EFF(m) - 1;
}
boolean isMatrixCharIdxEff(MatrixChar m, IdxType i, IdxType j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < ROW_EFF(m)) && (j >= 0 && j < COL_EFF(m));
}
char getMatrixCharElmtDiagonal(MatrixChar m, IdxType i)
{
    /* Mengirimkan elemen m(i,i) */
    /* KAMUS */

    /* ALGORITMA */
    return ELMT(m, i, i);
}

/* ********** Assignment  MatrixChar ********** */
void copyMatrixChar(MatrixChar mIn, MatrixChar *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    /* KAMUS */
    IdxType i, j;

    /* ALGORITMA */
    createMatrixChar(mOut, ROW_EFF(mIn), COL_EFF(mIn));
    for (i = 0; i < ROW_EFF(mIn); i++)
    {
        for (j = 0; j < COL_EFF(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixChar(MatrixChar *m, int row, int col)
{

    /* KAMUS */
    IdxType i, j;

    /*ALGORITMA*/
    createMatrixChar(m, row, col);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%c", &ELMT(*m, i, j));
        }
    }
}
void displayMatrixChar(MatrixChar m)
{

    IdxType i, j;

    /*ALGORITMA*/
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            printf("%c", ELMT(m, i, j));
            if (j == COL_EFF(m) - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatrixChar ********** */
boolean isMatrixCharEqual(MatrixChar m1, MatrixChar m2)
{
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* KAMUS */
    IdxType i, j;

    /*ALGORITMA*/
    if (countMatrixCharElmt(m1) != countMatrixCharElmt(m2))
    {
        return false;
    }

    if (getMatrixCharLastIdxCol(m1) != getMatrixCharLastIdxCol(m2))
    {
        return false;
    }

    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                return false;
            }
        }
    }

    return true;
}
boolean isMatrixCharNotEqual(MatrixChar m1, MatrixChar m2)
{
    /* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* KAMUS */
    IdxType i, j;

    /*ALGORITMA*/
    if (countMatrixCharElmt(m1) != countMatrixCharElmt(m2))
    {
        return true;
    }

    if (getMatrixCharLastIdxCol(m1) != getMatrixCharLastIdxCol(m2))
    {
        return true;
    }

    for (i = 0; i < ROW_EFF(m1); i++)
    {
        for (j = 0; j < COL_EFF(m1); j++)
        {
            if (ELMT(m1, i, j) != ELMT(m2, i, j))
            {
                return true;
            }
        }
    }

    return false;
}
boolean isMatrixCharSizeEqual(MatrixChar m1, MatrixChar m2)
{
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    /* KAMUS */

    /*ALGORITMA*/
    return ROW_EFF(m1) == ROW_EFF(m2) && COL_EFF(m1) == COL_EFF(m2);
}

/* ********** Operasi lain ********** */
int countMatrixCharElmt(MatrixChar m)
{
    /* Mengirimkan banyaknya elemen m */
    /* KAMUS */

    /*ALGORITMA*/
    return COL_EFF(m) * ROW_EFF(m);
}

/* ********** KELOMPOK TEST TERHADAP MatrixChar ********** */
boolean isMatrixCharSquare(MatrixChar m)
{
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* KAMUS */

    /*ALGORITMA*/
    return (ROW_EFF(m) == COL_EFF(m));
}
boolean isMatrixCharSymmetric(MatrixChar m)
{
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
       dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* KAMUS */
    IdxType i, j;

    /*ALGORITMA*/
    if (!isMatrixCharSquare(m))
    {
        return false;
    }
    for (i = 0; i < ROW_EFF(m); i++)
    {
        for (j = 0; j < COL_EFF(m); j++)
        {
            if (ELMT(m, i, j) != ELMT(m, j, i))
            {
                return false;
            }
        }
    }
    return true;
}
