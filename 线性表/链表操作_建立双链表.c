#include<stdio.h>
#include<stdlib.h>

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

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

// ˫�����������,��ĳ�����ݽڵ�ָ��
int ShowDLinkListPrior(DNode *p){
    while (p->prior!=NULL)
    {
        printf("%d",p->data);
        p = p->prior;
    }
    
}

int main(){
    DLinkList L;
    InitDLinkList(L);
}