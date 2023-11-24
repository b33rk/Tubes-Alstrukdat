#include <stdio.h>
#include "../../libs/list/listdinkicau.h"

int main()
{
    ListDinKicau list;
    Kicauan k;
    int type, x;
    CreateListDinKicau(&list, 5);
    CreateKicauan(&k);

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        insertLastListDinKicau(&list, k);
        printf("%d\n", listDinKicauLength(list));
        break;
    case 2:
        scanf("%d", &x);
        k.idUser = x;
        insertLastListDinKicau(&list, k);
        printf("%d\n", list.buffer[0].idUser);
        break;
    case 3:
        scanf("%d", &x);
        k.id = x;
        Kicauan tumbal;
        CreateKicauan(&tumbal);
        insertLastListDinKicau(&list, tumbal);
        insertLastListDinKicau(&list, tumbal);
        insertLastListDinKicau(&list, k);
        insertLastListDinKicau(&list, tumbal);
        printf("%d\n", indexOfListDinKicauById(list, x)); // 2
        break;
    }

    return 0;
}