#include"sqlist.h"

void CreateList(Sqlist* &L, ElemType a[], int n)
{
    if(a!=nullptr && n>=0)
    {
        for(int i=0;i<n;i++)
            L->data[i]=a[i];
        L->length=n;
    }
}

void InitalList(Sqlist* &L)
{
    L->length=0;
}

void InsertList(Sqlist* &L, ElemType a)
{
    L->data[L->length]=a;
    L->length+=1;
}

void PrintList(Sqlist* &L)
{
for(int i=0;i<L->length;i++)
    cout<<L->data[i]<<endl;
}