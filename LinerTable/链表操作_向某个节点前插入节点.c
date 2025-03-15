#include <stdio.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;

// 因为单链表无法寻找某个节点的前驱节点,故有两种方式实现
// 方法一:函数传参时传入此链表的头节点指针,从而寻找该节点的前驱节点,时间复杂度O(n)
// 方法二:正常插入到该节点的后面,之后将该节点与插入节点的数据互换,从而另类实现插入前驱节点,时间复杂度O(1)

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
