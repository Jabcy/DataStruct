#include<stdio.h>
#include<stdbool.h>
// ����ջ���������
#define MAXSIZE 10
// ����Ԫ������
typedef int ElemType;
// ջ�ṹ�嶨��
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

// ����ջ�ṹ�嶨��
typedef struct{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}ShStack; 




// ��ʼ��ջ
void initStack(SqStack *S){
    (*S).top = -1;
};

// ��ʼ������ջ
void initShStack(ShStack *S){
    (*S).top1 = -1;
    (*S).top2 = MAXSIZE;
}

// ����ջ
void destroyStack(SqStack *S){
    (*S).top = -1;
}

// ��ջ
bool push(SqStack *S,ElemType x){
    if ((*S).top == MAXSIZE-1)    return false;// ջ��
    (*S).top++;
    (*S).data[(*S).top] = x;
    return true;
}

// ��ջ
bool pop(SqStack *S,ElemType *x){
    if ((*S).top == -1)     return false;// ջ��
    *x = (*S).data[(*S).top];
    (*S).top--;
    return true;
}

// ��ȡջ��Ԫ��
bool getTop(SqStack S,ElemType *x){
    if(S.top == -1)      return false;
    *x = S.data[S.top];
    return true;
}



int main()
{
    ElemType x;
    SqStack S;
    initStack(&S);
    push(&S,1);
    push(&S,2);
    push(&S,3);
    push(&S,4);
    push(&S,5);
    pop(&S,&x);
    printf("%d\n",x);
    getTop(S,&x);
    printf("%d\n",x);
    return 0;
}
