#include <iostream>
#include "sqlist.h"

using namespace std;
using namespace sqlist;

int main()
{
    cout << "实验题1:实现顺序表的各种基本运算的算法." << endl;
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

    cout << "位置为3的元素为: ";
    ElemType e;
    GetElementViaLocation(L, 3, e);
    cout << e<<endl;

    char b = 'b';
    cout << "字符b的位置为: " << GetLocationViaElement(L, b) << endl;

    cout << "在位置为3的地方插入元素'f'之后的顺序表: " << endl;
    InsertElementInList(L, 3, 'f');
    PrintList(L);

    cout << "删掉位置4上的元素,此时顺序表为: " << endl;
    DeleteElementInList(L, 4);
    PrintList(L);

    return 0;
}