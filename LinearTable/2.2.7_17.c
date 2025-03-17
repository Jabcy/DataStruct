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



// ���ҵ�����k���ڵ�
int searchkthFormBottom(LNode* list,int k){
    if (list==NULL)
    {
        return 0;
    }

    int x =k;
    LNode *current = list;
    LNode *tail = list;
    while (tail!=NULL&&k!=0)
    {
        tail = tail->next;
        k--;
    }if (k!=0)
    {
        return 0;
    }
    
    while (tail!=NULL)
    {
        current = current->next;
        tail = tail->next;
    }

    printf("������%d����%d",x,current->data);
    return 1;

}


int main()
{
    LinkList A = NULL;

    InitList(&A);

    Append(A, 5);
    Append(A, 10);
    Append(A, 11);
    Append(A, 15);
    Append(A, 20);
    Append(A, 20);

    PrintList(A);
    searchkthFormBottom(A,3);
    
    return 0;
}
