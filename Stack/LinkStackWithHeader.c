#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;
// 定义链栈结构体变量
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkStack;

// 初始化链栈
void initStack(LinkStack *S){
    *S = (LinkNode *)malloc(sizeof(LinkNode));
    (*S)->next = NULL;
}

// 入栈 
bool push(LinkStack S){
    ElemType x;
    LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));
    newnode->next = S->next;
    scanf("%d",&x);
    newnode->data = x;
    S->next = newnode;
    return true;
}

// 出栈
bool pop(LinkStack S,ElemType *x){
    if(S->next == NULL) return false;
    *x = S->next->data;
    LinkNode *p = S->next;
    S->next = p->next;
    free(p);
    return true;
}

// 获取栈顶元素
bool getTop(LinkStack S ,ElemType *x){
    if (S->next == NULL)    return false;
    *x = S->next->data;
    return true;
}


int main()
{
    LinkStack S;
    initStack(&S);
    push(S);
    int x;
    getTop(S,&x);
    printf("%d\n",x);
    int y;
    pop(S,&y);
    printf("%d\n",y);
    return 0;
}
