#include <stdio.h>

typedef struct LNode
{
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
// ���벻��ͷ�ڵ������
int InsertList(LinkList L,int i,int e){
    
    if (i<1)
    {
        return 0;
        printf("����λ�򲻺Ϸ�\n");
    }
    LNode *p,*q;
    // for (int j = 0; j < i-1; j++)
    // {
    //     p = p->next;
    // }// ����pָ��i��ǰһ���ڵ�
    // ��forѭ����Ϊwhileѭ��,���Է�����ж��Ƿ�β�ڵ�
    
    // ��һ���ڵ�Ҫ���⴦��
    if (i == 1)
    {   
        q = (LNode *)malloc(sizeof(LNode));
        if (q == NULL)
        {
            return 0;
        }
        
        q->data = e;
        q->next = L->next;
        L->next = q;
        return 1;
    }

    // ����һ���ڵ���Ľڵ㴦���߼�
    int j = 1;
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        printf("����λ����ڱ�+1,���Ϸ�,����ʧ��\n");
        return 0;
    }
    q = (LNode*)malloc(sizeof(LNode));
    if (q==NULL)
    {
        return 0;
    }
    
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 0;
}


// �������ͷ�ڵ������
int InsertList2(LinkList L,int i,int e){
    
    if (i<1)
    {
        return 0;
        printf("����λ�򲻺Ϸ�\n");
    }

    LNode *p,*q;
    int j=0;
    p = L;
    // for (int j = 0; j < i-1; j++)
    // {
    //     p = p->next;
    // }// ����pָ��i��ǰһ���ڵ�
    // ��forѭ����Ϊwhileѭ��,���Է�����ж��Ƿ�β�ڵ�
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        printf("����λ����ڱ�+1,���Ϸ�,����ʧ��\n");
        return 0;
    }
    q = (LNode*)malloc(sizeof(LNode));
    if (q==NULL)
    {
        return 0;
    }
    
    q->data = e;
    q->next = p->next;
    p->next = q;
    return 0;
}


int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
