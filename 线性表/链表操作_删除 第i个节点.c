#include <stdio.h>

typedef struct
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
// 删除某个节点
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
}//时间复杂度O(1)
// 有时并未给出头节点,也就无法获取要删除节点的前驱节点,那么就将后继节点的数据赋给要删除节点,之后删除后继节点
int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
