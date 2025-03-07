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

// 双链表的向后遍历,给某个数据节点
// 若需要查找某个位序的节点,则使用一个计数器i++
int ShowDLinkListBack(DNode *p){
    while (p!=NULL)
    {
        printf("%d",p->data);
        p = p->next;
         
    }
}

// 双链表的向后遍历,给某个数据节点指针
int ShowDLinkListPrior(DNode *p){
    while (p->prior!=NULL)
    {
        printf("%d",p->data);
        p = p->prior;
    }
    
}

int main(){
    DLinkList L;
    InitDLinkList(L);
}