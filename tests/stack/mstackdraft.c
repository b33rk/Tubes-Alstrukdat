#include <stdio.h>
#include "../../libs/stack/stackdraft.h"

int intInput(){
    int x;
    scanf("%d", &x);
    return x;
}

int main()
{
    StackDraft draf;
    int type;
    int x;

    Draft d;
    int i;

    char text[32] = "satusampaisembilanpuluhsembilan";
    for(i = 0; i < 32; i++){d.text[i] = text[i];}

    DATETIME DTtest;
    CreateDATETIME(&DTtest, 0, 0, 0, 0, 0, 0);

    d.datetime = DTtest;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        CreateStackDraft(&draf);
        printf("%d\n", isEmptyStackDraft(draf));
        break;
    case 2:
        CreateStackDraft(&draf);
        pushStackDraft(&draf, d);
        printf("%d\n", lengthStackDraft(draf));
        break;
    case 3:
        CreateStackDraft(&draf);
        pushStackDraft(&draf, d);
        Draft d1;
        Draft d2;
        Draft ddecoy;
        pushStackDraft(&draf, d1);
        popStackDraft(&draf, &ddecoy);
        pushStackDraft(&draf, d2);
        pushStackDraft(&draf, d1);
        printf("%d %d\n", lengthStackDraft(draf), (DEQ(draf.addrTop->next->next->info.datetime, DTtest)));
        break;
    }


    return 0;
}