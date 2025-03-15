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
    } // 内存分配失败

    L->next = NULL;
    L->prior = NULL;

    return 0;
}

// 删除p节点之后的q节点,只给p节点
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


// 删除一个双链表
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