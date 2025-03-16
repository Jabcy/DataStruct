#include<stdio.h>
#include<stdlib.h>

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;


// �����������Ԫ��
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

// ��ӡ�����е�����Ԫ��
void PrintList(LinkList L)
{
    if (L->next == L) { // �������Ϊ�գ�ֻ��ͷ�ڵ㣩
        printf("����Ϊ��\n");
        return;
    }
    LNode *p = L->next; // ����ͷ�ڵ㿪ʼ��ӡ����
    do {
        printf("%d -> ", p->data);
        p = p->next;
    } while (p != L); // ���ص�ͷ�ڵ�ʱֹͣ
    printf("...\n"); // ��ʾѭ������
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
    
    // ��B�������ӵ�A����󣬲��ͷ�B��ͷ�ڵ�
    tailA->next = B->next;
    tailB->next = A;
    free(B); // �ͷ�ԭ����B����ͷ�ڵ�
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
