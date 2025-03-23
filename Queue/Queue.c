#include<stdio.h>
#include<stdbool.h>

#define MAXSIZE 10

typedef int ElemType;

typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}*SqQueue;

// ��ʼ��
void initQueue(SqQueue Q){
    Q->front = 0;
    Q->rear = 0;
}

// �п�
bool queueEmpty(SqQueue Q){
    return Q->front==Q->rear; 
}
// ����
bool queueFull(SqQueue Q){
    return (Q->rear+1)%MAXSIZE == Q->front;
}

// ���
bool enQueue(SqQueue Q,ElemType x){
    if (queueFull(Q)) return false;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear+1)%MAXSIZE;
    return true; 
}

// ����
bool deQueue(SqQueue Q,ElemType *x){
    if(queueEmpty) return false;
    *x = Q->data[Q->front];
    Q->front = (Q->front+1)%MAXSIZE;
    return true; 
}

// ��ȡ��ͷԪ��
bool getQueue(SqQueue Q,ElemType *x){
    if(queueEmpty) return false;
    *x = Q->data[Q->front];
}

// ��ȡ���г���
int getLength(SqQueue Q){
   return (Q->rear+MAXSIZE-Q->front)%MAXSIZE; 
}

int main()
{
    SqQueue Q;
    initQueue(&Q);
    
    return 0;
}
