#include <iostream>

using namespace std;


#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
typedef struct 
{
    ElemType *elem;
    int length;
}SqList;

Status InitList(SqList &L)
{
    L.elem = new ElemType[MAXSIZE];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}
Status GetElem(SqList L,int i,ElemType &e)
{
    if(i<1||i>L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}
int LocateElem(SqList L, ElemType e)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.elem[i]==e) return i+1;
    }
    return 0;
}

Status ListInsert(SqList &L, int i, ElemType e)
{
    if((i<1)||(i>L.length+1)) return ERROR;
    if(L.length == MAXSIZE) return ERROR;
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1] = L.elem[j];
    }
    L.elem[i-1] = e;
    ++L.length;
    return OK;
}
Status ListDelete(SqList &L,int i)
{
    if((i<1)||(i>L.length+1)) return ERROR;
    for (int j=i; j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    --L.length;
    return OK;
}
void DestroyList(SqList &L)
{
    if(L.elem) delete[]L.elem;
}
void ClearList(SqList &L)
{
    L.length = 0;
}
int GetLength(SqList L)
{
    return (L.length);
}
int IsEmpty(SqList L)
{
    if(L.length == 0) return 1;
    else return 0;
}
void MergeList(SqList La, SqList Lb, SqList &Lc)
{
    ElemType *pa,*pb,*pc,*pa_last,*pb_last;
    pa = La.elem; pb = Lb.elem;
    Lc.length = La.length + Lb.length;
    Lc.elem=(ElemType*)malloc(Lc.length*sizeof(ElemType));
    pc = Lc.elem;
    if(!Lc.elem) exit(OVERFLOW);
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;
    while (pa<=pa_last && pb<=pb_last)
    {
        if(*pa<=*pb) *pc++=*pa++;
        else *pc++=*pb++;
    }
    while(pa<=pa_last) *pc++=*pa++;
    while(pb<=pb_last) *pc++=*pb++;
}    
int main()
{
    /* code; */
}