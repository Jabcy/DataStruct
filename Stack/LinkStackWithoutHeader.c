#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;
// ������ջ�ṹ�����
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkStack;

// ��ʼ����ջ
void initStack(LinkStack *S){
    (*S) = NULL;
}

// ��ջ 
bool push(LinkStack *S){
    ElemType x;
    LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));
    newnode->next = *S;
    scanf("%d",&x);
    newnode->data = x;
    *S = newnode;
    return true;
}

// ��ջ
bool pop(LinkStack S,ElemType *x){
    if(S == NULL) return false;
    *x = S->data;
    LinkNode *p = S;
    S = p->next;
    free(p);
    return true;
}

// ��ȡջ��Ԫ��
bool getTop(LinkStack S ,ElemType *x){
    if (S == NULL)    return false;
    *x = S->data;
    return true;
}


int main()
{
    LinkStack S;
    initStack(&S);
    push(&S);
    int x;
    getTop(S,&x);
    printf("%d\n",x);
    int y;
    pop(S,&y);
    printf("%d\n",y);
    return 0;
}
