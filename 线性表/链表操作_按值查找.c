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
    // 不用判断是否为NULL,反正都要返回,正确就返回结果,错误就返回NULL
    return p;
}//时间复杂度O(n)


int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
