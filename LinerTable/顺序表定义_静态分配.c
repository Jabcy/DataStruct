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

int main(){
    SeqList L;
    InitList(&L);
    printf("%d",L.length);
}