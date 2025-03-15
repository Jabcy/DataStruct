#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

void Delete(SeqList *L) {
    if (L->length == 0) {
        return;  // ���˳���Ϊ�գ�ֱ�ӷ���
    }

    int n = 0;  // ��˳��������
    for (int i = 0; i < L->length; i++) {
        // �����ǰԪ������һ��Ԫ�ز�ͬ�����ߵ�ǰԪ�������һ��Ԫ��
        if (i == L->length - 1 || L->data[i] != L->data[i + 1]) {
            L->data[n] = L->data[i];  // ����ǰԪ�ر��浽��λ��
            n++;  // ������˳��������
        }
    }
    L->length = n;  // ����˳���ĳ���
}

int main() {
    SeqList list = {{1, 1, 2, 2, 3, 3}, 6};  // ��ʼ��˳���
    Delete(&list);  // ɾ�������ظ�Ԫ��

    printf("ɾ�����˳���: ");
    for (int i = 0; i < list.length; i++) {
        printf("%d ", list.data[i]);
    }
    printf("\n");

    return 0;
}