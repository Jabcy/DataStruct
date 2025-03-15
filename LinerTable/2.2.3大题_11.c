#include <stdio.h>

#define MAXSIZE 15

typedef struct 
{
    int data[MAXSIZE];
    int length;
}SeqList;


void ShowList(SeqList L){
    for (int i = 0; i < L.length; i++)
    {
        printf("%d\n",L.data[i]);
    }
    
}

void SearchMid(SeqList L1,SeqList L2){
    int mid = L1.data[0];
    for (int i = 0; i < L1.length; i++)
    {
        if (mid<L2.data[i])
        {
            mid = L1.data[i+1];
        }else{
            mid = L2.data[i];
        }
        
    }
    
}




void main(){
    SeqList L = {{1,2,3,1,2,3,1,2,3,4,5,6,4,5,6},15};
    SeqList L2 = {{4,5,6,4,2,7,8},7};

    ShowList(L);
}