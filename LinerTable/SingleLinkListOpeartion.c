#include <stdio.h>
// ������ṹ�嶨��
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// ������λ��ѯ 
LNode* SearchNodeByBit(LinkList L,int i){
    if (i<1)
    {
        return NULL;
    }
    
    LNode *p;
    p = L;
    int j = 0;
    while (p!=NULL&&j<i)
    {
        p = p->next;
        j++;
    }
    // if (p==NULL)
    // {
    //     return NULL;
    // }
    // �����ж��Ƿ�ΪNULL,������Ҫ����,��ȷ�ͷ��ؽ��,����ͷ���NULL
    return p;
}//ʱ�临�Ӷ�O(n)

// ������ֵ��ѯ
int SearchNodeByValue(LinkList L,int e){
    
    LNode *p;
    p = L->next;
    while (p!=NULL&&p->data!=e)
    {
        p = p->next;
    }
    // if (p==NULL)
    // {
    //     return NULL;
    // }
    // �����ж��Ƿ�ΪNULL,������Ҫ����,��ȷ�ͷ��ؽ��,����ͷ���NULL
    return p;
}//ʱ�临�Ӷ�O(n)

// β�巨����������
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

// ͷ�巨����������
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

// ��ȡ�������
int GetLength(LinkList L)
{
    LNode *p;
    p = L;
    int len = 0;
    while (p != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
}

// ɾ��ĳ���ڵ�
int Delete(LinkList L,int i ,int *e){
    if (i<1)
    {
        return 0;
    }
    int j = 0;
    LNode *p,*q;
    p = L;
    while (p!=NULL&&j<i-1)
    {
        p = p->next;
        j++;
    }
    if (p==NULL)
    {
        return 0;
    }
    
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 1;
}//ʱ�临�Ӷ�O(1)
// ��ʱ��δ����ͷ�ڵ�,Ҳ���޷���ȡҪɾ���ڵ��ǰ���ڵ�,��ô�ͽ���̽ڵ�����ݸ���Ҫɾ���ڵ�,֮��ɾ����̽ڵ�

// �򲻴�ͷ�ڵ�������е�i��λ�ò���ڵ�
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

// �����ͷ�ڵ�������е�i��λ�ò���ڵ�
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

// ��ĳ���ڵ�����ڵ�
int Insert(LNode *L, int e){
    if (L==NULL)
    {
        return 0;
    }
    
    LNode *p;
    p =(LNode *)malloc(sizeof(LNode));
    if (p==NULL)
    {
        return 0;
    }
    
    p->data = e;
    p->next = L->next;
    L->next = p;
    return 1;
}

// ��ĳ���ڵ�ǰ����ڵ�
int Insert(LNode *q, int e){
    if (q==NULL)
    {
        return 0;
    }
    
    LNode *p;
    p =(LNode *)malloc(sizeof(LNode));
    if (p==NULL)
    {
        return 0;
    }
    
    p->data = e;
    p->next = q->next;
    q->next = p;
    int temp = q->data;
    q->data = p->data;
    p->data = temp;
    
    return 1;
}

int main()
{
    LinkList L;
    InitLinkList2(L);
    
    return 0;
}
