#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 10

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}*SqQueue;

// 初始化
void initQueue(SqQueue Q){
    Q->front = 0;
    Q->rear = 0;
}

// 判空
bool queueEmpty(SqQueue Q){
    return Q->front==Q->rear; 
}
// 判满
bool queueFull(SqQueue Q){
    return (Q->rear+1)%MAXSIZE == Q->front;
}

// 入队
bool enQueue(SqQueue Q,ElemType x){
    if (queueFull(Q)) return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return true; 
}

// 出队
bool deQueue(SqQueue Q,ElemType *x){
    if(queueEmpty) return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return true; 
}

// 获取对头元素
bool getQueue(SqQueue Q,ElemType *x){
    if(queueEmpty) return false;
    *x = Q->data[Q->front];
}

// 获取队列长度
int getLength(SqQueue Q){
   return (Q->rear+MAXSIZE-Q->front)%MAXSIZE; 
}

int main()
{
    SqQueue Q;
    initQueue(&Q);
    
    return 0;
}
