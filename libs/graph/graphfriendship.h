#ifndef GRAPHFRIENDSHIP_H
#define GRAPHFRIENDSHIP_H

#include "../boolean.h"
#include "../matrix/matrixint.h"
#include "../list/liststatikint.h"

typedef struct graphFriendship {
    MatrixInt matrix;
} GraphFriendship;

void CreateGraphFriendship(GraphFriendship* graph);

void addGraphFriendshipRelation(GraphFriendship* graph, int id1, int id2);

void deleteGraphFriendshipRelation(GraphFriendship* graph, int id1, int id2);

ListStatikInt getGraphFriendshipRelation(GraphFriendship graph, int id);

int countGraphFriendshipRelation(GraphFriendship graph, int id);

void addGraphFriendshipPending(GraphFriendship* graph, int id1, int id2);

boolean isPending(GraphFriendship graph, int id1, int id2);

boolean isHasRelation(GraphFriendship graph, int id1, int id2);


#endif