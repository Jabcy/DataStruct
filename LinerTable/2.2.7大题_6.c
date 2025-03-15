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
// 分离奇偶链表
int spiltLinkList(LinkList L,LinkList *A,LinkList *B){
    if (L->next == NULL)
    {
        return L;
    }

    (*A) = (LNode*)malloc(sizeof(LNode));
    (*B) = (LNode*)malloc(sizeof(LNode));
    LNode *current = L->next;
    LNode *pa = *A,*pb = *B;
    int num =1;
    while (current != NULL)
    {
        if (num %2 == 1)
        {
            pa->next = current;
            pa = pa->next;
        } 
        else
        {
            pb->next = current;
            pb = pb->next;
        }
        current = current->next;
        num++;
    }
    pa->next = NULL;
    pb->next = NULL;
    
}



int main()
{
    LinkList L = NULL;
    InitList(&L);
    Append(L, 5);
    Append(L, 10);
    Append(L, 15);
    Append(L, 10);
    Append(L, 20);
    printf("original List\n");
    PrintList(L);
    LinkList A=NULL,B=NULL;
    spiltLinkList(L,&A,&B);
    printf("After deleteing\n");
    PrintList(A);
    PrintList(B);
    return 0;
}
