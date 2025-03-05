#include <stdio.h>

typedef struct
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

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
// 获取表长,时间复杂度O(n)

int main()
{
    LinkList L;
    InitLinkList2(L);

    return 0;
}
