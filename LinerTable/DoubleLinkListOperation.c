#include<stdio.h>
#include<stdlib.h>
// ˫����ṹ�嶨��
typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

// ˫�����ʼ��
int InitDLinkList(DLinkList L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
    {
        return 0;
    }//�ڴ����ʧ��

    L->next = NULL;
    L->prior = NULL;

    return 0;
}

// ˫�����������,��ĳ�����ݽڵ�
// ����Ҫ����ĳ��λ��Ľڵ�,��ʹ��һ��������i++
int ShowDLinkListBack(DNode *p){
    while (p!=NULL)
    {
        printf("%d",p->data);
        p = p->next;
    }
}

// ˫�������ǰ����,��ĳ�����ݽڵ�ָ��
int ShowDLinkListPrior(DNode *p){
    while (p->prior!=NULL)
    {
        printf("%d",p->data);
        p = p->prior;
    }
    
}

// ��������˫����Ľڵ�,��q���뵽p�ڵ�֮��
int Insert(DNode *p,DNode *q){
    if (p==NULL||q==NULL)
    {
        return 0;
    }
    
    q->next = p->next;
    if(p->next != NULL){
        p->next->prior = q;
    }
    q->prior = p;
    p->next = q;
} 

// ɾ��p�ڵ�֮���q�ڵ�,ֻ��p�ڵ�
int Delete(DNode *p)
{
    if (p == NULL)
    {
        return 0;
    }
    DNode *q = p->next;
    p->next = q->next;
    if (p->next != NULL)
    {
        q->next->prior = p;
    }
    free(q);
    return 0;
}

// ɾ��һ��˫����
int DestoryList(DLinkList L){
    while (L->next)
    {
        Delete(L);
    }
    free(L);
    return 0;
}

// ѭ��˫�����ʼ��
int InitList(DLinkList L){
    L = (DNode*)malloc(sizeof(DNode));
    if (L==NULL)
    {
        return 0;
    }
    L->next = L;//ѭ��˫�����ʼ��ʱ��next��priorָ��ͷ�ڵ�
    L->prior = L; 
    return 1;
}

// ѭ��˫�����п�
int empty(DLinkList L){
    if (L->next == L)//ѭ�������ж��Ƿ�Ϊ��,���ж�ͷ�ڵ��next�Ƿ�Ϊ�Լ�
    {
        return 1;
    }
    return 0;
}

// ѭ��˫�������
int insertNextDNode(DNode *p,DNode *q){
    if (p==NULL||q==NULL)
    {
        return 0;
    }
    
    q->next = p->next;
    p->next->prior = q;
    p->next = q;
    q->prior = p;
    return 1;
}

// ѭ��˫�����ж�β�ڵ�
int isTail(DLinkList L,DNode *p){
    if (p->next==L)
    {
        return 1;
    }
    return 0;
}

// ѭ��˫����ɾ��
int deleteDNode(DNode *p){
    if (p==NULL)
    {
        return 0;
    }
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return 1;
}

int main(){
    DLinkList L;
    InitDLinkList(L);
}