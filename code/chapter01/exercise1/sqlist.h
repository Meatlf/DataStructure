#ifndef SQLIST_H_
#define SQLIST_H_

#include<iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

struct Sqlist
{
    /* data */
    ElemType data[MaxSize];
    int length;
};

void CreateList(Sqlist* &L, ElemType a[], int n);
void InitalList(Sqlist* &L);

void InsertList(Sqlist* &L, ElemType a);

void PrintList(Sqlist* &L);
#endif