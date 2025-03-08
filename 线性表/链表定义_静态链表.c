#include<stdio.h>

#define MAXSIZE 10

typedef struct Node
{
    int data;
    int next;
}SLinkList[MAXSIZE];//定义每个节点


int initList(SLinkList L){

    for (int i = 0; i < MAXSIZE; i++)
    {
        L[i].data = -2;//将所有节点的next设为-2,意味着空
    }
    L->next = -1;//代表指向了表尾,类似于NULL
}





int main()
{
    struct Node a[MAXSIZE];//建立了以节点为基本元素的数组作为静态链表,此写法看起来像是定义了一个Node型数组,
    SLinkList b;//此写法类似于链表的LNode与*LinkList的区别,用于在视觉上表现是静态链表,此写法看起来像直接定义了一个静态链表
    return 0;
}

