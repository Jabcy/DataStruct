#include <stdio.h>

#define MAXSIZE 10

typedef struct 
{
    int data[MAXSIZE];
    int length;
}SeqList;
// 初始化
void InitList(SeqList *L){
    L->length=0;
}
// 插入
int InsertList(SeqList *L, int e,int i){
    if (L->length>=MAXSIZE)
    {
        printf("线性表已满,插入失败\n");
        return -1;
    }

    if(i<1||i>L->length+1){
        printf("插入位置不合法,插入失败\n");
        return -1;
    }
    
    for(int j = L->length;j>=i;j--){
        L->data[j] = L->data[j-1];
    };
    L->data[i-1] = e;
    L->length++;
    return 0;
}
// 展示
void ShowList(SeqList *L){
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n",L->data[i]);
    }
    
}
// 删除
int DeleteList(SeqList *L,int i,int *e){
    if (i<1||i>L->length+1)
    {
        printf("删除位置不合法,删除失败\n");
        return -1;
    }
    if (L->length==0)
    {
        printf("线性表为空,删除失败\n");
        return -1;
    }
    *e = L->data[i-1];
    for(int j = i;j<L->length;j++){
        L->data[j-1] = L->data[j];
    }
    L->length--;
}

int main(){
    SeqList L;
    InitList(&L);
    // printf("%d",L.length);
    InsertList(&L,7,1);
    InsertList(&L,8,2);
    InsertList(&L,23,3);
    InsertList(&L,7,4);
    InsertList(&L,8,5);
    InsertList(&L,23,6);
    InsertList(&L,7,8);
    InsertList(&L,8,7);
    InsertList(&L,23,8);
    InsertList(&L,7,9);
    InsertList(&L,1,10);

    ShowList(&L);
}