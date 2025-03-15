#include <stdio.h>

#define MAXSIZE 15

typedef struct
{
    int data[MAXSIZE];
    int length;
} SeqList;

void ExchangeList(SeqList *L, int m, int n)
{
    int temp[m + n];
    for (int i = 0; i < m; i++)
    {
        temp[i] = L->data[i];
    }
    for (int j = 0; j < n; j++)
    {
        L->data[j] = L->data[j + m];
    }
    for (int k = 0; k < m; k++)
    {
        L->data[n + k] = temp[k];
    }
}

void ShowList(SeqList L){
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n",L.data[i]);
    }
    
}


void main(){
    SeqList L = {{1,2,3,1,2,3,1,2,3,4,5,6,4,5,6},15};
    int m = 9;
    int n = 6;
    ExchangeList(&L,m,n);

    ShowList(L);
}