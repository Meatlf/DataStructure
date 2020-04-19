#include <iostream>
#include "linklist.h"

using namespace std;
using namespace linklist;

int main()
{
    cout << "实验题2:实现单链表的各种基本运算的算法." << endl;
    cout << "sizeof(LinkNode) = " << sizeof(LinkNode) << endl;

    LinkNode *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);

    InsertList(L, 'a');
    InsertList(L, 'b');
    InsertList(L, 'c');
    InsertList(L, 'd');
    InsertList(L, 'e');

    cout << "打印链表的元素: ";
    PrintList(L);

    cout << "该链表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    cout << "位置为3的元素为: ";
    ElemType e;
    GetElementViaLocation(L, 3, e);
    cout << e << endl;

    e = 'a';
    cout << "字符" << e << "的位置为: " << GetLocationViaElement(L, e) << endl;

    e = 'f';
    int location = 3;
    cout << "在位置为" << location << "的地方插入元素" << e << "之后的顺序表: " << endl;
    InsertElementInList(L, location, 'f');
    PrintList(L);

    location = 4;
    cout << "删掉位置" << location << "上的元素,此时顺序表为: " << endl;
    DeleteElementInList(L, location, e);
    PrintList(L);

    FreeList(L);
    cout << "释放链表完成!" << endl;

    return 0;
}