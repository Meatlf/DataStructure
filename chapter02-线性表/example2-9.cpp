#include <iostream>
#include "dlinklist.h"

using namespace std;
using namespace dlinklist;
#define NUMBER 4

void reverseV1(DLinkNode *&L)
{
    DLinkNode *p = L->next, *temp;
    temp = p->next;
    p->next = NULL;
    p->prior = temp;
    p = temp;
    while (p->next != NULL)
    {
        temp = p->next;
        p->next = p->prior;
        p->prior = temp;
        p = temp;
    }
    p->next = p->prior;
    L->next = p;
    p->prior = L;
}

// 头插法
void reverseV2(DLinkNode *&L)
{
    DLinkNode *p = L->next, *q;

    L->next = NULL;

    while (p != NULL)
    {
        q = p->next;
        p->next = L->next;
        if (L->next != NULL)
            L->next->prior = p;
        L->next = p;
        p->prior = L;
        p = q;
    }
}

int main()
{
    cout << "例2.9:双向链表的逆序表示." << endl;
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
    InsertList(L, 1, 'f');

    cout << "打印链表的元素: ";
    PrintList(L);

    cout << "该链表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    reverseV1(L);
    cout << "翻转后的链表: ";
    PrintList(L);

    reverseV2(L);
    cout << "翻转后的链表: ";
    PrintList(L);

    FreeList(L);
    cout << "释放链表完成!" << endl;

    return 0;
}