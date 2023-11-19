#include "graphfriendship.h"

void CreateGraphFriendship(GraphFriendship *graph)
{
    createMatrixInt(20, 20, &(graph->matrix));
    int i, j;
    for (i = 0; i < graph->matrix.rowEff; i++)
    {
        for (j = 0; j < graph->matrix.colEff; j++)
        {
            graph->matrix.mem[i][j] = 0;
        }
    }
}

void addGraphFriendshipRelation(GraphFriendship *graph, int id1, int id2)
{
    graph->matrix.mem[id1][id2] = 1;
    graph->matrix.mem[id2][id1] = 1;
}

void deleteGraphFriendshipRelation(GraphFriendship *graph, int id1, int id2)
{
    graph->matrix.mem[id1][id2] = 0;
    graph->matrix.mem[id2][id1] = 0;
}

ListStatikInt getGraphFriendshipRelation(GraphFriendship graph, int id)
{
    ListStatikInt list;
    CreateListStatikInt(&list);

    int i;
    for (i = 0; i < graph.matrix.rowEff; i++)
    {
        list.contents[i] = graph.matrix.mem[id][i];
    }

    return list;
}

int countGraphFriendshipRelation(GraphFriendship graph, int id)
{
    int count = 0;
    int i;

    for (i = 0; i < graph.matrix.rowEff; i++)
    {
        if (graph.matrix.mem[id][i] == 1)
        {
            count++;
        }
    }

    return count;
}

void addGraphFriendshipPending(GraphFriendship *graph, int id1, int id2)
{
    graph->matrix.mem[id1][id2] = -1;
    graph->matrix.mem[id2][id1] = -1;
}

boolean isPending(GraphFriendship graph, int id1, int id2)
{
    return graph.matrix.mem[id1][id2] == -1;
}

boolean isHasRelation(GraphFriendship graph, int id1, int id2)
{
    return graph.matrix.mem[id1][id2] == 1;
}
