#include <stdio.h>

#define MAXSIZE 10

typedef struct 
{
    int data[MAXSIZE];
    int length;
}SeqList;

void DeleteElem(SeqList *L,int x){
    int k = 0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i]!=x)
        {
            L->data[k]=L->data[i];
            k++; 
        }
    }
    L->length = k;
}