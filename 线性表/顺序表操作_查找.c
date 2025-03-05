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
        printf("���Ա�����,����ʧ��\n");
        return -1;
    }

    if(i<1||i>L->length+1){
        printf("����λ�ò��Ϸ�,����ʧ��\n");
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


int GetElem(SeqList L, int i){
    
    return L.data[i-1];
}

int LocateElem(SeqList L,int e){
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i]==e)
        {
            return i+1 ;
        }
    }
    return -1;
}

int main(){
    SeqList L;
    InitList(&L);
    // printf("%d",L.length);
    InsertList(&L,1,1);
    InsertList(&L,2,1);
    InsertList(&L,3,1);
    InsertList(&L,4,1);
    InsertList(&L,5,1);
    InsertList(&L,6,1);


    printf("���ҵ�%dλ,���Ϊ%d\n",3,GetElem(L,3));
    printf("����%d��λ��,����ڵ�%dλ\n",2,LocateElem(L,2));
    ShowList(&L);
}