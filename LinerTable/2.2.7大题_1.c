#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int InitList(LinkList *L){
    *L = (LNode*)malloc(sizeof(LNode));

    (*L)->next = NULL;
    return 1;
}

int deleteNode(LinkList L,int x){
    if (L->next==NULL)
    {
        return 0;
    }
    LNode *p = L;
    while (p->next!=NULL)
    {
        if (p->next->data==x)
        {
            LNode *s = p->next;
            p->next = s->next;
            free(s);
        }
        
        p = p->next;
    }
    return 1;
}


// �����������Ԫ��
void Append(LinkList L, int x) {
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = x;
    newNode->next = NULL;
    
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

// ��ӡ�����е�����Ԫ��
void PrintList(LinkList L) {
    LNode *p = L->next; // Skip the header node
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main()
{
    int x = 10;
    LinkList L = NULL;
    InitList(&L);
     // ���һЩԪ�ص�������
     Append(L, 5);
     Append(L, 10);
     Append(L, 15);
     Append(L, 10);
     Append(L, 20);
 
     printf("Original list:\n");
     PrintList(L);
 
     // ɾ��ֵΪ10�����нڵ�
     deleteNode(L, x);
 
     printf("After deleting nodes with value 10:\n");
     PrintList(L);
 
    return 0;
}
