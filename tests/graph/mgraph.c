#include <stdio.h>
#include "../../libs/graph/graphfriendship.h"

int main()
{
    GraphFriendship g;
    int type;
    
    CreateGraphFriendship(&g);

    scanf("%d", &type);

    switch (type)
    {
    case 1:
        addGraphFriendshipRelation(&g, 1, 9);
        addGraphFriendshipRelation(&g, 1, 2);
        addGraphFriendshipRelation(&g, 1, 3);
        printf("%d %d %d\n", countGraphFriendshipRelation(g, 1), isHasRelation(g, 1, 2), isHasRelation(g, 2, 3)); // 3 1 0
        break;
    case 2:
        addGraphFriendshipRelation(&g, 1, 9);
        addGraphFriendshipRelation(&g, 1, 2);
        addGraphFriendshipRelation(&g, 1, 3);
        deleteGraphFriendshipRelation(&g, 3, 1);
        deleteGraphFriendshipRelation(&g, 1, 2);
        printf("%d %d %d\n", countGraphFriendshipRelation(g, 1), isHasRelation(g, 1, 2), isHasRelation(g, 9, 1)); // 1 0 1
        break;
    case 3:
        addGraphFriendshipPending(&g, 6, 9);
        addGraphFriendshipPending(&g, 12, 3);
        addGraphFriendshipRelation(&g, 7, 3);
        printf("%d ", countPending(g));// 2
        addGraphFriendshipRelation(&g, 3, 12);
        printf("%d %d %d %d\n", countPending(g), isHasRelation(g, 3, 12), isPending(g, 12, 3), isPending(g, 9, 6)); // 1 1 0 1
        break;
    }

    return 0;
}