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

// 初始化，将头尾指针都指向头节点
void initQueue(LinkQueue *Q){
    *Q = (LinkQueue)malloc(sizeof(struct Queue));
    (*Q)->front = (LinkNode*)malloc(sizeof(LinkNode));
    if((*Q)->front==NULL){printf("内存分配失败\n");}
    (*Q)->rear = (*Q)->front;
    (*Q)->front->next = NULL;
}

// 判空,头尾指针相等，即同时指向头节点
bool isEmpty(LinkQueue Q){
    return Q->front==Q->rear;
}



// 入队
bool enqueue(LinkQueue Q,ElemType x){
    LinkNode *newnode = (LinkNode*)malloc(sizeof(LinkNode));
    if(newnode == NULL){return false;}
    newnode->data = x;
    newnode->next = NULL;
    Q->rear->next = newnode;
    Q->rear = newnode;
    return true;
}


// 出队
bool dequeue(LinkQueue Q,ElemType *x){
    if(isEmpty(Q)){return false;}
    LinkNode *p;
    p = Q->front->next;
    Q->front->next = p->next;
    *x = p->data;
    if(p ==Q->rear){Q->rear = Q->front;}
    free(p);
    return true;
}





int main()
{  
    LinkQueue Q;
    initQueue(&Q); 
    printf("%d\n", isEmpty(Q));
    enqueue(Q,1);
    enqueue(Q,2);
    enqueue(Q,3);
    enqueue(Q,4);
    enqueue(Q,5);
    ElemType x,y,z;
    dequeue(Q,&x);
    dequeue(Q,&y);
    dequeue(Q,&z);
    printf("%d->%d->%d\n",x,y,z);
    return 0;
}