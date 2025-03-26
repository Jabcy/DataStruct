#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXLEN 255

// ˳����崮
typedef struct String
{
    char ch[MAXLEN];
    int length;
}SString;

// ��̬���鶨�崮
typedef struct String
{
    char *ch;
    int length;
}HString;



// // ����T��ֵΪchars
// bool strAssign(*T,char s){}

// // ���Ʋ���������S��T
// bool strCopy(*T,S){}

// // �п�
// bool strEmpty(S){}

// // �󴮳�
// int strLength(S){}

// // ��գ�������Ϊ�մ�
// bool clearString(*S){}

// // ���ٴ�
// bool destroyString(*S){}

// // ����������,��T����
// bool conCat(*T,S1,S2){}

// �����鶨��Ĵ���һλ��Ϊ�գ��Ӷ�ʹ�ַ�����λ���������λ����ͬ
// ���Ӵ�����Sub���أ���S�ĵ�pos���len���ַ�
bool subString(SString *Sub,SString S,int pos,int len){
    if(pos+len-1 > Sub->length){return false;}
    for (int i = pos; i < len; i++)
    {
        (*Sub).ch[i-pos+1] = S.ch[i];
    }
    (*Sub).length = len;
    return true;
}



// �Ƚϴ����ַ��Ĵ�С,��S>T�򷵻�1����ȷ���0��S<T����-1
int strCompare(SString S,SString T){
    
    for (int i = 1; i < S.length && i < T.length ; i++)
    {
        if(S.ch[i]!=T.ch[i]){return S.ch[i]-T.ch[i];}
    }
    // ��ѭ��������û���أ�˵�������ַ���ǰ����ַ���ͬ
    return S.length-T.length;// ��S��������ֵ��T�����ظ�ֵ��ͬ�����򷵻�0
}

// ��λ����������S��T��λ�ã���û�У��򷵻�0
// ��ϱȽϴ�С�����ͽ�ȡ�Ӵ��Ĳ���
int index(SString S,SString T){
    SString temp;
    int n = strLength(S);
    int m = strLength(T);
    int i =1;
    while (i<n-m+1)
    {
        subString(&temp,S,i,m);
        if(strCompare(temp,T)!=0) i++;
        else return i;
    }
    return 0;
}


int main()
{
    
    return 0;
}