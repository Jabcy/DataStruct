#include <stdio.h>

#define MAXSIZE 10

typedef struct{
    int data[MAXSIZE];
    int length;
}SeqList;


int Delete(SeqList *L,int s,int t){
    if(s=t||s>t){
        printf("s与t不合理\n");
        return 0;
    }
    if (L->length == 0)
    {
        printf("顺序表为空\n");
        return 0;
    }
    int k=0;
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i]<s||L->data[i]>t)
        {
            L->data[k] = L->data[i];
            k++;
        }
        
    }
    L->length = k;
} 