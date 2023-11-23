#include <stdio.h>
#include "../libs/datetime.h"

int main()
{
    int type, DD, BB, YYYY, HH, MM, SS;
    DATETIME datetime;

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
        break;

    case 2:
        break;

    case 3:
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;
    }

    return 0;
}