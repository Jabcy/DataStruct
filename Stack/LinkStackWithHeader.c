#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef char ElemType;
// ������ջ�ṹ�����
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
}LinkNode,*LinkStack;

// ��ʼ����ջ
void initStack(LinkStack *S){
    *S = (LinkNode *)malloc(sizeof(LinkNode));
    (*S)->next = NULL;
}

// ��ջ 
bool push(LinkStack S,ElemType x){
    LinkNode *newnode = (LinkNode *)malloc(sizeof(LinkNode));
    newnode->next = S->next;
    newnode->data = x;
    S->next = newnode;
    return true;
}

// ��ջ
bool pop(LinkStack S,ElemType *x){
    if(S->next == NULL) return false;
    *x = S->next->data;
    LinkNode *p = S->next;
    S->next = p->next;
    free(p);
    return true;
}

// ��ȡջ��Ԫ��
bool getTop(LinkStack S ,ElemType *x){
    if (S->next == NULL)    return false;
    *x = S->next->data;
    return true;
}

// �п�
bool isEmpty(LinkStack S){
    return S->next == NULL;
}

// ����ƥ��
// ʹ��ջ���洢�����ţ�������һ�������žͽ�ջ��Ԫ������ƥ�䣬��ƥ��ɹ����ǳ�ջ
// ��ƥ��ʧ�ܣ���ʧ��
// �������ŵ���ջ�գ���ʧ��
// ɨ����ϵ�ջ���գ���ʧ��
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
// ��׺ת��׺���ʽ
// 1.������ɨ����ʽ
// 2.������������ֱ�Ӽ����׺���ʽ
// 3.����������ֱ����ջ
// 4.�����������򵯳�ջ��Ԫ�ؼ����׺���ʽֱ��������,���Ų������׺���ʽ
// 5.���������,�����ε���ջ��"���ȼ�"���ڻ���ڱ�������������,�������׺���ʽ
//       ���������ѹ��ջ,����������ֹͣ,������һ��ɨ��
// 6.����׺���ʽɨ�����,���ε���ջ��Ԫ��,�������׺���ʽ

// TODO...
// ��׺���ʽ(�沨��ʽ)�ļ���
// 1.������ɨ����ʽ
// 2.����ǲ�������ѹ��ջ�У����ص� 1
// 3.�������������͵�������ջ��Ԫ�أ���ִ�����㣬�ȵ�������������ұߣ��󵯳������������ߣ����ѹ��ջ��
// TODO...
bool calculateSuffixExpression(){

}

// TODO...
// ǰ׺���ʽ(����ʽ)�ļ���
// 1.���ҵ���ɨ����ʽ
// 2.����ǲ�������ѹ��ջ�У����ص� 1
// 3.�������������͵�������ջ��Ԫ�أ���ִ�����㣬�ȵ��������������ߣ��󵯳�����������ұߣ����ѹ��ջ��
// TODO...
bool calculatePrefixExpression(){

}


// �ݹ�ʵ�ֽ׳�
int factorial(int n){
    if(n==0||n==1){return 1;}
    else return n*factorial(n-1);
}


// �ݹ�ʵ��쳲���������
int fib(int n){
    if(n==0||n==1){return n;}
    else return fib(n-2)+fib(n-1);
    
}

int main()
{

    // // ��������
    // char arr1[6] = {'(', '(', ')', ')', '(', ')'}; // ƥ��ɹ�
    // char arr2[6] = {'(', '(', '(', ')', ')', ')'}; // ƥ��ɹ�
    // char arr3[6] = {'(', ')', ')', '(', ')', ')'}; // ����������
    // char arr4[6] = {'(', '(', ')', ')', ')', ')'}; // �����Ź���
    // char arr5[6] = {'(', '[', ']', ')', '{', ')'}; // ���Ͳ�ƥ��
    // char arr6[6] = {'(', '[', '{', '}', ']', ')'}; // Ƕ��ƥ��ɹ�
    // char arr7[6] = {'(', '(', '(', '(', '(', '('}; // ֻ��������
    // char arr8[6] = {')', ')', ')', ')', ')', ')'}; // ֻ��������
    // char arr9[0] = {};                             // ������
    // char arr10[1] = {'('};                         // ����������

    // // �������
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


    //  �׳˲���
    int x = factorial(3);
    printf("%d\n",x);
    x = fib(6);
    printf("%d\n",x);
    return 0;
}
