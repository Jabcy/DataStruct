#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct ThreadNode
{
    Elemtype data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;// ��tagֵΪ0ʱ����ʾָ��ָ���ӣ���tagΪ1ʱ����ʾtag������
}ThreadNode,*ThreadTree;

// ȫ�ֱ���
ThreadNode *pre;


// ǰ���С����������������
// �и�©�����������һ���ڵ�ʱ��preҲ��ָ�����һ���ڵ㣬�����һ���ڵ��������ָ�뻹ûָ��
// ���ȷ�������Ϊpre��ȫ�ֱ��������Կ����������������ֶ���pre��rtag
// ��������һ�㺯�����������ж��Ƿ�Ϊ���ڵ㣬����ǣ����ֶ�����
void createInThread(ThreadTree T){
    pre = NULL;
    if (T!=NULL)
    {
        inThread(T);
        if (pre->rchild==NULL)//�������������������Ҫ�жϣ���ǰ��ͺ�����Ҫ�����Խ��˺�����Ϊ��ͬ��������������ͨ���޸�inThread�ĵݹ�˳�����ı�
        {
            pre->rtag = 1; 
        }
    }
}


// ��һ��ǰ�������������
//��������ǰ�������ʱ�����ܳ�����visit�н�һ���ڵ������ָ��ָ��������ǰ��ǰ������ôpreThread�Ͳ����ڷ���T�������ˣ�������������ѭ��
// ֻ��ǰ���ݹ���뵽�Ѿ����������Ľڵ㣬����
/*
         A
        / 
       B   
*/
// ������A->�ݹ����B,������B,����B����ָ����Ϊ������ָ����A,���Կ��Ե���,�ݹ����A,������A......����ѭ��


void preThread(ThreadTree T){
    if (T!=NULL)
    {
        visit(T);
        if (T->ltag == 0)        {
            preThread(T->lchild);
        }
        preThread(T->rchild);
    }
}



// ��һ�����������������
void inThread(ThreadTree T){
    if(T!=NULL){
        inThread(T->lchild);
        visit(T);
        inThread(T->rchild);
    }
}

// ��һ�����������������
void postThread(ThreadTree T){
    if (T!=NULL)
    {
        postThread(T->lchild);
        postThread(T->rchild);
        visit(T);
    }
    
}

// ����������
void visit(ThreadNode *q){
    if (q->lchild==NULL)
    {
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre!=NULL&&pre->rchild==NULL)
    {
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}



// ����һ����������Ľڵ�,Ѱ����������
// ���ýڵ���������������½ǵĽڵ�,��ýڵ�ĺ������ָ��Ľڵ�
ThreadNode *nextNode(ThreadNode *p){
    if(p->rtag == 0){ return firstNode(p->rchild);}
    else return p->rchild;
}
// ����һ�������ĸ�,��������������ĵ�һ���ڵ�
// ���������������½ǵĽڵ�
ThreadNode *firstNode(ThreadNode *p){
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}
// �Ը������������������������������(��ʹ�õݹ�)
// ��Ϊͨ�������������������ҵ�����һ���ڵ�ĺ��,��ôֻҪ������һ���ڵ�,��ô��֪�������к��,�������������
void inOrder(ThreadNode *T){
    ThreadNode *p = firstNode(T);//��ȡ�ö����������½ǵĽڵ�,������������еĵ�һ���ڵ�
    for(;p!=NULL;p=nextNode(p))
        get(p);
}





// ����һ����������Ľڵ�,����������ǰ��
// �����ظýڵ��������������½ǵĽڵ�,��ýڵ��ǰ������ָ��Ľڵ�
ThreadNode *preNode(ThreadNode *p){
    if(p->ltag == 0 ){return lastNode(p);}
    else return p->lchild;
}
// ����һ������,������������������һ���ڵ�
// ���������������½ǵĽڵ�
ThreadNode *lastNode(ThreadNode *p){
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    return p;
}
// �Ը�����������������������(��ʹ�õݹ�)
void revInOrder(ThreadTree T){
    ThreadNode *p = lastNode(T);//��ȡ�ö����������½ǵĽڵ�,������������е����һ���ڵ�
    for (;p!=NULL;p = preNode(p))
        get(p);
}