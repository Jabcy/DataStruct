#include<stdio.h>

typedef struct{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//����ͷ�ڵ�----��ָ���next��ָ��Ŀռ���ǵ�һ���ڵ�
//�ձ��ж�L == NULL
int InitLinkList(LinkList L){
    L->next = NULL;
    return 0;
}

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

int main(){
    LinkList L;
    LinkList L2;
    InitLinkList(L);
    InitLinkList2(L2);
}