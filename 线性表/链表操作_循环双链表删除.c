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
    L->next = L;//ѭ��˫�����ʼ��ʱ��next��priorָ��ͷ�ڵ�
    L->prior = L; 
    return 1;
}

int empty(DLinkList L){
    if (L->next == L)//ѭ�������ж��Ƿ�Ϊ��,���ж�ͷ�ڵ��next�Ƿ�Ϊ�Լ�
    {
        return 1;
    }
    return 0;
}


int insertNextDNode(DNode *p,DNode *q){
    if (p==NULL||q==NULL)
    {
        return 0;
    }
    
    q->next = p->next;
    p->next->prior = q;
    p->next = q;
    q->prior = p;
    return 1;
}


int deleteDNode(DNode *p){
    if (p==NULL)
    {
        return 0;
    }
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return 1;
}


int isTail(DLinkList L,DNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}