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

// O(n)
void CreateList(SqList *&L, ElemType a[], int n);

// O(1)
void InitalList(SqList *&L);

// 尾插法
// O(1)
void InsertList(SqList *&L, ElemType a);

// O(n)
void PrintList(SqList *&L);

// O(1)
bool GetElementViaLocation(SqList *&L, int location, ElemType &element);

// O(n)
int GetLocationViaElement(SqList *&L, ElemType element);

// O(1)
bool IsNullList(SqList *&L);

// O(1)
int ListLength(SqList *&L);

// O(n)
bool InsertElementInList(SqList *&L, int location, ElemType element);

// O(n)
bool DeleteElementInList(SqList *&L, int location);

// O(1)
void FreeList(SqList *&L);
#endif