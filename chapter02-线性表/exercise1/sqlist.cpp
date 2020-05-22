#include <string.h>
#include "sqlist.h"

void sqlist::CreateList(SqList *&L, ElemType a[], int n)
{
    L = (SqList *)malloc(sizeof(SqList));
    if (a != nullptr && n > 0)
    {
        for (int i = 0; i < n; i++)
            L->data[i] = a[i];
        L->length = n;
    }
}

void sqlist::InitalList(SqList *&L)
{
    L = (SqList *)malloc(sizeof(SqList));
    L->length = 0;
}

void sqlist::InsertList(SqList *&L, ElemType a)
{
    L->data[L->length] = a;
    L->length += 1;
}

void sqlist::PrintList(SqList *&L)
{
    for (int i = 0; i < L->length; i++)
        cout << L->data[i] << " ";
    cout << endl;
}

bool sqlist::GetElementViaLocation(SqList *&L, int location, ElemType &element)
{
    if(location<1||location>L->length)
        return false;
    element=L->data[location - 1];
    return true;
}

int sqlist::GetLocationViaElement(SqList *&L, ElemType element)
{
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] - element == 0)
            return i+1;
    }
    return 0;
}

bool sqlist::IsNullList(SqList *&L)
{
    return L == NULL;
}

int sqlist::ListLength(SqList *&L)
{
    return L->length;
}

bool sqlist::InsertElementInList(SqList *&L, int location, ElemType element)
{
    if(location<1||location>L->length)
        return false;
    for (int i = L->length - 1; i > location - 2; i--)
        L->data[i + 1] = L->data[i];
    L->data[location - 1] = element;
    L->length++;
    return true;
}

bool sqlist::DeleteElementInList(SqList *&L, int location)
{
    if(location<1||location>L->length)
        return false;
    for (int i = location - 1; i < L->length; i++)
        L->data[i] = L->data[i + 1];
    L->data[L->length - 1] = '\0';
    L->length--;
    return true;
}

void sqlist::FreeList(SqList *&L)
{
    free(L);
}