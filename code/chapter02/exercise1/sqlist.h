#ifndef SQLIST_H_
#define SQLIST_H_

#include<iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

struct SqList
{
    /* data */
    ElemType data[MaxSize];
    int length;
};

void CreateList(SqList* &L, ElemType a[], int n);
void InitalList(SqList* &L);

void InsertList(SqList* &L, ElemType a);

void PrintList(SqList* &L);

bool isNullList(SqList* &L);
#endif