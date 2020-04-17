#include <string.h>
#include "sqlist.h"

void CreateList(SqList *&L, ElemType a[], int n)
{
    L = (SqList *)malloc(sizeof(SqList));
    if (a != nullptr && n >= 0)
    {
        for (int i = 0; i < n; i++)
            L->data[i] = a[i];
        L->length = n;
    }
}

void InitalList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void InsertList(SqList *&L, ElemType a)
{
    L->data[L->length] = a;
    L->length += 1;
}

void PrintList(SqList *&L)
{
    for (int i = 0; i < L->length; i++)
        cout << L->data[i] << " ";
    cout << endl;
}

void PrintElementViaLocation(SqList *&L, int location)
{
    cout << L->data[location - 1] << endl;
}

int PrintLocationViaElement(SqList *&L, ElemType element)
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] - element == 0)
            return i;
    }
}

bool IsNullList(SqList *&L)
{
    return L == NULL;
}

int ListLength(SqList *&L)
{
    return L->length;
}

void InsertElementInList(SqList *&L, int location, ElemType element)
{
    for (int i = L->length - 1; i > location - 2; i--)
        L->data[i + 1] = L->data[i];
    L->data[location-1] = element;
    L->length++;
}

void DeleteElementInList(SqList *&L, int location)
{
    for (int i = location-1; i < L->length; i++)
        L->data[i] = L->data[i + 1];
    L->data[L->length - 1] = '\0';
}

void FreeList(SqList *&L)
{
    free(L);
}