#include <stdio.h>

#define MAXSIZE 10

typedef struct{
    int data[MAXSIZE];
    int length;
}SeqList;

int DeleteMin(SeqList *L){
    if (L->length == 0)
    {
        printf("Ë³Ğò±íÎª¿Õ,É¾³ıÊ§°Ü\n");
        return 0;
    }
    
    int min = 0;
    int minnum = L->data[0];
    for (int i = 0; i < L->length; i++)
    {
        if (L->data[i]<min)
        {
            min = i;
        }
    }
    minnum = L->data[min];
    L->data[min] = L->data[L->length-1];
    L->length--;
    return minnum;
}