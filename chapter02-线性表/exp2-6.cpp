#include <iostream>
#include "linklist.h"

using namespace std;
using namespace linklist;
#define NUMBER 4

LinkNode *Divide(LinkNode *L, ElemType e);

LinkNode *Divide(LinkNode *L, ElemType e)
{
    LinkNode *L0 = (LinkNode *)malloc(sizeof(LinkNode));
    L0->next = NULL;

    LinkNode *p = L->next;
    LinkNode *q;
    LinkNode *t;
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));

    s = p;
    s->next = NULL;

    L0->next = s;
    t = s;

    p = p->next;

    while (p != NULL)
    {
        q = p->next;

        if (p->data <= e)
        {
            p->next = L0->next;
            L0->next = p;
        }
        else
        {
            s = p;
            s->next = NULL;
            t->next = s;
            t = p;
        }
        p = q;
    }
    return L0;
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

    LinkNode *L0 = Divide(L, 'e');
    PrintList(L0);

    FreeList(L);
    cout << "释放链表完成!" << endl;

    return 0;
}