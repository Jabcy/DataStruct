#include<stdio.h>

#define MAXSIZE 10

typedef struct Node
{
    int data;
    int next;
}SLinkList[MAXSIZE];//����ÿ���ڵ�


int initList(SLinkList L){

    for (int i = 0; i < MAXSIZE; i++)
    {
        L[i].data = -2;//�����нڵ��next��Ϊ-2,��ζ�ſ�
    }
    L->next = -1;//����ָ���˱�β,������NULL
}





int main()
{
    struct Node a[MAXSIZE];//�������Խڵ�Ϊ����Ԫ�ص�������Ϊ��̬����,��д�����������Ƕ�����һ��Node������,
    SLinkList b;//��д�������������LNode��*LinkList������,�������Ӿ��ϱ����Ǿ�̬����,��д����������ֱ�Ӷ�����һ����̬����
    return 0;
}

