#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior;
    struct DNode *next;
} DNode, *DLinkList;

int InitDLinkList(DLinkList L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return 0;
    } // �ڴ����ʧ��

    L->next = NULL;
    L->prior = NULL;

    return 0;
}

// ɾ��p�ڵ�֮���q�ڵ�,ֻ��p�ڵ�
int Delete(DNode *p)
{
    if (p == NULL)
    {
        return 0;
    }
    DNode *q = p->next;
    p->next = q->next;
    if (p->next != NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return 0;
}


// ɾ��һ��˫����
int DestoryList(DLinkList L){
    while (L->next)
    {
        Delete(L);
    }
    free(L);
    return 0;
}

int main()
{
    DLinkList L;
    InitDLinkList(L);
}