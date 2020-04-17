#include <iostream>
#include "sqlist.h"

using namespace std;

int main()
{
    cout << "sizeof(SqList) = " << sizeof(SqList) << endl;

    SqList *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    // (1)初始化顺序表L
    InitalList(L);

    // (2)依次插入a,b,c,d,e元素
    InsertList(L, 'a');
    InsertList(L, 'b');
    InsertList(L, 'c');
    InsertList(L, 'd');
    InsertList(L, 'e');

    // (3)输出顺序表L
    cout << "此时顺序表的元素为: ";
    PrintList(L);

    // (4)输出顺序表L的长度
    cout << "该数据表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    cout << "位置为3的元素为: ";
    PrintElementViaLocation(L, 3);
    char b = 'b';
    cout << "字符a的位置为: " << PrintLocationViaElement(L, b) << endl;

    cout << "在位置为3的地方插入元素'f'之后的顺序表: " << endl;
    InsertElementInList(L, 3, 'f');
    PrintList(L);

    cout << "删掉位置4上的元素,此时顺序表为: " << endl;
    DeleteElementInList(L, 4);
    PrintList(L);

    return 0;
}