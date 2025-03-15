#include <stdio.h>

#define MAXSIZE 15

typedef struct 
{
    int data[MAXSIZE];
    int length;
}SeqList;

void LeftMove(SeqList *L,int p){
    int temp[L->length];//定义临时数组
    for (int i = 0; i < p; i++)
    {   
        temp[i] = L->data[i];
    }//将前p个元素赋给临时数组
    for (int j = 0; j < L->length-p; j++)
    {
        L->data[j] = L->data[j+p];
    }//将剩余元素左移p位
    for (int k = 0; k < p; k++)
    {
        L->data[L->length-p + k] = temp[k];
    }//将临时数组内的元素从p+1位开始,赋给原数组
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