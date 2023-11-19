#include "draft.h"
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"

void CopyText(Text k, Draft *D){
    for(int i = 0; i < k.Length ; i++){
        Teks(*D).TabString[i] = k.TabString[i];
    }
}

void CreateEmptyStack(StackDraft *S){
    Top(*S) = Nil;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(StackDraft S){
    return Top(S) == Nil;
}
/* Mengirim true jika StackDraft kosong: lihat definisi di atas */
boolean IsFullStack(StackDraft S){
    return Top(S) == MaxEl - 1;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke StackDraft ************ */
void PushStack(StackDraft * S, Draft X){
    Top(*S) += 1;
    InfoTop(*S) = X; 
}
/* Menambahkan X sebagai elemen StackDraft S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen StackDraft ************ */
void PopStack(StackDraft * S, Draft* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}
/* Menghapus X dari StackDraft S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void buatdraft(StackDraft draf){
    printf("Masukkan draf:\n");
    STARTTEXT();
    printText(currentText);
}
void hapusdraft(StackDraft draf){
    pop();
}
void simpandraft(StackDraft* draf, Text currentText){
    Draft D;
    time_t t = time(NULL);
    localtime(&t);
    CopyText(currentText, &D);
    Date(D) = localtime(&t);
    pushStack(draf,D);
    printf("Draf telah berhasil disimpan!\n");
}
void terbitdraft(Draft draft){
    printf("Selamat! Draf kicauan telah diterbitkan!\n");
    printf("Detil kicauan:\n");
    printf("|  ID:\n");
    printf("|  \n");
    printf("|  \n");
    printf("|  Detil kicauan:\n");
    printf("|  Disukai:\n");
}

void ubahdraft(StackDraft* draf){
    popStack(draf);
    buatdraft(*draf);
}

void lihatdraft(StackDraft* draf){
    if (isEmptyStack(*draf)){
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");
    } else {
        printf("Ini draf terakhir anda:\n");
        printf("|  :\n");
        printf("|  :\n");
        STARTWORD();
    }
}