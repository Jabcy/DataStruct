#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct ThreadNode
{
    Elemtype data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;// 当tag值为0时，表示指针指向孩子，当tag为1时，表示tag是线索
}ThreadNode,*ThreadTree;

// 全局变量
ThreadNode *pre;


// 前、中、后序二叉树线索化
// 有个漏洞，当到最后一个节点时，pre也会指向最后一个节点，但最后一个节点的右线索指针还没指定
// 补救方法：因为pre是全局变量，所以可以在其他函数中手动将pre的rtag
// 可以再套一层函数，其中来判断是否为最后节点，如果是，则手动处理
void createInThread(ThreadTree T){
    pre = NULL;
    if (T!=NULL)
    {
        inThread(T);
        if (pre->rchild==NULL)//中序二叉树线索化不需要判断，但前序和后序需要，可以将此函数作为共同的线索化函数，通过修改inThread的递归顺序来改变
        {
            pre->rtag = 1; 
        }
    }
}


// 将一个前序二叉树线索化
//在线索化前序二叉树时，可能出现在visit中将一个节点的左孩子指针指向了他的前序前驱，那么preThread就不能在访问T的左孩子了，否则将陷入无限循环
// 只有前序会递归进入到已经线索化过的节点，比如
/*
         A
        / 
       B   
*/
// 线索化A->递归进入B,线索化B,由于B的左指针因为线索化指向了A,所以可以调用,递归进入A,线索化A......无限循环


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



// 将一个中序二叉树线索化
void inThread(ThreadTree T){
    if(T!=NULL){
        inThread(T->lchild);
        visit(T);
        inThread(T->rchild);
    }
}

// 将一个后序二叉树线索化
void postThread(ThreadTree T){
    if (T!=NULL)
    {
        postThread(T->lchild);
        postThread(T->rchild);
        visit(T);
    }
    
}

// 进行线索化
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



// 给定一个线索化后的节点,寻找其中序后继
// 即该节点的右子树的最左下角的节点,或该节点的后继线索指向的节点
ThreadNode *nextNode(ThreadNode *p){
    if(p->rtag == 0){ return firstNode(p->rchild);}
    else return p->rchild;
}
// 给定一个子树的根,返回其中序遍历的第一个节点
// 即该子树中最左下角的节点
ThreadNode *firstNode(ThreadNode *p){
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}
// 对给定的中序线索二叉树进行中序遍历(不使用递归)
// 因为通过上面两个函数可以找到任意一个节点的后继,那么只要给出第一个节点,那么就知道其所有后继,即中序遍历序列
void inOrder(ThreadNode *T){
    ThreadNode *p = firstNode(T);//获取该二叉树最左下角的节点,即中序遍历序列的第一个节点
    for(;p!=NULL;p=nextNode(p))
        get(p);
}





// 给定一个线索化后的节点,返回其中序前驱
// 即返回该节点左子树的最右下角的节点,或该节点的前驱线索指向的节点
ThreadNode *preNode(ThreadNode *p){
    if(p->ltag == 0 ){return lastNode(p);}
    else return p->lchild;
}
// 给定一个子树,返回其中序遍历的最后一个节点
// 即该子树的最右下角的节点
ThreadNode *lastNode(ThreadNode *p){
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    return p;
}
// 对给定子树进行逆向的中序遍历(不使用递归)
void revInOrder(ThreadTree T){
    ThreadNode *p = lastNode(T);//获取该二叉树最右下角的节点,即中序遍历序列的最后一个节点
    for (;p!=NULL;p = preNode(p))
        get(p);
}