#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode* next;
}LinkNode;

typedef struct Queue
{
    LinkNode *front,*rear;
}*LinkQueue;

// 初始化
void initQueue(LinkQueue *Q){
    *Q = (LinkQueue)malloc(sizeof(struct Queue));
    (*Q)->front = NULL;
    (*Q)->rear = NULL;
}

// 判空
bool isEmpty(LinkQueue Q){
    return Q->front==NULL;
}

// 入队
bool enqueue(LinkQueue *Q,ElemType x){
    LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));
    if(newnode == NULL){return false;}
    newnode->data = x;
    newnode->next =NULL;
    if (isEmpty(*Q))
    {

        (*Q)->front = newnode;
        (*Q)->rear = newnode;

    }else{
        (*Q)->rear->next = newnode;
        (*Q)->rear = newnode;
    }
    return true;
}

// 出队
bool dequeue(LinkQueue *Q,ElemType *x){
    if(isEmpty(*Q)){return false;}
    LinkNode *p;
    p = (*Q)->front;
    *x = p->data;
    (*Q)->front = p->next;//只剩一个节点时，让其指向NULL，剩余多个节点时，让其指向下一个
    if (p == (*Q)->rear)
    {
        (*Q)->rear = NULL;
    }
    free(p);
    return true;
}



int main()
{  
    LinkQueue Q;
    initQueue(&Q); 
    printf("%d\n", isEmpty(Q));
    enqueue(&Q,1);
    enqueue(&Q,2);
    enqueue(&Q,3);
    enqueue(&Q,4);
    enqueue(&Q,5);
    ElemType x,y,z;
    dequeue(&Q,&x);
    dequeue(&Q,&y);
    dequeue(&Q,&z);
    printf("%d->%d->%d\n",x,y,z);
    return 0;
}