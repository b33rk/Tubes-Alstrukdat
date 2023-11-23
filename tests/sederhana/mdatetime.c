#include <stdio.h>
#include "../../libs/sederhana/datetime.h"

int main()
{
    int type, DD, BB, YYYY, HH, MM, SS;
    DATETIME datetime, datetime2;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        // Test Create DATETIME
        scanf("%d", &DD);
        scanf("%d", &BB);
        scanf("%d", &YYYY);
        scanf("%d", &HH);
        scanf("%d", &MM);
        scanf("%d", &SS);
        CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
        TulisDATETIME(datetime);
        printf("\n");
        break;

    case 2:
        scanf("%d", &DD);
        scanf("%d", &BB);
        scanf("%d", &YYYY);
        scanf("%d", &HH);
        scanf("%d", &MM);
        scanf("%d", &SS);
        CreateDATETIME(&datetime, DD, BB, YYYY, HH, MM, SS);
        scanf("%d", &DD);
        scanf("%d", &BB);
        scanf("%d", &YYYY);
        scanf("%d", &HH);
        scanf("%d", &MM);
        scanf("%d", &SS);
        CreateDATETIME(&datetime2, DD, BB, YYYY, HH, MM, SS);
        printf("%d %d\n", DGT(datetime, datetime2), DLT(datetime, datetime2));
        break;
    }

    return 0;
}