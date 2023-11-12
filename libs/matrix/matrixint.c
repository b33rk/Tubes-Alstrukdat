#include "matrixint.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatrixInt *** */
void createMatrixInt(int nRows, int nCols, MatrixInt *m)
{
    /* Membentuk sebuah MatrixInt "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
    /* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
    /* F.S. Matriks m sesuai dengan definisi di atas terbentuk */
    /* KAMUS */

    /* ALGORITMA */
    m->rowEff = nRows;
    m->colEff = nCols;
}

/* *** Selektor "Dunia MatrixInt" *** */
boolean isMatrixIntIdxValid(int i, int j)
{
    /* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < 50) && (j >= 0 && j < 50);
}

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
int getMatrixIntLastIdxRow(MatrixInt m)
{
    /* Mengirimkan Index baris terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return m.rowEff - 1;
}
int getMatrixIntLastIdxCol(MatrixInt m)
{
    /* Mengirimkan Index kolom terbesar m */
    /* KAMUS */

    /* ALGORITMA */
    return m.colEff - 1;
}
boolean isMatrixIntIdxEff(MatrixInt m, int i, int j)
{
    /* Mengirimkan true jika i, j adalah Index efektif bagi m */
    /* KAMUS */

    /* ALGORITMA */
    return (i >= 0 && i < m.rowEff) && (j >= 0 && j < m.colEff);
}
int getMatrixIntElmtDiagonal(MatrixInt m, int i)
{
    /* Mengirimkan elemen m(i,i) */
    /* KAMUS */

    /* ALGORITMA */
    return m.mem[i][i];
}

/* ********** Assignment  MatrixInt ********** */
void copyMatrixInt(MatrixInt mIn, MatrixInt *mOut)
{
    /* Melakukan assignment mOut <- mIn */
    /* KAMUS */
    int i, j;

    /* ALGORITMA */
    createMatrixInt(mIn.rowEff, mIn.colEff, mOut);
    for (i = 0; i < mIn.rowEff; i++)
    {
        for (j = 0; j < mIn.colEff; j++)
        {
            mOut->mem[i][j] = mIn.mem[i][j];
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixInt(MatrixInt *m, int nRow, int nCol)
{
    /* I.S. isIdxValid(nRow,nCol) */
    /* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
    /* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
    /* Selanjutnya membaca nilai elemen per baris dan kolom */
    /* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
    1 2 3
    4 5 6
    8 9 10
    */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    createMatrixInt(nRow, nCol, m);

    for (i = 0; i < nRow; i++)
    {
        for (j = 0; j < nCol; j++)
        {
            scanf("%d", &m->mem[i][j]);
        }
    }
}
void displayMatrixInt(MatrixInt m)
{
    /* I.S. m terdefinisi */
    /* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
       dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
    /* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
    /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
    1 2 3
    4 5 6
    8 9 10
    */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            printf("%d", m.mem[i][j]);
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

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MatrixInt addMatrixInt(MatrixInt m1, MatrixInt m2)
{
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil penjumlahan matriks: m1 + m2 */
    /* KAMUS */
    int i, j;
    MatrixInt m3;

    /*ALGORITMA*/
    createMatrixInt(m1.rowEff, m1.colEff, &m3);

    for (i = 0; i < m1.rowEff; i++)
    {
        for (j = 0; j < m1.colEff; j++)
        {
            m3.mem[i][j] = m1.mem[i][j] + m2.mem[i][j];
        }
    }

    return m3;
}
MatrixInt subtractMatrixInt(MatrixInt m1, MatrixInt m2)
{
    /* Prekondisi : m1 berukuran sama dengan m2 */
    /* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
    /* KAMUS */
    int i, j;
    MatrixInt m3;

    /*ALGORITMA*/
    createMatrixInt(m1.rowEff, m1.colEff, &m3);

    for (i = 0; i < m1.rowEff; i++)
    {
        for (j = 0; j < m1.colEff; j++)
        {
            m3.mem[i][j] = m1.mem[i][j] - m2.mem[i][j];
        }
    }

    return m3;
}
MatrixInt multiplyMatrixInt(MatrixInt m1, MatrixInt m2)
{
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan m1 * m2 */
    /* KAMUS */
    int i, j, k;
    MatrixInt m3;

    /*ALGORITMA*/
    createMatrixInt(m1.rowEff, m2.colEff, &m3);

    for (i = 0; i < m1.rowEff; i++)
    {
        for (j = 0; j < m1.colEff; j++)
        {
            m3.mem[i][j] = 0;
            for (k = 0; k < m1.colEff; k++)
            {
                m3.mem[i][j] += (m1.mem[i][k] * m2.mem[k][j]);
            }
        }
    }

    return m3;
}
MatrixInt multiplyMatrixIntWithMod(MatrixInt m1, MatrixInt m2, int mod)
{
    /* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
    /* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
    /* KAMUS */
    int i, j;
    MatrixInt m3;

    /*ALGORITMA*/
    m3 = multiplyMatrixInt(m1, m2);
    for (i = 0; i < m3.rowEff; i++)
    {
        for (j = 0; j < m3.colEff; j++)
        {
            m3.mem[i][j] %= mod;
        }
    }

    return m3;
}
MatrixInt multiplyMatrixIntByConst(MatrixInt m, int x)
{
    /* Mengirim hasil perkalian setiap elemen m dengan x */
    /* KAMUS */
    int i, j;
    MatrixInt m2;

    /*ALGORITMA*/
    createMatrixInt(m.rowEff, m.colEff, &m2);

    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            m2.mem[i][j] = m.mem[i][j] * x;
        }
    }

    return m2;
}
void pMultiplyMatrixIntByConst(MatrixInt *m, int k)
{
    /* I.S. m terdefinisi, k terdefinisi */
    /* F.S. Mengalikan setiap elemen m dengan k */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    for (i = 0; i < m->rowEff; i++)
    {
        for (j = 0; j < m->colEff; j++)
        {
            m->mem[i][j] *= k;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatrixInt ********** */
boolean isMatrixIntEqual(MatrixInt m1, MatrixInt m2)
{
    /* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
    /* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
    /* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    if (countMatrixIntElmt(m1) != countMatrixIntElmt(m2))
    {
        return false;
    }

    if (getMatrixIntLastIdxCol(m1) != getMatrixIntLastIdxCol(m2))
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
boolean isMatrixIntNotEqual(MatrixInt m1, MatrixInt m2)
{
    /* Mengirimkan true jika m1 tidak sama dengan m2 */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    if (countMatrixIntElmt(m1) != countMatrixIntElmt(m2))
    {
        return true;
    }

    if (getMatrixIntLastIdxCol(m1) != getMatrixIntLastIdxCol(m2))
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
boolean isMatrixIntSizeEqual(MatrixInt m1, MatrixInt m2)
{
    /* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
    /* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */
    /* KAMUS */

    /*ALGORITMA*/
    return m1.rowEff == m2.rowEff && m1.colEff == m2.colEff;
}

/* ********** Operasi lain ********** */
int countMatrixIntElmt(MatrixInt m)
{
    /* Mengirimkan banyaknya elemen m */
    /* KAMUS */

    /*ALGORITMA*/
    return m.colEff * m.rowEff;
}

/* ********** KELOMPOK TEST TERHADAP MatrixInt ********** */
boolean isMatrixIntSquare(MatrixInt m)
{
    /* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
    /* KAMUS */

    /*ALGORITMA*/
    return (m.rowEff == m.colEff);
}
boolean isMatrixIntSymmetric(MatrixInt m)
{
    /* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
       dan untuk setiap elemen m, m(i,j)=m(j,i) */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    if (!isMatrixIntSquare(m))
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
boolean isMatrixIntIdentity(MatrixInt m)
{
    /* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
       setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            if (i == j)
            {
                if (m.mem[i][j] != 1)
                    return false;
            }
            else
            {
                if (m.mem[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}
boolean isMatrixIntSparse(MatrixInt m)
{
    /* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
       hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
    /* KAMUS */
    int i, j;
    int count;
    int eff;
    float persen;

    /*ALGORITMA*/
    count = countMatrixIntElmt(m);
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            if (m.mem[i][j] != 0)
            {
                eff++;
            }
        }
    }

    persen = (float)(eff * 100) / (float)count;
    // printf("\n%f\n", persen);

    if (persen <= 5.0)
    {
        return true;
    }

    return false;
}
MatrixInt negationMatrixInt(MatrixInt m)
{
    /* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            m.mem[i][j] *= -1;
        }
    }

    return m;
}
void pNegationMatrixInt(MatrixInt *m)
{
    /* I.S. m terdefinisi */
    /* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
    /* KAMUS */
    int i, j;

    /*ALGORITMA*/
    for (i = 0; i < m->rowEff; i++)
    {
        for (j = 0; j < m->colEff; j++)
        {
            m->mem[i][j] *= -1;
        }
    }
}

float determinantMatrixInt(MatrixInt m)
{
    /* Prekondisi: isSquare(m) */
    /* Menghitung nilai determinan m */
    /* KAMUS */
    int i, j, k;
    float det;
    MatrixInt mtemp;
    int plus2;

    /*ALGORITMA*/
    det = 0.0;
    plus2 = 0;
    if (countMatrixIntElmt(m) == 4)
    {
        return (float)(m.mem[0][0] * m.mem[1][1]) - (m.mem[0][1] * m.mem[1][0]);
    }
    else
    {
        for (i = 0; i < m.colEff; i++)
        {
            createMatrixInt(m.rowEff - 1, m.colEff - 1, &mtemp);
            for (j = 0; j < mtemp.rowEff; j++)
            {
                plus2 = 0;
                for (k = 0; k < mtemp.colEff; k++)
                {
                    if (k == i)
                    {
                        plus2++;
                    }
                    mtemp.mem[j][k] = m.mem[j+1][k+plus2];
                }
            }

            det += (float)(((i % 2 == 0) ? 1.0 : -1.0) * m.mem[0][i] * determinantMatrixInt(mtemp));
        }
    }

    return det;
    
}
MatrixInt transposeMatrixInt(MatrixInt m)
{
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /* KAMUS */
    int i, j;
    MatrixInt mt;

    /*ALGORITMA*/
    createMatrixInt(m.rowEff, m.colEff, &mt);
    for (i = 0; i < m.rowEff; i++)
    {
        for (j = 0; j < m.colEff; j++)
        {
            mt.mem[i][j] = m.mem[j][i];
        }
    }

    return mt;
}
void pTransposeMatrixInt(MatrixInt *m)
{
    /* I.S. m terdefinisi dan IsSquare(m) */
    /* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
    /* KAMUS */
    int i, j;
    MatrixInt mt;

    /*ALGORITMA*/
    createMatrixInt(m->rowEff, m->colEff, &mt);
    for (i = 0; i < m->rowEff; i++)
    {
        for (j = 0; j < m->colEff; j++)
        {
            mt.mem[j][i] = m->mem[i][j];
        }
    }

    *m = mt;
}
