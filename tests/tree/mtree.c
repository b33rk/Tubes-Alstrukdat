#include <stdio.h>
#include "../../libs/tree/treeOfBalasan.h"

int main()
{
    TreeOfBalasan T;
    int type, x;
    createTree(&T);

    Text empty = charArrToText("");
    int IdDecoy = 0;

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        addToTreeAt(&T, empty, IdDecoy, 0);
        printf("%d %d\n", isIdInTree(T, 0), isIdInTree(T, 6));
        break;
    case 2:
        scanf("%d", &x);
        addToTreeAt(&T, empty, x, 0);
        printf("%d\n", NODEBALASAN_IDAUTHOR(getNodeInTreeById(T, 1)));
        break;
    case 3:
        addToTreeAt(&T, empty, x, 0);
        addToTreeAt(&T, empty, x, 0);
        addToTreeAt(&T, empty, x, 1);
        addToTreeAt(&T, empty, x, 2);
        printf("%d\n", TreeLength(T));
        break;
    case 4:
        addToTreeAt(&T, empty, x, 0); // Id 1
        addToTreeAt(&T, empty, x, 1); // Id 2
        addToTreeAt(&T, empty, x, 1); // Id 3
        addToTreeAt(&T, empty, x, 2); // Id 4
        addToTreeAt(&T, empty, x, 1); // Id 5
        addToTreeAt(&T, empty, x, 0); // Id 6
        addToTreeAt(&T, empty, x, 4); // Id 7
        addToTreeAt(&T, empty, x, 4); // Id 8
        addToTreeAt(&T, empty, x, 7); // Id 9
        addToTreeAt(&T, empty, x, 2); // Id 10
        addToTreeAt(&T, empty, x, 0); // Id 11
        addToTreeAt(&T, empty, x, 1); // Id 12
        printf("%d ", TreeLength(T));
        deleteTreeNodeAt(&T, 2);
        printf("%d\n", TreeLength(T));
        break;
    }

    return 0;
}