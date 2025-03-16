#include<stdio.h>

#define MAXSIZE 10
// 单链表结构体
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// 静态链表结构体
typedef struct Node
{
    int data;
    int next;
}SLinkList[MAXSIZE];//定义每个节点

// 双链表结构体
typedef struct DNode{
    int data;
    DNode *next;
    DNode *prior;
}DNode,*DLinkList;

// 静态链表定义
int initStaticList(SLinkList L){

    for (int i = 0; i < MAXSIZE; i++)
    {
        L[i].data = -2;//将所有节点的next设为-2,意味着空
    }
    L->next = -1;//代表指向了表尾,类似于NULL
}

// 单链表定义
//不带头节点----此指针的next所指向的空间就是第一个节点
//空表判断L == NULL
int InitLinkList(LinkList L){
    L->next = NULL;
    return 0;
}

// 单链表定义
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

// 循环单链表
int InitCircularSingleList(LinkList L){
    L = (LNode*)malloc(sizeof(LNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//循环单链表初始化时让next指向头节点
    return 1;
}

// 循环双链表
int InitCircularDoubleList(DLinkList L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//循环双链表初始化时让next和prior指向头节点
    L->prior = L; 
    return 1;
}

// 循环单链表判空
int empty(LinkList L){
    if (L->next == L)//循环链表判断是否为空,就判断头节点的next是否为自己
    {
        return 1;
    }
    return 0;
}

// 循环单链表判断尾节点
int isTail(LinkList L,LNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}

// 循环双链表判空
int empty(DLinkList L){
    if (L->next == L)//循环链表判断是否为空,就判断头节点的next是否为自己
    {
        return 1;
    }
    return 0;
}

// 循环双链表判断尾节点 
int isTail(DLinkList L,DNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}

int main(){
    LinkList L;
    LinkList L2;
    InitLinkList(L);
    InitLinkList2(L2);
}