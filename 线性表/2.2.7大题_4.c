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

int deleteMidNode(LinkList L ,int min ,int max)
{
    while (L->next==NULL)
    {
        return 0;
    }
    
    LNode *head = L;
    LNode *current = head->next;
    LNode *prev = head;

    while (current != NULL)
    {
        if (current->data<max&&current->data>min)
        {
            prev->next = current->next;
            free(current);
            current = prev;
        }
        prev = current;
        current = prev->next;
    }
    

    return 1;
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
    deleteMidNode(L,10,17);
    printf("After deleteing\n");
    PrintList(L);
    return 0;
}
