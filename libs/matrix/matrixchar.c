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
    m->rowEff = row;
    m->colEff = col;
}

/* *** Selektor "Dunia MatrixChar" *** */
boolean isMatrixCharIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < 50) && (j >= 0 && j < 50);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
int getMatrixCharLastIdxRow(MatrixChar m)
{
    /* Mengirimkan Index baris terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return m.rowEff - 1;
}
int getMatrixCharLastIdxCol(MatrixChar m)
{
    /* Mengirimkan Index kolom terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return m.colEff - 1;
}
boolean isMatrixCharIdxEff(MatrixChar m, int i, int j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < m.rowEff) && (j >= 0 && j < m.colEff);
}
char getMatrixCharElmtDiagonal(MatrixChar m, int i)
{
    /* Mengirimkan elemen m(i,i) */
    /* KAMUS */

    /* ALGORITMA */
    return m.mem[i][i];
}

/* ********** Assignment  MatrixChar ********** */
void copyMatrixChar(MatrixChar mIn, MatrixChar *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    /* KAMUS */
    int i, j;

    /* ALGORITMA */
    createMatrixChar(mOut, mIn.rowEff, mIn.colEff);
    for (i = 0; i < mIn.rowEff; i++)
    {
        for (j = 0; j < mIn.colEff; j++)
        {
            mOut->mem[i][j] = mIn.mem[i][j];
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixChar(MatrixChar *m, int row, int col)
{

    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    createMatrixChar(m, row, col);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%c", &(m->mem[i][j]));
        }
    }
}
void displayMatrixChar(MatrixChar m)
{

    int i, j;

    /*ALGORITMA*/
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            printf("%c", m.mem[i][j]);
            if (j == m.colEff - 1)
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
    int i, j;

    /*ALGORITMA*/
    if (countMatrixCharElmt(m1) != countMatrixCharElmt(m2))
    {
        return false;
    }

    if (getMatrixCharLastIdxCol(m1) != getMatrixCharLastIdxCol(m2))
    {
        return false;
    }

    for (i = 0; i < m1.rowEff; i++)
    {
        for (j = 0; j < m1.colEff; j++)
        {
            if (m1.mem[i][j] != m2.mem[i][j])
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
    int i, j;

    /*ALGORITMA*/
    if (countMatrixCharElmt(m1) != countMatrixCharElmt(m2))
    {
        return true;
    }

    if (getMatrixCharLastIdxCol(m1) != getMatrixCharLastIdxCol(m2))
    {
        return true;
    }

    for (i = 0; i < m1.rowEff; i++)
    {
        for (j = 0; j < m1.colEff; j++)
        {
            if (m1.mem[i][j] != m2.mem[i][j])
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
    return m1.rowEff == m2.rowEff && m1.colEff == m2.colEff;
}

/* ********** Operasi lain ********** */
int countMatrixCharElmt(MatrixChar m)
{
    /* Mengirimkan banyaknya elemen m */
    /* KAMUS */

    /*ALGORITMA*/
    return m.colEff * m.rowEff;
}

/* ********** KELOMPOK TEST TERHADAP MatrixChar ********** */
boolean isMatrixCharSquare(MatrixChar m)
{
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* KAMUS */

    /*ALGORITMA*/
    return (m.rowEff == m.colEff);
}
boolean isMatrixCharSymmetric(MatrixChar m)
{
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
       dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    if (!isMatrixCharSquare(m))
    {
        return false;
    }
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            if (m.mem[i][j] != m.mem[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
