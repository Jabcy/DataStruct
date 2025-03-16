#include<stdio.h>
#include<stdlib.h>
#include <locale.h>

typedef struct DNode{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DNode,*DLinkList;

// ��ʼ��ѭ��˫����
int initList(DLinkList *L){
    *L = (DNode*)malloc(sizeof(DNode));
    if(*L == NULL) return 0; // ����ڴ����ʧ��
    
    (*L)->next = *L; // ѭ��˫�����ͷ�ڵ�nextָ������
    (*L)->prior = *L; // ͷ�ڵ��priorҲָ������
    return 1;
}

// ��ѭ��˫����ĩβ׷��һ��Ԫ��x
int append(DLinkList L, int x){
    if(L == NULL) return 0;
    
    DNode *s = (DNode*)malloc(sizeof(DNode));
    if(s == NULL) return 0;
    s->data = x;
    
    DNode *tail = L->prior; // ��ȡ��ǰβ�ڵ�
    
    s->next = L; // �½ڵ��nextָ��ͷ�ڵ�
    s->prior = tail; // �½ڵ��priorָ���β�ڵ�
    tail->next = s; // ��β�ڵ��nextָ���½ڵ�
    L->prior = s; // ͷ�ڵ��priorָ���½ڵ㣬���ѭ��
    
    return 1;
}

// ��ӡѭ��˫�����е�����Ԫ��
void PrintList(DLinkList L){
    if(L->next == L){ // ���ֻ��ͷ�ڵ�
        printf("Empty List\n");
        return;
    }
    DNode *p = L->next; // ����ͷ�ڵ㣬�ӵ�һ��ʵ�����ݽڵ㿪ʼ
    do {
        printf("%d -> ", p->data); // ��ӡ����
        p = p->next; // �ƶ�����һ���ڵ�
    } while(p != L); // ���ص�ͷ�ڵ�ʱֹͣ
    printf("HEAD\n"); // ��ʾ�������
}

// ��������Ƿ�Գƣ����ģ�
int isSymmetry(DLinkList L){
    if(L == NULL || L->next == L || L->next->next == L) return 1; // �������ֻ��һ��/����Ԫ����Ϊ�Գ�
    
    DNode *ph = L->next; // ��ǰ��������ָ��
    DNode *pt = L->prior; // �Ӻ���ǰ������ָ��
    
    while(ph != pt && ph->next != pt){
        if(ph->data != pt->data){
            printf("2\n");
            return 0;
        }
        ph = ph->next; // ��ǰ�ƶ�
        pt = pt->prior; // ����ƶ�
    }
    if(ph->data != pt->data){ // ���������������ڵ��Ԫ���Ƿ���ͬ
        printf("2\n");
        return 0;
    }
    
    printf("����\n");
    return 1;
}

int main(){
    setlocale(LC_ALL, "en_US.UTF-8"); // ���ó������������ΪUTF-8
    DLinkList L = NULL;
    if(initList(&L)){
        append(L,1);
        append(L,2);
        append(L,3);
        append(L,2);
        append(L,1);
        PrintList(L); // ��ӡ��������
        isSymmetry(L); // ��������Ƿ�Գ�
    } else {
        printf("��ʼ������ʧ��\n");
    }
    return 0;
}