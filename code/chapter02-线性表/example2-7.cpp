#include <iostream>
#include "linklist.h"

using namespace std;
using namespace linklist;

void sort(LinkNode *&L);

void sort(LinkNode *&L)
{
    LinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL)
    {
        LinkNode *q = p->next;
        LinkNode *pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}

int main()
{
    cout << "例2.7 链表元素递增排序." << endl;
    cout << "sizeof(LinkNode) = " << sizeof(LinkNode) << endl;

    LinkNode *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);

    InsertList(L, 'c');
    InsertList(L, 'b');
    InsertList(L, 'f');
    InsertList(L, 'd');
    InsertList(L, 'e');

    cout << "打印链表的元素: ";
    PrintList(L);

    cout << "该链表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    sort(L);
    cout << "打印排序之后的链表元素: ";
    PrintList(L);

    FreeList(L);
    cout << "释放链表完成!" << endl;

    return 0;
}