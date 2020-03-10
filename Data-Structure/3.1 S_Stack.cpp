#include <iostream>

using namespace std;


#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;
#define MAXSIZE 100
typedef struct 
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


//初始化栈
Status InitStack(SqStack &S){
    S.base = new SElemType[MAXSIZE];     //动态分配
    if(!S.base) return OVERFLOW;
    S.top = S.base;                      //栈顶指针指向栈底
    S.stacksize = MAXSIZE;
    return OK;
}

//判断空栈
bool StackEmpty(SqStack S){
    if(S.top == S.base) return true;
    else return false;
}

//求栈长
int Stacklength(SqStack S){
    return S.top - S.base;
}

//清空栈
Status ClearStack(SqStack S){
    if(S.base) S.top = S.base;
    return OK;
}

//入栈
Status Push(SqStack &S,SElemType e){
    if(S.top - S.base == S.stacksize) return ERROR; //栈满
    *S.top ++= e;
    return OK;
}

//出栈
Status Pop(SqStack &S,SElemType &e){
    if(S.top == S.base) return ERROR;               //栈空
    e = *--S.top;
    return OK;
}

//取栈顶元素
Status GetTop(SqStack S,SElemType &e){
    if(S.top == S.base) return ERROR;               //栈满
    e = *(S.top - 1);
    return OK;
}

