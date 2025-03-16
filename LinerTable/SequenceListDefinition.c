#include <stdio.h>
#include <stdlib.h>

#define InitSize 10
// 动态分配——结构体定义
typedef struct{
    int *data;
    int length;
    int MAXSIZE;
}SeqList;
// 动态分配初始化
void InitList(SeqList *L){
    L->MAXSIZE = InitSize;
    L->data = (SeqList *)malloc(L->MAXSIZE*sizeof(int));
    L->length = 0;
}
// 动态分配，增加空间
void IncreaseList(SeqList *L, int len){
    int *p = L->data;
    L->data =  (SeqList *)malloc((L->MAXSIZE+len)*sizeof(int));
    for(int i=0;i<L->MAXSIZE;i++){
        L->data[i] = p[i];
    }
    L->MAXSIZE += len;
    free(p);
}
// 静态分配——结构体定义
// typedef struct 
// {
//     int data[MAXSIZE];
//     int length;
// }SeqList;
// // 静态分配——初始化
// void InitList(SeqList *L){
//     L->length=0;
// }



int main(){
    SeqList L;
    InitList(&L);
    printf("%d\n",L.MAXSIZE);
    IncreaseList(&L,5);
    printf("%d\n",L.MAXSIZE);
}