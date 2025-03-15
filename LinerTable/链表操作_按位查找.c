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
    // 不用判断是否为NULL,反正都要返回,正确就返回结果,错误就返回NULL
    return p;
}//时间复杂度O(n)


int main()
{
    LinkList L;
    InitLinkList2(L);
    
    return 0;
}
