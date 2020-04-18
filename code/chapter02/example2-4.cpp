// 例2.4
#include <iostream>
#include "sqlist.h"

using namespace std;

// O(n),O(1)
void partion2(SqList *&L);

void partion2(SqList *&L)
{
    int i = 0, j = L->length - 1;
    ElemType pivot = L->data[0];

    while (i < j)
    {
        while (j > i && L->data[j] > pivot) // 这里的j > i,容易遗漏
            j--;
        L->data[i] = L->data[j];

        while (i < j && L->data[i] <= pivot) // 这里的i < j,容易遗漏
            i++;
        L->data[j] = L->data[i];
    }
    L->data[i] = pivot;
}

int main()
{
    cout << "例2.4" << endl;
    cout << "sizeof(SqList) = " << sizeof(SqList) << endl;

    SqList *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);

    InsertList(L, 'c');
    InsertList(L, 'd');
    InsertList(L, 'b');
    InsertList(L, 'e');
    InsertList(L, 'a');

    cout << "此时顺序表的元素为: ";
    PrintList(L);

    cout << "该数据表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    cout << "以第一个元素为基准,将比其小的元素放在前面,比其大的元素放在后面: ";
    partion2(L);

    PrintList(L);

    return 0;
}