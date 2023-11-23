#include "stackdraft.h"
#include "../machine/textmachine.h"
#include "../machine/wordmachine.h"

AddressDraft newNodeDraft(Draft d)
{
    AddressDraft p;
    p = (AddressDraft)malloc(sizeof(NodeDraft));
    if (p != NULL) {
        p->info = d;
        p->next = NULL;
    }
    return p;
}
boolean isEmptyStackDraft(StackDraft s) 
{
    return(s.addrTop == NULL); //#################
}

int lengthStackDraft(StackDraft s)
{
    int len = 0;
    AddressDraft p;
    p = s.addrTop;
    while(p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

void CreateStackDraft(StackDraft *s)
{
    s->addrTop = NULL;
}

// void DisplayStackDraft(StackDraft s)
// {
//     AddressDraft p;
//     if(isEmpty(s)) {
//         printf("[]");
//     }
//     else{
//         p = s.addrTop;
//         printf("[");
//         while(p->next != NULL) { //##########
//             printf("%d,",p->info);
//             p = p->next;
//         }
//         printf("%d]",p->info);
//     }
// }

void pushStackDraft(StackDraft *s, Draft d)

{
    AddressDraft p;
    p = newNodeDraft(d);
    if(p != NULL) {
        p->next = s->addrTop;
        s->addrTop = p;
    }
}

void popStackDraft(StackDraft *s, Draft *d)
{
    AddressDraft p;
    p = s->addrTop;
    *d = s->addrTop->info;
    s->addrTop = s->addrTop->next;
    p->next = NULL;
    free(p);
}

void CreateDraft(Draft *draft){
}
    
