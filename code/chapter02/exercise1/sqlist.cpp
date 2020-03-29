#include"sqlist.h"

void CreateList(SqList* &L, ElemType a[], int n)
{
    if(a!=nullptr && n>=0)
    {
        for(int i=0;i<n;i++)
            L->data[i]=a[i];
        L->length=n;
    }
}

void InitalList(SqList* &L)
{
    L->length=0;
}

void InsertList(SqList* &L, ElemType a)
{
    L->data[L->length]=a;
    L->length+=1;
}

void PrintList(SqList* &L)
{
for(int i=0;i<L->length;i++)
    cout<<L->data[i]<<endl;
    cout<<L->length<<endl;
}

bool isNullList(SqList* &L)
{
    return L==NULL;
}