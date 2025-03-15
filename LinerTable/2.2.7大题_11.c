#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

// 初始化循环双链表
int initList(DLinkList *L){
    *L = (DNode*)malloc(sizeof(DNode));
    if(*L == NULL) return 0; // 如果内存分配失败
    
    (*L)->next = *L; // 循环双链表的头节点next指向自身
    (*L)->prior = *L; // 头节点的prior也指向自身
    return 1;
}

// 在循环双链表末尾追加一个元素x
int append(DLinkList L, int x){
    if(L == NULL) return 0;
    
    DNode *s = (DNode*)malloc(sizeof(DNode));
    if(s == NULL) return 0;
    s->data = x;
    
    DNode *tail = L->prior; // 获取当前尾节点
    
    s->next = L; // 新节点的next指向头节点
    s->prior = tail; // 新节点的prior指向旧尾节点
    tail->next = s; // 旧尾节点的next指向新节点
    L->prior = s; // 头节点的prior指向新节点，完成循环
    
    return 1;
}

// 打印循环双链表中的所有元素
void PrintList(DLinkList L){
    if(L->next == L){ // 如果只有头节点
        printf("Empty List\n");
        return;
    }
    DNode *p = L->next; // 跳过头节点，从第一个实际数据节点开始
    do {
        printf("%d -> ", p->data); // 打印数据
        p = p->next; // 移动到下一个节点
    } while(p != L); // 当回到头节点时停止
    printf("HEAD\n"); // 表示链表结束
}

// 检查链表是否对称（回文）
int isSymmetry(DLinkList L){
    if(L == NULL || L->next == L || L->next->next == L) return 1; // 空链表或只有一个/两个元素视为对称
    
    DNode *ph = L->next; // 从前向后遍历的指针
    DNode *pt = L->prior; // 从后向前遍历的指针
    
    while(ph != pt && ph->next != pt){
        if(ph->data != pt->data){
            printf("2\n");
            return 0;
        }
        ph = ph->next; // 向前移动
        pt = pt->prior; // 向后移动
    }
    if(ph->data != pt->data){ // 最后检查相遇点或相邻点的元素是否相同
        printf("2\n");
        return 0;
    }
    
    printf("中文\n");
    return 1;
}

int main(){
    setlocale(LC_ALL, "en_US.UTF-8"); // 设置程序的区域设置为UTF-8
    DLinkList L = NULL;
    if(initList(&L)){
        append(L,1);
        append(L,2);
        append(L,3);
        append(L,2);
        append(L,1);
        PrintList(L); // 打印链表内容
        isSymmetry(L); // 检查链表是否对称
    } else {
        printf("初始化链表失败\n");
    }
    return 0;
}