#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

// ��ʽ�洢
typedef struct BiNode {
    ElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode, *BiTree;

// ���нڵ㶨��
typedef struct LinkNode {
    BiNode *data; // �洢�������ڵ�ָ��
    struct LinkNode *next;
} LinkNode;

// ���ж���
typedef struct Queue {
    LinkNode *front, *rear;
} *LinkQueue;

// ��ʼ������
void initQueue(LinkQueue *Q) {
    *Q = (LinkQueue)malloc(sizeof(struct Queue));
    (*Q)->front = (*Q)->rear = NULL;
}

// �ж϶����Ƿ�Ϊ��
bool isEmpty(LinkQueue Q) {
    return Q->front == NULL;
}

// ���
void enQueue(LinkQueue Q, BiNode *node) {
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    newNode->data = node;
    newNode->next = NULL;
    if (Q->rear == NULL) { // ����Ϊ��
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
}

// ����
bool deQueue(LinkQueue Q, BiNode **node) {
    if (isEmpty(Q)) {
        return false; // ����Ϊ��
    }
    LinkNode *temp = Q->front;
    *node = temp->data;
    Q->front = Q->front->next;
    if (Q->front == NULL) { // ������б��
        Q->rear = NULL;
    }
    free(temp);
    return true;
}

// ���ʽڵ�
void visit(BiNode *node) {
    printf("%d ", node->data);
}

// �������������
void levelOrder(BiTree T) {
    if (T == NULL) {
        return; // ����ֱ�ӷ���
    }

    LinkQueue Q;
    initQueue(&Q); // ��ʼ������
    enQueue(Q, T); // ���ڵ����

    while (!isEmpty(Q)) {
        BiNode *p;
        if (!deQueue(Q, &p)) {
            break; // ����Ϊ��
        }
        visit(p);       // ���ʸýڵ�
        if (p->lchild != NULL) {
            enQueue(Q, p->lchild); // �������
        }
        if (p->rchild != NULL) {
            enQueue(Q, p->rchild); // �Һ������
        }
    }
}

// ����һ���½ڵ�
BiNode* createNode(ElemType value) {
    BiNode *newNode = (BiNode *)malloc(sizeof(BiNode));
    newNode->data = value;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

// ������
int main() {
    // ����һ���򵥵Ķ�����
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

    // �������������
    printf("Level Order Traversal of Binary Tree:\n");
    levelOrder(root);
    printf("\n");

    return 0;
}