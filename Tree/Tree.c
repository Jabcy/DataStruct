#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

// 链式存储
typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode, *BiTree;

// 队列节点定义
typedef struct LinkNode {
    BiNode *data; // 存储二叉树节点指针
    struct LinkNode *next;
} LinkNode;

// 队列定义
typedef struct Queue {
    LinkNode *front, *rear;
} *LinkQueue;

// 初始化队列
void initQueue(LinkQueue *Q) {
    *Q = (LinkQueue)malloc(sizeof(struct Queue));
    (*Q)->front = (*Q)->rear = NULL;
}

// 判断队列是否为空
bool isEmpty(LinkQueue Q) {
    return Q->front == NULL;
}

// 入队
void enQueue(LinkQueue Q, BiNode *node) {
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = node;
    newNode->next = NULL;
    if (Q->rear == NULL) { // 队列为空
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

// 出队
bool deQueue(LinkQueue Q, BiNode **node) {
    if (isEmpty(Q)) {
        return false; // 队列为空
    }
    LinkNode *temp = Q->front;
    *node = temp->data;
    Q->front = Q->front->next;
    if (Q->front == NULL) { // 如果队列变空
        Q->rear = NULL;
    }
    free(temp);
    return true;
}

// 访问节点
void visit(BiNode *node) {
    printf("%d ", node->data);
}

// 层序遍历二叉树
void levelOrder(BiTree T) {
    if (T == NULL) {
        return; // 空树直接返回
    }

    LinkQueue Q;
    initQueue(&Q); // 初始化队列
    enQueue(Q, T); // 根节点入队

    while (!isEmpty(Q)) {
        BiNode *p;
        if (!deQueue(Q, &p)) {
            break; // 队列为空
        }
        visit(p);       // 访问该节点
        if (p->lchild != NULL) {
            enQueue(Q, p->lchild); // 左孩子入队
        }
        if (p->rchild != NULL) {
            enQueue(Q, p->rchild); // 右孩子入队
        }
    }
}

// 创建一个新节点
BiNode* createNode(ElemType value) {
    BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

// 主函数
int main() {
    // 创建一个简单的二叉树
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */
    BiTree root = createNode(1);
    root->lchild = createNode(2);
    root->rchild = createNode(3);
    root->lchild->lchild = createNode(4);
    root->lchild->rchild = createNode(5);
    root->rchild->lchild = createNode(6);
    root->rchild->rchild = createNode(7);

    // 层序遍历二叉树
    printf("Level Order Traversal of Binary Tree:\n");
    levelOrder(root);
    printf("\n");

    return 0;
}