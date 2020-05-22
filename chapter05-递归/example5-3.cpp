// 例5.3
#include <iostream>
#include "sqlist.h"

using namespace std;
using namespace sqlist;

ElemType Max(SqList L, int i, int j)
{
    int mid;
    ElemType max, max1, max2;
    if (i == j)
        max = L.data[i];
    else
    {
        mid = (i + j) / 2;
        max1 = Max(L, i, mid);
        max2 = Max(L, mid + 1, j);
        max = (max1 > max2) ? max1 : max2;
    }
    return max;
}

int main()
{
    cout << "例5.3" << endl;
    cout << "sizeof(SqList) = " << sizeof(SqList) << endl;

    SqList *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);

    InsertList(L, 'a');
    InsertList(L, 'f');
    InsertList(L, 'c');
    InsertList(L, 'd');
    InsertList(L, 'b');

    cout << "此时顺序表的元素为: ";
    PrintList(L);

    cout << "该数据表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    cout << Max(*L, 0, 4) << endl;
    PrintList(L);

    return 0;
}