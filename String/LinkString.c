#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct StringNode
{
    char ch[4];
    struct StringNode *next;
}StringNode,*String;
