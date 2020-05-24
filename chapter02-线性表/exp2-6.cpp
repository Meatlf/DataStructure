#include <iostream>
#include "linklist.h"

using namespace std;
using namespace linklist;
#define NUMBER 4

// 要点:
// 1) 前插法: 较小的值头插法
// 2) 后插法: 较大的值尾插法
// 3) 所需创建的指针: 遍历节点p,链表尾节点r和头插法所需的防止"失联"的节点q.
void Split(LinkNode *&L, ElemType x);

void Split(LinkNode *&L, ElemType x)
{
    LinkNode *p, *r, *q;
    p = L->next;
    L->next = NULL;
    r = L;

    while (p != NULL)
    {
        if (p->data < x) // 较小的值头插法
        {
            q = p->next;
            p->next = L->next;
            L->next = p;
            if (p->next == NULL)
                r = p;
            p = q;
        }
        else
        {
            r->next = p;
            r = p;
            p = p->next;
        }
    }
    r->next = NULL;
}

int main()
{
    cout << "实验题6:将单链表按基准划分." << endl;
    cout << "sizeof(LinkNode) = " << sizeof(LinkNode) << endl;

    LinkNode *L;

    ElemType a[NUMBER] = {'a', 'b', 'c', 'd'};
    int n = NUMBER;

    cout << "头插法创建链表: ";
    CreateListF(L, a, n);
    PrintList(L);

    cout << "尾插法创建链表: ";
    CreateListR(L, a, n);
    PrintList(L);

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
    ElemType x;
    GetElementViaLocation(L, 3, x);
    cout << x << endl;

    x = 'a';
    cout << "字符" << x << "的位置为: " << GetLocationViaElement(L, x) << endl;

    x = 'f';
    int location = 3;
    cout << "在位置为" << location << "的地方插入元素" << x << "之后的顺序表: " << endl;
    InsertElementInList(L, location, 'f');
    PrintList(L);

    location = 4;
    cout << "删掉位置" << location << "上的元素,此时顺序表为: " << endl;
    DeleteElementInList(L, location, x);
    PrintList(L);

    Split(L, 'e');
    cout << "将单链表按基准划分后的链表为: " << endl;
    PrintList(L);

    FreeList(L);
    cout << "释放链表完成!" << endl;

    return 0;
}