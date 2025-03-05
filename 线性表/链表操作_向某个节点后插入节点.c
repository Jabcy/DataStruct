#include <stdio.h>

typedef struct
{
    int data;
    struct LNode *next;
}LNode,*LinkList;


int Insert(LNode *L, int e){
    if (L==NULL)
    {
        return 0;
    }
    
    LNode *p;
    p =(LNode *)malloc(sizeof(LNode));
    if (p==NULL)
    {
        return 0;
    }
    
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
