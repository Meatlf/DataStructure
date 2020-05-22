#include <iostream>
#include "dlinklist.h"

using namespace std;
using namespace dlinklist;

void sort(DLinkNode *&L);

void sort(DLinkNode *&L)
{
    DLinkNode *p = L->next->next;
    L->next->next = NULL;
    while (p != NULL)
    {
        DLinkNode *q = p->next;
        DLinkNode *pre = L;
        while (pre->next != NULL && pre->next->data < p->data)
        {
            pre = pre->next;
        }
        p->next = pre->next;
        if (pre->next != NULL)
            pre->next->prior = p;
        pre->next = p;
        p->prior = pre;
        p = q;
    }
}

int main()
{
    cout << "例2.10 双链表元素递增排序." << endl;
    cout << "sizeof(DLinkNode) = " << sizeof(DLinkNode) << endl;

    DLinkNode *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);

    InsertList(L, 1, 'c');
    InsertList(L, 1, 'b');
    InsertList(L, 1, 'f');
    InsertList(L, 1, 'd');
    InsertList(L, 1, 'e');

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