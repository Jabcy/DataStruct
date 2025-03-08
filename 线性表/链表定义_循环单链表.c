#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int data;
    LNode *next;
}LNode,*LinkList;

int InitList(LinkList L){
    L = (LNode*)malloc(sizeof(LNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//循环单链表初始化时让next指向头节点
    return 1;
}

int empty(LinkList L){
    if (L->next == L)//循环链表判断是否为空,就判断头节点的next是否为自己
    {
        return 1;
    }
    return 0;
}

int isTail(LinkList L,LNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}