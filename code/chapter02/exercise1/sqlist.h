#ifndef SQLIST_H_
#define SQLIST_H_

#include <iostream>
using namespace std;

#define MaxSize 50
typedef char ElemType;

struct SqList
{
    /* data */
    ElemType data[MaxSize];
    int length;
};

void CreateList(SqList *&L, ElemType a[], int n);
void InitalList(SqList *&L);

void InsertList(SqList *&L, ElemType a);

void PrintList(SqList *&L);

void PrintElementViaLocation(SqList *&L, int location);

int PrintLocationViaElement(SqList *&L, ElemType element);

bool IsNullList(SqList *&L);

int ListLength(SqList *&L);

void InsertElementInList(SqList *&L, int location, ElemType element);

void DeleteElementInList(SqList *&L, int location);

void FreeList(SqList *&L);
#endif