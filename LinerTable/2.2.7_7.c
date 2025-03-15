#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// �����������Ԫ��
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

// ��ӡ�����е�����Ԫ��
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
// ɾ�����������ظ�ֵ
int deletePublicateValue(LinkList L){
    if (L->next == NULL)
    {
        return 0;
    }
    LNode *head = L;
    LNode *current = L->next;
    LNode *prev = head;
    while (current != NULL)
    {
        if (current->data == prev->data)
        {
            prev->next = current->next;
            free(current);
            current = prev;
        }
        prev = current;
        current = current->next;
        
        
    }
    return 1;

}



int main()
{
    LinkList L = NULL;
    InitList(&L);
    Append(L, 5);
    Append(L, 10);
    Append(L, 10);
    Append(L, 15);
    Append(L, 20);
    Append(L, 20);
    printf("original List\n");
    PrintList(L);
    deletePublicateValue(L);
    printf("After deleteing\n");
    PrintList(L);
    return 0;
}
