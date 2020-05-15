#include <iostream>
#include "clinklist.h"

using namespace std;
using namespace clinklist;

bool Symm(CLinkNode *&L);

bool Symm(CLinkNode *&L)
{
    bool same = true;
    CLinkNode *p = L->next;
    CLinkNode *q = L->prior;

    while (same)
    {
        if (p->data != q->data)
        {
            return false;
        }
        else
        {
            if (p == q || p == q->prior)
                break;
            p = p->next;
            q = q->prior;
        }
    }
    return same;
}

int main()
{
    cout << "例2.13 判断循环链表的对称性." << endl;
    cout << "sizeof(CLinkNode) = " << sizeof(CLinkNode) << endl;

    CLinkNode *L;
    // ElemType a[3] ={'a','b','c'};
    // int n = 3;
    // CreateList(L,a,n);

    InitalList(L);
    ElemType a[5] = {'a', 'b', 'a','b','a'};

    CreateListR(L, a, 5);

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    if (Symm(L))
        cout << "该链表是对称链表.";
    else
        cout << "该链表不是对称链表.";

    cout << endl<<endl;
    // FreeList(L);
    // cout << "释放链表完成!" << endl;

    return 0;
}