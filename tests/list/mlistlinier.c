#include <stdio.h>
#include <stdlib.h>
#include "../../libs/list/listlinierutas.h"

int main(){
    Utas l;

    int type;
    scanf("%d", &type);

    ElUtas valTumbal, val, val1, val2, val3, val4;

    switch(type){
        case 1:
            CreateUtas(&l);
            printf("%d\n", isEmptyUtas(l)); // 1
            break;
        case 2:
            val;
            val.id = 12;
            insertFirstUtas(&l, val);
            printf("%d\n", l->info.id); // 12
            break;
        case 3:
            val1;
            val1.id = 0;
            val2;
            val2.id = 1;
            val3;
            val3.id = 2;
            insertLastUtas(&l, val1);
            insertLastUtas(&l, val2);
            insertLastUtas(&l, val3);
            printf("%d %d %d\n", lengthUtas(l), getElmtUtas(l, 1).id, isEmptyUtas(l)); // 3 1 0
            break;
        case 4:
            val1;
            val1.id = 0;
            val2;
            val2.id = 1;
            val3;
            val3.id = 2;
            val4;
            val4.id = 3;
            valTumbal;
            insertLastUtas(&l, val1);
            insertLastUtas(&l, val2);
            insertLastUtas(&l, val3);
            deleteAtUtas(&l, 2, &valTumbal);
            printf("%d ", getElmtUtas(l, 1).id); // 1
            insertLastUtas(&l, val4);
            printf("%d %d %d\n", lengthUtas(l), getElmtUtas(l, 2).id, getElmtUtas(l, 0).id); // 3 3 0
            break;
    }
}