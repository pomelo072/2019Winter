#include <iostream>

using namespace std;


#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;

//定义链表结构
typedef struct Lnode
{
    ElemType data;
    struct Lnode *next;
}LNode,*LinkList;

//初始化链表
Status InitList_L(LinkList &L)
{
    L = new LNode;
    L -> next = NULL;
    return OK;
}

//销毁链表
Status DestroyList_L(LinkList &L)
{
    LinkList p;
    while (L)
    {
        p = L;
        L = L -> next;
        delete p;
    }
    return OK;
}

//清空链表
Status ClearList(LinkList &L)
{
    LinkList p,q;
    p = L ->next;
    while (p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    L ->next = NULL;
    return OK;
}

//求表长
int ListLength_L(LinkList L)
{
    LinkList p;
    p = L ->next;
    int i = 0;
    while (p)
    {
        i++;
        p = p ->next;
    }
    return i;
}

//判断空表
int ListEmpty(LinkList L)
{
    if(L ->next) return 0;
    else return 1;
}

//取值
Status GetElem_L(LinkList L,int i,ElemType &e)
{
    //初始化
    LinkList p = L ->next;
    int j = 1;
    while (p && j<i)
    {
        p = p ->next;
        ++j;
    }
    if(!p || j > i) return ERROR;
    e = p ->data;
    return OK;
}

//查找(地址)
LNode *LocateElem_A(LinkList L, ElemType e)
{
    LinkList p = L ->next;
    while (p && p ->data != e)
    {
        p = p ->next;
    }
    return p;
}

//查找(位置)
int LocateElem_N(LinkList L, ElemType e)
{
    LinkList p = L ->next;
    int j = 1;
    while(p && p ->data !=e)
    {
        p = p ->next;
        j++;
    }
    if (p) return j;
    else return 0;
}

//查找算法时间复杂度为O(n)

//插入
Status ListInsert_L(LinkList &L,int i, ElemType e)
{
    LinkList p = L;
    int j = 0;
    while(p && j < i-1)
    {
        p = p ->next;
        ++j;
    }
    if(!p || j >i-1) return ERROR;
    LinkList s;
    s = new LNode;
    s ->data = e;
    s ->next = p ->next;
    p ->next = s;
    return OK;
}

//删除
Status ListDelete_L(LinkList &L, int i,ElemType &e)
{
    LinkList p = L,q;
    int j = 0;
    while(p ->next && j < i-1)
    {
        p = p ->next;
        ++j;
    }
    if(!(p->next) || j > i-1) return ERROR;
    q = p ->next;
    p->next = q->next;
    e = q->data;
    delete q;
    return OK;
}

//插入删除算法时间复杂度为O(n)

//创建(表头插入)
void CreateList_F(LinkList &L, int n)
{
    L = new LNode;
    L->next = NULL;
    for(int i = n; i > 0;--i)
    {
        LinkList p;
        p = new LNode;
        cin >> p ->data;
        p -> next = L -> next;
        L -> next = p;
    }
}

//创建(表尾插入)
void CreateList_L(LinkList &L,int n)
{
    L = new LNode;
    L -> next =NULL;
    LinkList r = L;
    for(int i = 0; i < n; ++i)
    {
        LinkList p;
        p = new LNode;
        cin >> p-> data;
        p->next = NULL;
        r->next = p;
        r=p;
    }
}

//合并
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    LinkList pa = La->next,pb = Lb->next;
    LinkList pc = Lc = La;
    while(pa && pb){
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete Lb;
}


int main()
{
    /* code; */
}