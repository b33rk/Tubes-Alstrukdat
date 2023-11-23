#include "datetime.h"

void getCurrentDateTime(DATETIME *D)
{
    time_t rawtime;
    time(&rawtime);

    struct tm *local_time = localtime(&rawtime);
    CreateDATETIME(D, local_time->tm_mday, local_time->tm_mon + 1, 1900 + local_time->tm_year, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);
}

int GetMaxDay(int M, int Y)
{
    /* Mengirimkan jumlah hari maksimum pada bulan M dan tahun Y */
    /* Prekondisi: 1 <= M <= 12*/

    switch (M)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 2:
        if ((Y % 400 == 0) || (Y % 400 != 0 && Y % 100 != 0 && Y % 4 == 0))
        {
            return 29;
        }
        else
        {
            return 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    default:
        return -1;
    }

}

boolean IsDATETIMEValid(int D, int M, int Y, int h, int m, int s)
{
    /* Mengirim true jika D,M,Y,h,m,s dapat membentuk D yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah DATETIME */

    return (IsTIMEValid(h, m, s) && (Y >= 1900 && Y <= 2030) && (M >= 1 && M <= 12) && (D >= 1 && D <= GetMaxDay(M, Y)));
}

void CreateDATETIME(DATETIME *D, int DD, int MM, int YYYY, int hh, int mm, int ss)
{
    /* Membentuk sebuah DATETIME dari komponen-komponennya yang valid */
    /* Prekondisi : DD, MM, YYYY, h, m, s valid untuk membentuk DATETIME */

    TIME T;
    CreateTime(&T, hh, mm, ss);

    Day(*D) = DD;
    Month(*D) = MM;
    Year(*D) = YYYY;
    Time(*D) = T;
}

void BacaDATETIME(DATETIME *D)
{
    /* I.S. : D tidak terdefinisi */
    /* F.S. : D terdefinisi dan merupakan DATETIME yang valid */
    /* Proses : mengulangi membaca komponen DD, MM, YY, h, m, s sehingga membentuk D */
    /* yang valid. Tidak mungkin menghasilkan D yang tidak valid. */
    /* Pembacaan dilakukan dengan mengetikkan komponen DD, MM, YY, h, m, s
       dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
    /* Jika DATETIME tidak valid maka diberikan pesan: "DATETIME tidak valid", dan pembacaan
        diulangi hingga didapatkan DATETIME yang valid. */

    int DD, MM, YY, h, m, s;

    for (;;)
    {
        scanf("%d %d %d %d %d %d", &DD, &MM, &YY, &h, &m, &s);

        if (IsDATETIMEValid(DD, MM, YY, h, m, s))
        {
            break;
        }
        else
        {
            printf("DATETIME tidak valid\n");
        }
    }

    CreateDATETIME(D, DD, MM, YY, h, m, s);
}

void TulisDATETIME(DATETIME D)
{
    /* I.S. : D sembarang */
    /* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
    /* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

    printf("%02d/%02d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}

void TulisDATETIMEFile(DATETIME D, FILE* f)
{
    /* I.S. : D sembarang */
    /* F.S. : Nilai D ditulis dg format DD/MM/YYYY HH:MM:SS */
    /* Proses : menulis nilai setiap komponen D ke layar dalam format DD/MM/YYYY HH:MM:SS
       tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.*/

    fprintf(f, "%02d/%02d/%d %02d:%02d:%02d", Day(D), Month(D), Year(D), Hour(Time(D)), Minute(Time(D)), Second(Time(D)));
}


long long int DATETIMEtoDetik(DATETIME D)
{
    long long int totalDetik = 0;
    int i;
    for (i = 1900; i < Year(D); i++)
    {
        totalDetik += (337 + GetMaxDay(2, i)) * 24 * 3600;
    };
    for (i = 1; i < Month(D); i++)
    {
        totalDetik += (GetMaxDay(i, Year(D))) * 24 * 3600;
    };
    for (i = 1; i < Day(D); i++)
    {
        totalDetik += 24 * 3600;
    };
    totalDetik += TIMEToDetik(Time(D));
    return totalDetik;
}

DATETIME SecondtoDATETIME(long long int totalDetik)
{
    int year, month, day;
    TIME T;
    DATETIME D;
    year = 1900;
    month = 1;
    day = 1;
    while (totalDetik >= (337 + GetMaxDay(2, year)) * 24 * 3600)
    {
        totalDetik -= (337 + GetMaxDay(2, year)) * 24 * 3600;
        year += 1;
    }
    while (totalDetik >= (GetMaxDay(month, year) * 24 * 3600))
    {
        totalDetik -= (GetMaxDay(month, year) * 24 * 3600);
        month += 1;
    }
    while (totalDetik >= 24 * 3600)
    {
        day += 1;
        totalDetik -= 24 * 3600;
    }
    T = DetikToTIME(totalDetik);
    CreateDATETIME(&D, day, month, year, Hour(T), Minute(T), Second(T));
    return D;
}


/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok operasi relasional terhadap DATETIME *** */
boolean DEQ(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1=D2, false jika tidak */
    return ((Day(D1) == Day(D2)) && (Month(D1) == Month(D2)) && (Year(D1) == Year(D2)) && TEQ(Time(D1), Time(D2)));
}
boolean DNEQ(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1 tidak sama dengan D2 */
    return !DEQ(D1, D2);
}
boolean DLT(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1<D2, false jika tidak */
    return (DATETIMEtoDetik(D1) < DATETIMEtoDetik(D2));
}
boolean DGT(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1>D2, false jika tidak */
    return (DATETIMEtoDetik(D1) > DATETIMEtoDetik(D2));
}

DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    /* Mengirim salinan D dengan detik ditambah N */
    long long int totalDetik = DATETIMEtoDetik(D);
    totalDetik += N;
    return SecondtoDATETIME(totalDetik);
}

DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    /* Mengirim salinan D dengan detik dikurang N */
    /* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
    return DATETIMENextNDetik(D, -N);
}

long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    /* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
    /* Prekondisi: DAkh > DAw */
    return DATETIMEtoDetik(DAkh) - DATETIMEtoDetik(DAw);
}