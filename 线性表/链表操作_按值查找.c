#include <stdio.h>

typedef struct
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

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


int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
