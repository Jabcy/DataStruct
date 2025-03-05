#include<stdio.h>

typedef struct{
    int data;
    struct LNode *next;
}LNode,*LinkList;

//不带头节点----此指针的next所指向的空间就是第一个节点
//空表判断L == NULL
int InitLinkList(LinkList L){
    L->next = NULL;
    return 0;
}

//带头节点------头节点的data保持为空--头节点的next指向第一个节点----头节点只是为了让某些操作更加方便
//空表判断L->next == NULL
int InitLinkList2(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));
    if (L==NULL)
    {
        printf("内存分配失败\n");
        return 0;
    }
    L->next = NULL;
    return 1;
}

int main(){
    LinkList L;
    LinkList L2;
    InitLinkList(L);
    InitLinkList2(L2);
}