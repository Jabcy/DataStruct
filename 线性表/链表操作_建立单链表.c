#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

/*
    ʹ��ͷ�巨����������������˳�������
    ����:1,2,3,4,5
    ͷ�巨����:ͷ�ڵ�,5,4,3,2,1,NULL
    ������ʵ�ֶ�ĳ�����Ա������
*/ 

// β�巨
LinkList TailInsert(LinkList L)
{
    int x;                              // ���ڴ洢���������
    L = (LNode *)malloc(sizeof(LNode)); // ����ͷ�ڵ�
    LNode *s, *r = L;                   // �����½����Ľڵ�ָ���뵥�����βָ��,����βָ��һ��ʼָ��ͷ�ڵ�
    scanf("%d", &x);                    // �����һ���ڵ�����
    while (x != 9999)                   // ��������9999ʱ����
    {
        s = (LNode *)malloc(sizeof(LNode)); // �����½ڵ�
        s->data = x;                        // �����ݴ����½ڵ�
        r->next = s;                        // ���½ڵ�ӵ�β�ڵ�ĺ���
        r = s;                              // ����β�ڵ��λ��Ϊ�½ڵ�
        scanf("%d", &x);                    // ������һ���ڵ�����
    }
    r->next = NULL; // ��β�ڵ��next��ΪNULL
    return L;
}
// ͷ�巨
LinkList HeadInsert(LinkList L)
{
    int x;                              // ���ڴ洢���������
    L = (LNode *)malloc(sizeof(LNode)); // ����ͷ�ڵ�
    LNode *s;                           // �����½����Ľڵ�ָ��
    L->next = NULL;                     // ��ʼ��ͷ�ڵ��nextΪNULL
    scanf("%d", &x);                    // �����һ���ڵ�����
    while (x != 9999)                   // ��������9999ʱ����
    {                                       
        s = (LNode *)malloc(sizeof(LNode)); // �����½ڵ�
        s->data = x;                        // �����ݴ����½ڵ�
        s->next = L->next;                  // ���½ڵ���뵽ͷ�ڵ�֮��
        L->next = s;                        // ����ͷ�ڵ��nextָ���²���Ľڵ�
        scanf("%d", &x);                    // ������һ���ڵ�����
    }
    return L; // �����ѹ����õ������ͷָ��
}

// �´���һ������,����������������ô������������
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