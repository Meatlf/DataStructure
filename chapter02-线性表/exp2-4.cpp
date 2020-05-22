#include <iostream>
#include "dlinklist.h"

using namespace std;
using namespace dlinklist;
#define NUMBER 4

int main()
{
    cout << "实验题4:实现循环单链表的各种基本运算的算法." << endl;
    cout << "sizeof(DLinkNode) = " << sizeof(DLinkNode) << endl;

    DLinkNode *L;

    ElemType a[NUMBER] = {'a', 'b', 'c', 'd'};
    int n = NUMBER;

    cout << "头插法创建链表: ";
    CreateListF(L, a, n);
    PrintList(L);

    cout << "尾插法创建链表: ";
    CreateListR(L, a, n);
    PrintList(L);

    InitalList(L);

    InsertList(L, 1, 'a');
    InsertList(L, 1, 'b');
    InsertList(L, 1, 'c');
    InsertList(L, 1, 'd');
    InsertList(L, 1, 'e');

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
    int i = 3;
    cout << "在位置为" << i << "的地方插入元素" << e << "之后的顺序表: " << endl;
    InsertElementInList(L, i, 'f');
    PrintList(L);

    i = 4;
    cout << "删掉位置" << i << "上的元素,此时顺序表为: " << endl;
    DeleteElementInList(L, i, e);
    PrintList(L);

    FreeList(L);
    cout << "释放链表完成!" << endl;

    return 0;
}