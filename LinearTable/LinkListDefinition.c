#include<stdio.h>

#define MAXSIZE 10
// ������ṹ��
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// ��̬����ṹ��
typedef struct Node
{
    int data;
    int next;
}SLinkList[MAXSIZE];//����ÿ���ڵ�

// ˫����ṹ��
typedef struct DNode{
    int data;
    DNode *next;
    DNode *prior;
}DNode,*DLinkList;

// ��̬������
int initStaticList(SLinkList L){

    for (int i = 0; i < MAXSIZE; i++)
    {
        L[i].data = -2;//�����нڵ��next��Ϊ-2,��ζ�ſ�
    }
    L->next = -1;//����ָ���˱�β,������NULL
}

// ��������
//����ͷ�ڵ�----��ָ���next��ָ��Ŀռ���ǵ�һ���ڵ�
//�ձ��ж�L == NULL
int InitLinkList(LinkList L){
    L->next = NULL;
    return 0;
}

// ��������
//��ͷ�ڵ�------ͷ�ڵ��data����Ϊ��--ͷ�ڵ��nextָ���һ���ڵ�----ͷ�ڵ�ֻ��Ϊ����ĳЩ�������ӷ���
//�ձ��ж�L->next == NULL
int InitLinkList2(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L==NULL)
    {
        printf("�ڴ����ʧ��\n");
        return 0;
    }
    L->next = NULL;
    return 1;
}

// ѭ��������
int InitCircularSingleList(LinkList L){
    L = (LNode*)malloc(sizeof(LNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//ѭ���������ʼ��ʱ��nextָ��ͷ�ڵ�
    return 1;
}

// ѭ��˫����
int InitCircularDoubleList(DLinkList L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//ѭ��˫�����ʼ��ʱ��next��priorָ��ͷ�ڵ�
    L->prior = L; 
    return 1;
}

// ѭ���������п�
int empty(LinkList L){
    if (L->next == L)//ѭ�������ж��Ƿ�Ϊ��,���ж�ͷ�ڵ��next�Ƿ�Ϊ�Լ�
    {
        return 1;
    }
    return 0;
}

// ѭ���������ж�β�ڵ�
int isTail(LinkList L,LNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}

// ѭ��˫�����п�
int empty(DLinkList L){
    if (L->next == L)//ѭ�������ж��Ƿ�Ϊ��,���ж�ͷ�ڵ��next�Ƿ�Ϊ�Լ�
    {
        return 1;
    }
    return 0;
}

// ѭ��˫�����ж�β�ڵ� 
int isTail(DLinkList L,DNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}

int main(){
    LinkList L;
    LinkList L2;
    InitLinkList(L);
    InitLinkList2(L2);
}