#include "draft.h"
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"

Address newNode(ElType x)
{
    Address p;
    p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}
boolean isEmptyStack(StackDraft s) 
{
    return(ADDR_TOP(s) == NIL); //#################
}

int lengthStack(StackDraft s)
{
    int len = 0;
    Address p;
    p = ADDR_TOP(s);
    while(p != NIL) {
        len++;
        p = NEXT(p);
    }
    return len;
}

void CreateStack(StackDraft *s)
{
    ADDR_TOP(*s) = NIL;
}

void DisplayStack(StackDraft s)
{
    Address p;
    if(isEmpty(s)) {
        printf("[]");
    }
    else{
        p = ADDR_TOP(s);
        printf("[");
        while(NEXT(p) != NIL) { //##########
            printf("%d,",INFO(p));
            p = NEXT(p);
        }
        printf("%d]",INFO(p));
    }
}

void pushStack(StackDraft *s, ElType x)

{
    Address p;
    p = newNode(x);
    if(p != NIL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void popStack(StackDraft *s)
{
    Address p;
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NIL;
    free(p);
}

void buatdraft(StackDraft draf){
    printf("Masukkan draf:\n");
    STARTTEXT();
    printText(currentText);
}
void hapusdraft(StackDraft draf){
    pop();
}
void simpandraft(StackDraft* draf, Draft d){
    pushStack(draf,d);
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