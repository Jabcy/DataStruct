#include <stdio.h>

#define MAXSIZE 10

typedef struct {
    int data[MAXSIZE];
    int length;
} SeqList;

// ����˳���
void InverseList(SeqList *L) {
    int temp = 0;
    for (int i = 0; i < L->length / 2; i++) {
        temp = L->data[i];
        L->data[i] = L->data[L->length - i - 1];
        L->data[L->length - i - 1] = temp;
    }
}

// ��ӡ˳���
void PrintList(SeqList *L) {
    printf("˳������ݣ�");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int main() {
    // ��ʼ��˳���
    SeqList L = {{1, 2, 3, 4, 5}, 5}; // ��ʼ����Ϊ [1, 2, 3, 4, 5]������Ϊ 5
    printf("��ʼ˳���\n");
    PrintList(&L);

    // �������ú���
    InverseList(&L);
    printf("���ú��˳���\n");
    PrintList(&L);

    // ���Կձ�
    SeqList emptyList = {{}, 0}; // �ձ�
    printf("\n���Կձ�\n");
    printf("��ʼ�ձ�\n");
    PrintList(&emptyList);
    InverseList(&emptyList);
    printf("���ú�Ŀձ�\n");
    PrintList(&emptyList);

    // �����������ȱ�
    SeqList oddList = {{1, 2, 3}, 3}; // �������ȱ�
    printf("\n�����������ȱ�\n");
    printf("��ʼ�������ȱ�\n");
    PrintList(&oddList);
    InverseList(&oddList);
    printf("���ú���������ȱ�\n");
    PrintList(&oddList);

    // ����ż�����ȱ�
    SeqList evenList = {{1, 2, 3, 4}, 4}; // ż�����ȱ�
    printf("\n����ż�����ȱ�\n");
    printf("��ʼż�����ȱ�\n");
    PrintList(&evenList);
    InverseList(&evenList);
    printf("���ú��ż�����ȱ�\n");
    PrintList(&evenList);

    return 0;
}