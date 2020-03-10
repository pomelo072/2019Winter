#include <iostream>

using namespace std;


#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

typedef struct StackNode{
    SElemType data;
    struct StackNode *next;
} StackNode, *LinkStack;

//初始化
void InitStack(LinkStack &S){
    S = NULL;
}

//判断空栈
bool StackEmpty(LinkStack S){
    if(S == NULL) return true;
    else return false;
}

//入栈
Status Push(LinkStack &S,SElemType e){
    LinkStack p;
    p = new StackNode;
    p->data = e;
    p->next = S;      //栈顶指针移动
    S = p;            //栈顶位置交换
    return OK;
}

//出栈

Status Pop(LinkStack &S,SElemType &e){
    if(S == NULL) return ERROR;
    LinkStack p;
    e = S->data;
    p = S;
    S = S->next;
    delete p;
    return OK;
}
