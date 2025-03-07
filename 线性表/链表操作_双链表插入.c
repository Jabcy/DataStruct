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
    }//内存分配失败

    L->next = NULL;
    L->prior = NULL;

    return 0;
}

// 给定两个双链表的节点,将q插入到p节点之后
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