#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/*
    使用头插法产生的链表是输入顺序的逆序
    输入:1,2,3,4,5
    头插法链表:头节点,5,4,3,2,1,NULL
    即可以实现对某个线性表的逆置
*/ 

// 尾插法
LinkList TailInsert(LinkList L)
{
    int x;                              // 用于存储输入的数据
    L = (LNode *)malloc(sizeof(LNode)); // 创建头节点
    LNode *s, *r = L;                   // 创建新建立的节点指针与单链表的尾指针,并且尾指针一开始指向头节点
    scanf("%d", &x);                    // 输入第一个节点数据
    while (x != 9999)                   // 假设输入9999时结束
    {
        s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
        s->data = x;                        // 将数据传给新节点
        r->next = s;                        // 将新节点接到尾节点的后面
        r = s;                              // 更改尾节点的位置为新节点
        scanf("%d", &x);                    // 输入下一个节点数据
    }
    r->next = NULL; // 将尾节点的next置为NULL
    return L;
}
// 头插法
LinkList HeadInsert(LinkList L)
{
    int x;                              // 用于存储输入的数据
    L = (LNode *)malloc(sizeof(LNode)); // 创建头节点
    LNode *s;                           // 创建新建立的节点指针
    L->next = NULL;                     // 初始化头节点的next为NULL
    scanf("%d", &x);                    // 输入第一个节点数据
    while (x != 9999)                   // 假设输入9999时结束
    {                                       
        s = (LNode *)malloc(sizeof(LNode)); // 创建新节点
        s->data = x;                        // 将数据传给新节点
        s->next = L->next;                  // 将新节点插入到头节点之后
        L->next = s;                        // 更新头节点的next指向新插入的节点
        scanf("%d", &x);                    // 输入下一个节点数据
    }
    return L; // 返回已构建好的链表的头指针
}

// 新创建一个链表,并将传入的链表逆置存放在新链表中
LinkList InverseList(LinkList L){
    int x;
    LinkList p;
    p = (LNode *)malloc(sizeof(LNode));
    LNode *s,*q = L->next;
    p->next = NULL;
    while (q!=NULL)
    {
        x = q->data;
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = p->next;
        p->next = s;
        q = q->next;
    }
    return p;
}