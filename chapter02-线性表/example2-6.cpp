#include <iostream>
#include "linklist.h"

using namespace std;
using namespace linklist;

void spilt(LinkNode *&L, LinkNode *&L1, LinkNode *&L2);

void spilt(LinkNode *&L, LinkNode *&L1, LinkNode *&L2)
{
    LinkNode *p = L->next, *q, *r1;

    L1 = L;
    r1 = L1; // r1始终指向L1的尾结点
    L2 = (LinkNode *)malloc(sizeof(LinkNode));
    L2->next = NULL;

    while (p != NULL)
    {
        r1->next = p;
        r1 = p;
        if (p->next == NULL)
            break;
        p = p->next;
        q = p->next;        // 头插法会修改结点p的next域,用q保存结点p的后继结点
        p->next = L2->next; // 采用头插法将结点p插入L2中
        L2->next = p;
        p = q;
    }
    r1->next = NULL;
}

int main()
{
    cout << "例2.6 拆分为2个链表." << endl;
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

    LinkNode *L1, *L2;
    spilt(L, L1, L2);
    cout << "拆分之后的链表L1: ";
    PrintList(L1);
    cout << "拆分之后的链表L2: ";
    PrintList(L2);

    FreeList(L);
    FreeList(L1);
    FreeList(L2);
    cout << "释放链表完成!" << endl;

    return 0;
}