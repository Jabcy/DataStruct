#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;


// 向链表中添加元素
void Append(LinkList L, int x)
{
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = L;

    LNode *p = L;
    while (p->next != L)
    {
        p = p->next;
    }
    p->next = newNode;
}

// 打印链表中的所有元素
void PrintList(LinkList L)
{
    if (L->next == L) { // 如果链表为空（只有头节点）
        printf("链表为空\n");
        return;
    }
    LNode *p = L->next; // 跳过头节点开始打印数据
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != L); // 当回到头节点时停止
    printf("...\n"); // 表示循环链表
}

int InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));

    (*L)->next = *L;
    return 1;
}

int mergeList(LinkList A,LinkList B){
    if (A==NULL||B==NULL)
    {
        return 0;
    }
    LNode *tailA = A;
    while (tailA->next != A) tailA = tailA->next;
    LNode *tailB = B;
    while (tailB->next != B) tailB = tailB->next;
    
    // 将B链表连接到A链表后，并释放B的头节点
    tailA->next = B->next;
    tailB->next = A;
    free(B); // 释放原来的B链表头节点
    return 1;
}


int main()
{
    LinkList A,B;
    InitList(&A);
    InitList(&B);
    Append(A,1);
    Append(A,2);
    Append(A,3);
    Append(B,4);
    Append(B,5);
    Append(B,6);
    mergeList(A,B);
    PrintList(A);
    
    return 0;
}
