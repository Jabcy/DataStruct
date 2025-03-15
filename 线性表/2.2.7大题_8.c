#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 向链表中添加元素
void Append(LinkList L, int x)
{
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = NULL;

    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
}

// 打印链表中的所有元素
void PrintList(LinkList L)
{
    LNode *p = L->next; // Skip the header node
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int InitList(LinkList *L)
{
    *L = (LNode *)malloc(sizeof(LNode));

    (*L)->next = NULL;
    return 1;
}
// 用两链表公共值组成新链表
LinkList searchPublicValue(LinkList A,LinkList B){
    if (A==NULL||B==NULL)
    {
        return 0;
    }
    LinkList C = (LNode*)malloc(sizeof(LNode));
    C->next = NULL;
    LNode *pa = A->next;
    LNode *pb = B->next;
    LNode *pc = C;
    while (pa!=NULL&&pb!=NULL)
    {
        if (pa->data<pb->data)
        {
            pa = pa->next;
        }
        if (pa->data>pb->data)
        {
            pb = pb->next;
        }
        if (pa->data==pb->data)
        {
            LNode *s = (LNode*)malloc(sizeof(LNode));
            s->data = pa->data;
            pc->next = s;
            pc = pc->next;
            pa = pa->next;
            pb = pb->next;
        }
    }
    pc->next = NULL;
    return C;
}



int main()
{
    LinkList A = NULL;
    LinkList B = NULL;
    InitList(&A);
    InitList(&B);
    Append(A, 5);
    Append(A, 10);
    Append(A, 11);
    Append(A, 15);
    Append(A, 20);
    Append(A, 20);

    Append(B, 5);
    Append(B, 9);
    Append(B, 10);
    Append(B, 15);

    printf("original List\n");
    PrintList(A);
    PrintList(B);
    LinkList C = searchPublicValue(A,B);
    printf("After deleteing\n");
    PrintList(C);
    return 0;
}
