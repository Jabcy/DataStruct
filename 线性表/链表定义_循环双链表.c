#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
    int data;
    DNode *next;
    DNode *prior;
}DNode,*DLinkList;

int InitList(DLinkList L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//循环双链表初始化时让next和prior指向头节点
    L->prior = L; 
    return 1;
}

int empty(DLinkList L){
    if (L->next == L)//循环链表判断是否为空,就判断头节点的next是否为自己
    {
        return 1;
    }
    return 0;
}

int isTail(DLinkList L,DNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}