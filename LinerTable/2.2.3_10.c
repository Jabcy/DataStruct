#include <stdio.h>

#define MAXSIZE 15

typedef struct 
{
    int data[MAXSIZE];
    int length;
}SeqList;

void LeftMove(SeqList *L,int p){
    int temp[L->length];//������ʱ����
    for (int i = 0; i < p; i++)
    {   
        temp[i] = L->data[i];
    }//��ǰp��Ԫ�ظ�����ʱ����
    for (int j = 0; j < L->length-p; j++)
    {
        L->data[j] = L->data[j+p];
    }//��ʣ��Ԫ������pλ
    for (int k = 0; k < p; k++)
    {
        L->data[L->length-p + k] = temp[k];
    }//����ʱ�����ڵ�Ԫ�ش�p+1λ��ʼ,����ԭ����
}

void ShowList(SeqList L){
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n",L.data[i]);
    }
    
}

void main(){
    SeqList L = {{1,2,3,1,2,3,1,2,3,4,5,6,4,5,6},15};
    LeftMove(&L,9);

    
    ShowList(L);
}