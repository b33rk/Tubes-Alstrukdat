/* File : time.c */
/* Body ADT TIME */
#include "time1.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* KELOMPOK VALIDASI TERHADAP TYPE */
boolean IsTIMEValid(int H, int M, int S)
{
    /* Mengirim true jika H,M,S dapat membentuk T yang valid */
    /* dipakai untuk mentest SEBELUM membentuk sebuah Jam */
    /* Kamus Lokal */

    /* Algoritma */
    return ((H >= 0 && H <= 23) && (M >= 0 && M <= 59) && (S >= 0 && S <= 59));
}

/* Konstruktor: Membentuk sebuah TIME dari komponen-komponennya */
void CreateTime(TIME *T, int HH, int MM, int SS)
{
    /* Membentuk sebuah TIME dari komponen-komponennya yang valid */
    /* Prekondisi : HH, MM, SS valid untuk membentuk TIME */
    /* I.S. int HH, MM, dan SS */
    /* F.S. T terdefinisi */
    /* Kamus Lokal */

    /* Algoritma */
    if (IsTIMEValid(HH, MM, SS) == true)
    {
        Hour(*T) = HH;
        Minute(*T) = MM;
        Second(*T) = SS;
    }
}

/* KELOMPOK BACA/TULIS */
void BacaTIME(TIME *T)
{
    /* I.S. : T tidak terdefinisi */
    /* F.S. : T terdefinisi dan merupakan jam yang valid */
    /* Kamus Lokal */
    int h, m, s;

    /* Algoritma */
    for (;;)
    {
        scanf("%d %d %d", &h, &m, &s);
        if (IsTIMEValid(h, m, s))
        {
            break;
        }
        else
        {
            printf("Jam tidak valid\n");
        }
    }

    CreateTime(T, h, m, s);
}

void TulisTIME(TIME T)
{
    /* I.S. : T sembarang */
    /* F.S. : Nilai T ditulis dg format HH:MM:SS */
    /* Kamus Lokal */

    /* Algoritma */
    printf("%02d:%02d:%02d", Hour(T), Minute(T), Second(T));
}

/* KELOMPOK KONVERSI TERHADAP TYPE */
long TIMEToDetik(TIME T)
{
    /* Diberikan sebuah TIME, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
    /* Kamus Lokal */

    /* Algoritma */
    return (long)(3600 * Hour(T) + 60 * Minute(T) + Second(T));
}

TIME DetikToTIME(long N)
{
    /* Mengirim  konversi detik ke TIME */
    /* Kamus Lokal */
    int h, m, s;
    TIME T;

    /* Algoritma */
    if (N < 0)
    {
        N += 86400;
    }
    N = N % 86400;

    h = N / 3600;
    m = (N % 3600) / 60;
    s = (N % 3600) % 60;

    CreateTime(&T, h, m, s);
    return T;
}

/* KELOMPOK OPERASI TERHADAP TYPE */
/* Kelompok Operator Relational */
boolean TEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1=T2, false jika tidak */
    /* Kamus Lokal */

    /* Algoritma */
    return (Hour(T1) == Hour(T2) && Minute(T1) == Minute(T2) && Second(T1) == Second(T2));
}

boolean TNEQ(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1 tidak sama dengan T2 */
    /* Kamus Lokal */

    /* Algoritma */
    return (Hour(T1) != Hour(T2) || Minute(T1) != Minute(T2) || Second(T1) != Second(T2));
}
boolean TLT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1<T2, false jika tidak */
    /* Kamus Lokal */

    /* Algoritma */
    return (TIMEToDetik(T1) < TIMEToDetik(T2));
}

boolean TGT(TIME T1, TIME T2)
{
    /* Mengirimkan true jika T1>T2, false jika tidak */
    /* Kamus Lokal */

    /* Algoritma */
    return (TIMEToDetik(T1) > TIMEToDetik(T2));
}

/* *** Operator aritmatika TIME *** */
TIME NextDetik(TIME T)
{
    /* Mengirim 1 detik setelah T dalam bentuk TIME */
    /* Kamus Lokal */
    long detikT, detikTs;

    /* Algoritma */
    detikT = TIMEToDetik(T);
    detikTs = detikT + 1;

    return DetikToTIME(detikTs);
}
TIME NextNDetik(TIME T, int N)
{
    /* Mengirim N detik setelah T dalam bentuk TIME */
    /* Kamus Lokal */
    long detikT, detikTn;

    /* Algoritma */
    detikT = TIMEToDetik(T);
    detikTn = detikT + N;

    return DetikToTIME(detikTn);
}
TIME PrevDetik(TIME T)
{
    /* Mengirim 1 detik sebelum T dalam bentuk TIME */
    /* Kamus Lokal */
    long detikT, detikTs;

    /* Algoritma */
    detikT = TIMEToDetik(T);
    detikTs = detikT - 1;

    return DetikToTIME(detikTs);
}
TIME PrevNDetik(TIME T, int N)
{
    /* Mengirim N detik sebelum T dalam bentuk TIME */
    /* Kamus Lokal */
    long detikT, detikTn;

    /* Algoritma */
    detikT = TIMEToDetik(T);
    detikTn = detikT - N;

    return DetikToTIME(detikTn);
}

/* Kelompok Operator Aritmetika */
long Durasi(TIME TAw, TIME TAkh)
{
    /* Mengirim TAkh-TAw dlm Detik, dengan kalkulasi */
    /* Jika TAw > TAkh, maka TAkh adalah 1 hari setelah TAw */
    /* Kamus Lokal */
    long detikTAw, detikTAkh, selisih;

    /* Algoritma */
    detikTAw = TIMEToDetik(TAw);
    detikTAkh = TIMEToDetik(TAkh);

    if (detikTAkh < detikTAw)
    {
        detikTAkh += 86400;
    }

    selisih = detikTAkh - detikTAw;
    return selisih;
}