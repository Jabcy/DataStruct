#include <stdio.h>

typedef struct
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
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
int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
