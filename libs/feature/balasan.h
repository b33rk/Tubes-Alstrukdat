#ifndef BALASAN_H
#define BALASAN_H

#include "../tree/treeOfBalasan.h"
#include "../../database/database.h"
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"
#include "../list/listdinkicau.h"
#include "../graph/graphfriendship.h"

void displayAll(TreeOfBalasan T);
void displayNodeAll(TreeOfBalasan T, int Id, int indent);
void displayNode(NodeBalasanAddress N, int Indent);
void balas();
void displayBalasan();
void hapusBalasan();

#endif