// 例5.4 使用递归法释放链表中的所有结点
#include <iostream>
#include "linklist.h"

using namespace std;
using namespace linklist;

void release(LinkNode *&L)
{
    if (L != NULL)
    {
        release(L->next);
        free(L);
    }
}

int main()
{
    cout << "例5.4 使用递归法释放链表中的所有结点" << endl;
    cout << "sizeof(LinkNode) = " << sizeof(LinkNode) << endl;

    LinkNode *L;

    ElemType a[3] = {'a', 'b', 'c'};
    int n = 3;
    CreateListR(L, a, n);

    cout << "此时顺序表的元素为: ";
    PrintList(L);

    cout << "该数据表的长度为: " << ListLength(L) << endl;

    if (IsNullList(L) == true)
        cout << "该链表是空链表!" << endl;
    else
        cout << "该链表不是空链表!" << endl;

    cout << "打印当前链表: ";
    PrintList(L);

    release(L);
    L = NULL;
    cout << "是否为空链表,空则输出1,非空则输出0: " << IsNullList(L) << endl;

    return 0;
}