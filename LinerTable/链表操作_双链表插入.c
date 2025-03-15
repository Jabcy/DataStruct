#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

int InitDLinkList(DLinkList L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
    {
        return 0;
    }//�ڴ����ʧ��

    L->next = NULL;
    L->prior = NULL;

    return 0;
}

// ��������˫����Ľڵ�,��q���뵽p�ڵ�֮��
int Insert(DNode *p,DNode *q){
    if (p==NULL||q==NULL)
    {
        return 0;
    }
    
    q->next = p->next;
    if(p->next != NULL){
        p->next->prior = q;
    }
    q->prior = p;
    p->next = q;
} 


int main(){
    DLinkList L;
    InitDLinkList(L);
}