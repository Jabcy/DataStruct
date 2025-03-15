#include <stdio.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;



//不带头节点----此指针的next所指向的空间就是第一个节点
//空表判断L == NULL
int InitLinkList(LinkList L){
    L->next = NULL;
    return 0;
}

//带头节点------头节点的data保持为空--头节点的next指向第一个节点----头节点只是为了让某些操作更加方便
//空表判断L->next == NULL
int InitLinkList2(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L==NULL)
    {
        printf("内存分配失败\n");
        return 0;
    }
    L->next = NULL;
    return 1;
}
// 插入不带头节点的链表
int InsertList(LinkList L,int i,int e){
    
    if (i<1)
    {
        return 0;
        printf("插入位序不合法\n");
    }
    LNode *p,*q;
    // for (int j = 0; j < i-1; j++)
    // {
    //     p = p->next;
    // }// 现在p指向i的前一个节点
    // 将for循环改为while循环,可以方便地判断是否到尾节点
    
    // 第一个节点要特殊处理
    if (i == 1)
    {   
        q = (LNode *)malloc(sizeof(LNode));
        if (q == NULL)
        {
            return 0;
        }
        
        q->data = e;
        q->next = L->next;
        L->next = q;
        return 1;
    }

    // 除第一个节点外的节点处理逻辑
    int j = 1;
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        printf("插入位序大于表长+1,不合法,插入失败\n");
        return 0;
    }
    q = (LNode*)malloc(sizeof(LNode));
    if (q==NULL)
    {
        return 0;
    }
    
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 0;
}


// 插入带有头节点的链表
int InsertList2(LinkList L,int i,int e){
    
    if (i<1)
    {
        return 0;
        printf("插入位序不合法\n");
    }

    LNode *p,*q;
    int j=0;
    p = L;
    // for (int j = 0; j < i-1; j++)
    // {
    //     p = p->next;
    // }// 现在p指向i的前一个节点
    // 将for循环改为while循环,可以方便地判断是否到尾节点
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        printf("插入位序大于表长+1,不合法,插入失败\n");
        return 0;
    }
    q = (LNode*)malloc(sizeof(LNode));
    if (q==NULL)
    {
        return 0;
    }
    
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 0;
}


int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
