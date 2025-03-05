#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

// 逆置顺序表
void InverseList(SeqList *L) {
    int temp = 0;
    for (int i = 0; i < L->length / 2; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

// 打印顺序表
void PrintList(SeqList *L) {
    printf("顺序表内容：");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main() {
    // 初始化顺序表
    SeqList L = {{1, 2, 3, 4, 5}, 5}; // 初始内容为 [1, 2, 3, 4, 5]，长度为 5
    printf("初始顺序表：\n");
    PrintList(&L);

    // 调用逆置函数
    InverseList(&L);
    printf("逆置后的顺序表：\n");
    PrintList(&L);

    // 测试空表
    SeqList emptyList = {{}, 0}; // 空表
    printf("\n测试空表：\n");
    printf("初始空表：\n");
    PrintList(&emptyList);
    InverseList(&emptyList);
    printf("逆置后的空表：\n");
    PrintList(&emptyList);

    // 测试奇数长度表
    SeqList oddList = {{1, 2, 3}, 3}; // 奇数长度表
    printf("\n测试奇数长度表：\n");
    printf("初始奇数长度表：\n");
    PrintList(&oddList);
    InverseList(&oddList);
    printf("逆置后的奇数长度表：\n");
    PrintList(&oddList);

    // 测试偶数长度表
    SeqList evenList = {{1, 2, 3, 4}, 4}; // 偶数长度表
    printf("\n测试偶数长度表：\n");
    printf("初始偶数长度表：\n");
    PrintList(&evenList);
    InverseList(&evenList);
    printf("逆置后的偶数长度表：\n");
    PrintList(&evenList);

    return 0;
}