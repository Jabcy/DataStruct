#include<stdio.h>
#include<stdlib.h>
// 双链表结构体定义
typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

// 双链表初始化
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

// 双链表的向前遍历,给某个数据节点指针
int ShowDLinkListPrior(DNode *p){
    while (p->prior!=NULL)
    {
        printf("%d",p->data);
        p = p->prior;
    }
    
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

// 循环双链表初始化
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

// 循环双链表判空
int empty(DLinkList L){
    if (L->next == L)//循环链表判断是否为空,就判断头节点的next是否为自己
    {
        return 1;
    }
    return 0;
}

// 循环双链表插入
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

// 循环双链表判断尾节点
int isTail(DLinkList L,DNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}

// 循环双链表删除
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

int main(){
    DLinkList L;
    InitDLinkList(L);
}