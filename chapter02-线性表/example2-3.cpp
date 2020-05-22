// 例2.3
#include <iostream>
#include "sqlist.h"

using namespace std;
using namespace sqlist;

// O(n),O(1)
void delnode1(SqList *&L, ElemType x);

// O(n),O(1)
void delnode2(SqList *&L, ElemType x);

void delnode1(SqList *&L, ElemType x)
{
    int k = 0, i;

    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] != x)
        {
            L->data[k] = L->data[i];
            k++;
        }
    }
    L->length = k;
}

void delnode2(SqList *&L, ElemType x)
{
    int k = 0, i;

    for (i = 0; i < L->length; i++)
    {
        if (L->data[i] != x)
        {
            L->data[i - k] = L->data[i];
        }
        else
        {
            k++;
        }
    }
    L->length -= k;
}

int main()
{
    cout << "例2.3" << endl;
    cout << "sizeof(SqList) = " << sizeof(SqList) << endl;

    SqList *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);

    InsertList(L, 'a');
    InsertList(L, 'b');
    InsertList(L, 'c');
    InsertList(L, 'd');
    InsertList(L, 'e');

    cout << "此时顺序表的元素为: ";
    PrintList(L);

    cout << "该数据表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    ElemType e = 'c';
    cout << "删除所有值为" << e << "之后: ";
    delnode1(L, e);

    PrintList(L);

    e = 'd';
    cout << "删除所有值为" << e << "之后: ";
    delnode2(L, e);

    PrintList(L);

    return 0;
}