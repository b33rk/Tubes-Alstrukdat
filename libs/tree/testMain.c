#include "treeOfBalasan.h"
#include <stdio.h>

Text stringToText(char* str, int length){
    Text txt;
    CreateText(&txt, 1);
    int i;
    for(i = 0; i < length; i++){
        insertLastText(&txt, str[i]);
    }
    return txt;
}

// int main(){
//     TreeOfBalasan T;
//     createTree(&T);
//     addToTreeAt(&T, stringToText("one", 3), 0);
//     addToTreeAt(&T, stringToText("two", 3), 0);
//     addToTreeAt(&T, stringToText("three", 5), 0);
//     addToTreeAt(&T, stringToText("four", 4), 1);
//     addToTreeAt(&T, stringToText("five", 4), 1);
//     addToTreeAt(&T, stringToText("depth", 5), 4);
//     // deleteTreeNodeAt(&T, 1);
//     displayAll(T);
// }