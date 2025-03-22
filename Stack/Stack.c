#include<stdio.h>
#include<stdbool.h>
// 定义栈的最大容量
#define MAXSIZE 10
// 定义元素类型
typedef int ElemType;
// 栈结构体定义
typedef struct{
    ElemType data[MAXSIZE];
    int top;
}SqStack;

// 共享栈结构体定义
typedef struct{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
}ShStack; 




// 初始化栈
void initStack(SqStack *S){
    (*S).top = -1;
};

// 初始化共享栈
void initShStack(ShStack *S){
    (*S).top1 = -1;
    (*S).top2 = MAXSIZE;
}

// 销毁栈
void destroyStack(SqStack *S){
    (*S).top = -1;
}

// 入栈
bool push(SqStack *S,ElemType x){
    if ((*S).top == MAXSIZE-1)    return false;// 栈满
    (*S).top++;
    (*S).data[(*S).top] = x;
    return true;
}

// 出栈
bool pop(SqStack *S,ElemType *x){
    if ((*S).top == -1)     return false;// 栈空
    *x = (*S).data[(*S).top];
    (*S).top--;
    return true;
}

// 读取栈顶元素
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
