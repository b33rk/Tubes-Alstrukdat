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

boolean DEQ(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1=D2, false jika tidak */

    return (TEQ(Time(D1), Time(D2)) && (Year(D1) == Year(D2)) && (Month(D1) == Month(D2)) && (Day(D1) == Day(D2)));
}
boolean DNEQ(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1 tidak sama dengan D2 */

    return (TNEQ(Time(D1), Time(D2)) || (Year(D1) != Year(D2)) || (Month(D1) != Month(D2)) || (Day(D1) != Day(D2)));
}
boolean DLT(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1<D2, false jika tidak */

    if (Year(D2) > Year(D1))
    {
        return true;
    }
    else if (Year(D2) == Year(D1))
    {
        if (Month(D2) > Month(D1))
        {
            return true;
        }
        else if (Month(D2) == Month(D1))
        {
            if (Day(D2) > Day(D1))
            {
                return true;
            }
            else if (Day(D2) == Day(D1))
            {
                if (TLT(Time(D1), Time(D2)))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
boolean DGT(DATETIME D1, DATETIME D2)
{
    /* Mengirimkan true jika D1>D2, false jika tidak */
    if (Year(D1) > Year(D2))
    {
        return true;
    }
    else if (Year(D1) == Year(D2))
    {
        if (Month(D1) > Month(D2))
        {
            return true;
        }
        else if (Month(D1) == Month(D2))
        {
            if (Day(D1) > Day(D2))
            {
                return true;
            }
            else if (Day(D1) == Day(D2))
            {
                if (TGT(Time(D1), Time(D2)))
                {
                    return true;
                }
            }
        }
    }

    return false;
}
DATETIME DATETIMENextNDetik(DATETIME D, int N)
{
    /* Mengirim salinan D dengan detik ditambah N */

    // int detik, hari, jumlah;

    // detik = N % 86400;
    // hari = N / 86400;

    // Time(D) = NextNDetik(Time(D), detik);

    // if (hari != 0)
    // {
    //     for (jumlah = Day(D) + hari; jumlah > GetMaxDay(Month(D), Year(D)); jumlah = jumlah - ((GetMaxDay(Month(D), Year(D))) - Day(D)))
    //     {
    //         Month(D) = Month(D) + 1;
    //         if (Month(D) == 13)
    //         {
    //             Month(D) = 1;
    //             Year(D) = Year(D) + 1;
    //         }
    //     }
    //     Day(D) = jumlah;
    // }

    // return D;
    Time(D) = NextNDetik(Time(D), N);
    return D;
}
DATETIME DATETIMEPrevNDetik(DATETIME D, int N)
{
    /* Mengirim salinan D dengan detik dikurang N */
    // int detik, hari, jumlah;

    // detik = N % 86400;
    // hari = N / 86400;

    // Time(D) = PrevNDetik(Time(D), detik);

    // if (hari != 0)
    // {
    //     for (jumlah = Day(D) - hari; jumlah < 1; jumlah = jumlah + GetMaxDay((Month(D) - 1 == 0 ? 12 : Month(D) - 1), (Month(D) - 1 == 0 ? Year(D) - 1 : Year(D))))
    //     {
    //         Month(D) = Month(D) - 1;
    //         if (Month(D) == 0)
    //         {
    //             Month(D) = 12;
    //             Year(D) = Year(D) - 1;
    //         }
    //     }
    //     Day(D) = jumlah;
    // }

    // return D;
    Time(D) = PrevNDetik(Time(D), N);
    return D;
}
/* *** Kelompok Operator Aritmetika terhadap DATETIME *** */
long int DATETIMEDurasi(DATETIME DAw, DATETIME DAkh)
{
    /* Mengirim DAkh-DAw dlm Detik, dengan kalkulasi */
    /* Prekondisi: DAkh > DAw */

    // unsigned long b, sAw, sAkh;

    // selisih = 0;

    // for (t = Year(DAw) + 1; t < Year(DAkh); t++)
    // {
    //     if ((t % 400 == 0) || (t % 400 != 0 && t % 100 != 0 && t % 4 == 0))
    //     {
    //         selisih += 366;
    //     }
    //     else
    //     {
    //         selisih += 365;
    //     }
    // }

    // for (b = 1; b < Month(DAkh); b++)
    // {
    //     sAkh += (GetMaxDay(b, Year(DAkh)) * 86400);
    // }
    // sAkh += ((Day(DAkh) - 1) * 86400);
    // sAkh += TIMEToDetik(Time(DAkh));

    // for (b = 1; b < Month(DAw); b++)
    // {
    //     sAw += (GetMaxDay(b, Year(DAw)) * 86400);
    // }
    // sAw += ((Day(DAw) - 1) * 86400);
    // sAw += TIMEToDetik(Time(DAw));

    // for (b = Month(DAw) + 1; b <= 12; b++)
    // {
    //     selisih += GetMaxDay(b, Year(DAw));
    // }
    // selisih += (GetMaxDay(Month(DAw), Year(DAw)) - Day(DAw));

    // selisih += TIMEToDetik(Time(DAkh));
    // selisih += (86359 - TIMEToDetik(Time(DAw)));

    return Durasi(Time(DAw), Time(DAkh));
}