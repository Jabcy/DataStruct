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
    L->next = L;//ѭ���������ʼ��ʱ��nextָ��ͷ�ڵ�
    return 1;
}

int empty(LinkList L){
    if (L->next == L)//ѭ�������ж��Ƿ�Ϊ��,���ж�ͷ�ڵ��next�Ƿ�Ϊ�Լ�
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