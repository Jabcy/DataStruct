#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char ElemType;
// 定义链栈结构体变量
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkStack;

// 初始化链栈
void initStack(LinkStack *S){
    *S = (LinkNode *)malloc(sizeof(LinkNode));
    (*S)->next = NULL;
}

// 入栈 
bool push(LinkStack S,ElemType x){
    LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));
    newnode->next = S->next;
    newnode->data = x;
    S->next = newnode;
    return true;
}

// 出栈
bool pop(LinkStack S,ElemType *x){
    if(S->next == NULL) return false;
    *x = S->next->data;
    LinkNode *p = S->next;
    S->next = p->next;
    free(p);
    return true;
}

// 获取栈顶元素
bool getTop(LinkStack S ,ElemType *x){
    if (S->next == NULL)    return false;
    *x = S->next->data;
    return true;
}

// 判空
bool isEmpty(LinkStack S){
    return S->next == NULL;
}

// 括号匹配
// 使用栈来存储左括号，若发现一个有括号就将栈顶元素与其匹配，若匹配成功就是出栈
// 若匹配失败，则失败
// 有右括号但是栈空，则失败
// 扫描完毕但栈不空，则失败
bool bracketCheck(char arr[],int length){
    LinkStack S;
    initStack(&S);
    char x;
    for (int i = 0; i < length; i++)
    {
        if(arr[i] == '('||arr[i] == '['||arr[i] == '{'){push(S,arr[i]);}
        else{
            if(isEmpty(S)){return false;}
            else{
                pop(S,&x);
                if(x == '(' && arr[i] != ')')return false;
                if(x == '[' && arr[i] != ']')return false;
                if(x == '{' && arr[i] != '}')return false; 
            }
        }
    }
    return isEmpty(S);
}

// TODO...
// 中缀转后缀表达式
// 1.从左到右扫描表达式
// 2.遇到操作符就直接加入后缀表达式
// 3.遇到左括号直接入栈
// 4.遇到有括号则弹出栈顶元素加入后缀表达式直到左括号,括号不加入后缀表达式
// 5.遇到运算符,就依次弹出栈内"优先级"高于或等于本运算符的运算符,并加入后缀表达式
//       将本运算符压入栈,碰到左括号停止,进行下一次扫描
// 6.将中缀表达式扫描完后,依次弹出栈顶元素,并加入后缀表达式

// TODO...
// 后缀表达式(逆波兰式)的计算
// 1.从左到右扫描表达式
// 2.如果是操作数就压入栈中，并回到 1
// 3.如果是运算符，就弹出两个栈顶元素，并执行运算，先弹出的在运算符右边，后弹出的在运算符左边，结果压入栈中
// TODO...
bool calculateSuffixExpression(){

}

// TODO...
// 前缀表达式(波兰式)的计算
// 1.从右到左扫描表达式
// 2.如果是操作数就压入栈中，并回到 1
// 3.如果是运算符，就弹出两个栈顶元素，并执行运算，先弹出的在运算符左边，后弹出的在运算符右边，结果压入栈中
// TODO...
bool calculatePrefixExpression(){

}


// 递归实现阶乘
int factorial(int n){
    if(n==0||n==1){return 1;}
    else return n*factorial(n-1);
}


// 递归实现斐波那契数列
int fib(int n){
    if(n==0||n==1){return n;}
    else return fib(n-2)+fib(n-1);
    
}

int main()
{

    // // 测试用例
    // char arr1[6] = {'(', '(', ')', ')', '(', ')'}; // 匹配成功
    // char arr2[6] = {'(', '(', '(', ')', ')', ')'}; // 匹配成功
    // char arr3[6] = {'(', ')', ')', '(', ')', ')'}; // 多余右括号
    // char arr4[6] = {'(', '(', ')', ')', ')', ')'}; // 右括号过多
    // char arr5[6] = {'(', '[', ']', ')', '{', ')'}; // 类型不匹配
    // char arr6[6] = {'(', '[', '{', '}', ']', ')'}; // 嵌套匹配成功
    // char arr7[6] = {'(', '(', '(', '(', '(', '('}; // 只有左括号
    // char arr8[6] = {')', ')', ')', ')', ')', ')'}; // 只有右括号
    // char arr9[0] = {};                             // 空数组
    // char arr10[1] = {'('};                         // 单独左括号

    // // 测试输出
    // printf("Test Case 1: %d\n", bracketCheck(arr1, 6)); // 1
    // printf("Test Case 2: %d\n", bracketCheck(arr2, 6)); // 1
    // printf("Test Case 3: %d\n", bracketCheck(arr3, 6)); // 0
    // printf("Test Case 4: %d\n", bracketCheck(arr4, 6)); // 0
    // printf("Test Case 5: %d\n", bracketCheck(arr5, 6)); // 0
    // printf("Test Case 6: %d\n", bracketCheck(arr6, 6)); // 1
    // printf("Test Case 7: %d\n", bracketCheck(arr7, 6)); // 0
    // printf("Test Case 8: %d\n", bracketCheck(arr8, 6)); // 0
    // printf("Test Case 9: %d\n", bracketCheck(arr9, 0)); // 1
    // printf("Test Case 10: %d\n", bracketCheck(arr10, 1)); // 0


    //  阶乘测试
    int x = factorial(3);
    printf("%d\n",x);
    x = fib(6);
    printf("%d\n",x);
    return 0;
}
