#include <iostream>

using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

typedef struct Polyn{
    int coef; //系数
    int expn; //指数
    struct Polyn *next;
}PNode,*Polynomial;

void CreatePolyn(Polynomial &P, int n){
    P = new PNode;
    P->next = NULL;
    for (int i = 1; i < n; ++i){
        Polynomial s;
        s = new PNode;
        cin >> s->coef >> s->expn;
        Polynomial pre = P;
        Polynomial q = P->next;
        while(q && q->expn < s->expn){
            pre = q;
            q = q->next;
        }
        s->next = q;
        pre->next = s;
    }
}

PNode *add_Poly(PNode *Ah, PNode *Bh)
{
    PNode *qa,*qb,*s,*r,*Ch;
    qa = Ah->next; qb = Bh->next;         //指向各链表头节点
    r = Ah;                               //指向‘和链表’最后一个结点
    Ch = Ah;                              //Ah作为‘和链表’
    while(qa != NULL && qb != NULL){
        if(qa->expn < qb->expn){         //qa指数小
            r->next = qa;
            r = qa;
            qa = qb->next;
        }
        else if(qa->expn > qb->expn){    //qb指数小
            r->next = qb;
            r = qb;
            qb = qb->next;
        }
        else{
            int x = qa->coef + qb->coef;
            if(x != 0){                  //系数不为0
                qa->coef = x; r->next = qa; r=qa;
                qa = qa->next; s = qb; qb = qb->next;
                free(s);
            }
            else{                        //系数为0 
                s = qa; qa = qa->next; free(s);
                s = qb; qb = qb->next; free(s);
            }
        }
    }
    if(qa == NULL) r->next = qb;
    else r->next = qa;
    free(Bh);
    return (Ch);
}

int main(){
    /* code; */
}