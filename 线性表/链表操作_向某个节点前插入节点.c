#include <stdio.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// ��Ϊ�������޷�Ѱ��ĳ���ڵ��ǰ���ڵ�,�������ַ�ʽʵ��
// ����һ:��������ʱ����������ͷ�ڵ�ָ��,�Ӷ�Ѱ�Ҹýڵ��ǰ���ڵ�,ʱ�临�Ӷ�O(n)
// ������:�������뵽�ýڵ�ĺ���,֮�󽫸ýڵ������ڵ�����ݻ���,�Ӷ�����ʵ�ֲ���ǰ���ڵ�,ʱ�临�Ӷ�O(1)

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
