#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

void Delete(SeqList *L) {
    if (L->length == 0) {
        return;  // 如果顺序表为空，直接返回
    }

    int n = 0;  // 新顺序表的索引
    for (int i = 0; i < L->length; i++) {
        // 如果当前元素与下一个元素不同，或者当前元素是最后一个元素
        if (i == L->length - 1 || L->data[i] != L->data[i + 1]) {
            L->data[n] = L->data[i];  // 将当前元素保存到新位置
            n++;  // 更新新顺序表的索引
        }
    }
    L->length = n;  // 更新顺序表的长度
}

int main() {
    SeqList list = {{1, 1, 2, 2, 3, 3}, 6};  // 初始化顺序表
    Delete(&list);  // 删除连续重复元素

    printf("删除后的顺序表: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    return 0;
}