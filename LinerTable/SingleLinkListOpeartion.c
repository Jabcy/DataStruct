#include <stdio.h>
// 单链表结构体定义
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// 单链表按位查询 
LNode* SearchNodeByBit(LinkList L,int i){
    if (i<1)
    {
        return NULL;
    }
    
    LNode *p;
    p = L;
    int j = 0;
    while (p!=NULL&&j<i)
    {
        p = p->next;
        j++;
    }
    // if (p==NULL)
    // {
    //     return NULL;
    // }
    // 不用判断是否为NULL,反正都要返回,正确就返回结果,错误就返回NULL
    return p;
}//时间复杂度O(n)

// 单链表按值查询
int SearchNodeByValue(LinkList L,int e){
    
    LNode *p;
    p = L->next;
    while (p!=NULL&&p->data!=e)
    {
        p = p->next;
    }
    // if (p==NULL)
    // {
    //     return NULL;
    // }
    // 不用判断是否为NULL,反正都要返回,正确就返回结果,错误就返回NULL
    return p;
}//时间复杂度O(n)

// 尾插法建立单链表
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

// 头插法建立单链表
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

// 获取单链表表长
int GetLength(LinkList L)
{
    LNode *p;
    p = L;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// 删除某个节点
int Delete(LinkList L,int i ,int *e){
    if (i<1)
    {
        return 0;
    }
    int j = 0;
    LNode *p,*q;
    p = L;
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        return 0;
    }
    
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}//时间复杂度O(1)
// 有时并未给出头节点,也就无法获取要删除节点的前驱节点,那么就将后继节点的数据赋给要删除节点,之后删除后继节点

// 向不带头节点的链表中第i个位置插入节点
int InsertList(LinkList L,int i,int e){
    
    if (i<1)
    {
        return 0;
        printf("插入位序不合法\n");
    }
    LNode *p,*q;
    // for (int j = 0; j < i-1; j++)
    // {
    //     p = p->next;
    // }// 现在p指向i的前一个节点
    // 将for循环改为while循环,可以方便地判断是否到尾节点
    
    // 第一个节点要特殊处理
    if (i == 1)
    {   
        q = (LNode *)malloc(sizeof(LNode));
        if (q == NULL)
        {
            return 0;
        }
        
        q->data = e;
        q->next = L->next;
        L->next = q;
        return 1;
    }

    // 除第一个节点外的节点处理逻辑
    int j = 1;
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        printf("插入位序大于表长+1,不合法,插入失败\n");
        return 0;
    }
    q = (LNode*)malloc(sizeof(LNode));
    if (q==NULL)
    {
        return 0;
    }
    
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 0;
}

// 向带有头节点的链表中第i个位置插入节点
int InsertList2(LinkList L,int i,int e){
    
    if (i<1)
    {
        return 0;
        printf("插入位序不合法\n");
    }

    LNode *p,*q;
    int j=0;
    p = L;
    // for (int j = 0; j < i-1; j++)
    // {
    //     p = p->next;
    // }// 现在p指向i的前一个节点
    // 将for循环改为while循环,可以方便地判断是否到尾节点
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        printf("插入位序大于表长+1,不合法,插入失败\n");
        return 0;
    }
    q = (LNode*)malloc(sizeof(LNode));
    if (q==NULL)
    {
        return 0;
    }
    
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 0;
}

// 向某个节点后插入节点
int Insert(LNode *L, int e){
    if (L==NULL)
    {
        return 0;
    }
    
    LNode *p;
    p =(LNode *)malloc(sizeof(LNode));
    if (p==NULL)
    {
        return 0;
    }
    
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

// 向某个节点前插入节点
int Insert(LNode *q, int e){
    if (q==NULL)
    {
        return 0;
    }
    
    LNode *p;
    p =(LNode *)malloc(sizeof(LNode));
    if (p==NULL)
    {
        return 0;
    }
    
    p->data = e;
    p->next = q->next;
    q->next = p;
    int temp = q->data;
    q->data = p->data;
    p->data = temp;
    
    return 1;
}

int main()
{
    LinkList L;
    InitLinkList2(L);
    
    return 0;
}
