#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAXLEN 255

// 顺序表定义串
typedef struct String
{
    char ch[MAXLEN];
    int length;
}SString;

// 动态数组定义串
typedef struct String
{
    char *ch;
    int length;
}HString;



// // 将串T赋值为chars
// bool strAssign(*T,char s){}

// // 复制操作，复制S到T
// bool strCopy(*T,S){}

// // 判空
// bool strEmpty(S){}

// // 求串长
// int strLength(S){}

// // 清空，将串置为空串
// bool clearString(*S){}

// // 销毁串
// bool destroyString(*S){}

// // 连接两个串,由T返回
// bool conCat(*T,S1,S2){}

// 由数组定义的串第一位置为空，从而使字符串的位序与数组的位序相同
// 求子串，由Sub返回，串S的第pos起的len个字符
bool subString(SString *Sub,SString S,int pos,int len){
    if(pos+len-1 > Sub->length){return false;}
    for (int i = pos; i < len; i++)
    {
        (*Sub).ch[i-pos+1] = S.ch[i];
    }
    (*Sub).length = len;
    return true;
}



// 比较串中字符的大小,若S>T则返回1，相等返回0，S<T返回-1
int strCompare(SString S,SString T){
    
    for (int i = 1; i < S.length && i < T.length ; i++)
    {
        if(S.ch[i]!=T.ch[i]){return S.ch[i]-T.ch[i];}
    }
    // 若循环结束还没返回，说明两个字符串前面的字符相同
    return S.length-T.length;// 若S长返回正值，T长返回负值，同样长则返回0
}

// 定位操作，返回S中T的位置，若没有，则返回0
// 结合比较大小操作和截取子串的操作
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