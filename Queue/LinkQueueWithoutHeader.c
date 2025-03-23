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

// ��ʼ��
void initQueue(LinkQueue *Q){
    *Q = (LinkQueue)malloc(sizeof(struct Queue));
    (*Q)->front = NULL;
    (*Q)->rear = NULL;
}

// �п�
bool isEmpty(LinkQueue Q){
    return Q->front==NULL;
}

// ���
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

// ����
bool dequeue(LinkQueue *Q,ElemType *x){
    if(isEmpty(*Q)){return false;}
    LinkNode *p;
    p = (*Q)->front;
    *x = p->data;
    (*Q)->front = p->next;//ֻʣһ���ڵ�ʱ������ָ��NULL��ʣ�����ڵ�ʱ������ָ����һ��
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