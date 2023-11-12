/* ********** Definisi TYPE MatrixInt dengan Index dan elemen integer ********** */

#ifndef MATRIXINT_H
#define MATRIXINT_H

#include "../boolean.h"
#include <stdio.h>

/* Ukuran maksimum baris dan kolom */

typedef struct
{
   int mem[50][50];
   int rowEff; /* banyaknya/ukuran baris yg terdefinisi */
   int colEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MatrixInt;
/* rowEff >= 1 dan colEff >= 1 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MatrixInt *** */
void createMatrixInt(int nRows, int nCols, MatrixInt *m);
/* Membentuk sebuah MatrixInt "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */

/* *** Selektor "Dunia MatrixInt" *** */
boolean isMatrixIntIdxValid(int i, int j);
/* Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */
int getMatrixIntLastIdxRow(MatrixInt m);
/* Mengirimkan Index baris terbesar m */
int getMatrixIntLastIdxCol(MatrixInt m);
/* Mengirimkan Index kolom terbesar m */
boolean isMatrixIntIdxEff(MatrixInt m, int i, int j);
/* Mengirimkan true jika i, j adalah Index efektif bagi m */
int getMatrixIntElmtDiagonal(MatrixInt m, int i);
/* Mengirimkan elemen m(i,i) */

/* ********** Assignment  MatrixInt ********** */
void copyMatrixInt(MatrixInt mIn, MatrixInt *mOut);
/* Melakukan assignment mOut <- mIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrixInt(MatrixInt *m, int nRow, int nCol);
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void displayMatrixInt(MatrixInt m);
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi. Baris terakhir tidak diakhiri dengan newline */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MatrixInt addMatrixInt(MatrixInt m1, MatrixInt m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */
MatrixInt subtractMatrixInt(MatrixInt m1, MatrixInt m2);
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */
MatrixInt multiplyMatrixInt(MatrixInt m1, MatrixInt m2);
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */
MatrixInt multiplyMatrixIntWithMod(MatrixInt m1, MatrixInt m2, int mod);
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan (m1 * m2)%mod, artinya setiap elemen matrix hasil perkalian m1 * m2 dilakukan modulo terhadap mod */
MatrixInt multiplyMatrixIntByConst(MatrixInt m, int x);
/* Mengirim hasil perkalian setiap elemen m dengan x */
void pMultiplyMatrixIntByConst(MatrixInt *m, int k);
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MatrixInt ********** */
boolean isMatrixIntEqual(MatrixInt m1, MatrixInt m2);
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */
boolean isMatrixIntNotEqual(MatrixInt m1, MatrixInt m2);
/* Mengirimkan true jika m1 tidak sama dengan m2 */
boolean isMatrixIntSizeEqual(MatrixInt m1, MatrixInt m2);
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */
/* yaitu RowEff(m1) = RowEff (m2) dan ColEff (m1) = ColEff (m2) */

/* ********** Operasi lain ********** */
int countMatrixIntElmt(MatrixInt m);
/* Mengirimkan banyaknya elemen m */

/* ********** KELOMPOK TEST TERHADAP MatrixInt ********** */
boolean isMatrixIntSquare(MatrixInt m);
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */
boolean isMatrixIntSymmetric(MatrixInt m);
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m)
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
boolean isMatrixIntIdentity(MatrixInt m);
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean isMatrixIntSparse(MatrixInt m);
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
MatrixInt negationMatrixInt(MatrixInt m);
/* Menghasilkan salinan m dengan setiap elemen dinegasikan (dikalikan -1) */
void pNegationMatrixInt(MatrixInt *m);
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
float determinantMatrixInt(MatrixInt m);
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m */
MatrixInt transposeMatrixInt(MatrixInt m);
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. menghasilkan salinan transpose dari m, yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */
void pTransposeMatrixInt(MatrixInt *m);
/* I.S. m terdefinisi dan IsSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */

#endif