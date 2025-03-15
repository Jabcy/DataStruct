#include <stdio.h>

#define MAXSIZE 10

typedef struct 
{
    int data[MAXSIZE];
    int length;
}SeqList;
void InitList(SeqList *L){
    L->length=0;
}

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

void ShowList(SeqList *L){
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n",L->data[i]);
    }
}

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
    L.length = 4;
    // printf("%d",L.length);
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    int e;
    DeleteList(&L,2,&e); 
    ShowList(&L);
    printf("删除%d成功\n",e);
    return 0;
}