#include <stdio.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

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


int main()
{
    LinkList L;
    InitLinkList2(L);
    
    return 0;
}
