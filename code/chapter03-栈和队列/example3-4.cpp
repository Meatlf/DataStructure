#include <iostream>
#include "stack.h"

using namespace std;
using namespace sqstack;

bool symmetry(ElemType str[])
{
    int i = 0;
    ElemType e;
    SqStack *st;
    InitStack(st);

    while (str[i] != '\0')
    {
        if (!sqstack::Push(st, str[i++]))
        {
            sqstack::DestoryStack(st);
            return false;
        }
    }
    i = 0;
    while (str[i] != '\0')
    {
        if (!sqstack::Pop(st, e) || str[i++] != e)
        {
            sqstack::DestoryStack(st);
            return false;
        }
    }
    sqstack::DestoryStack(st);
    return true;
}

int main()
{
    cout << "例3.4:利用顺序栈判断一个字符串是否为对称串." << endl;
    cout << "sizeof(SqStack) = " << sizeof(SqStack) << endl;

    ElemType str0[4] = {'a', 'b', 'c', 'd'};
    cout << "如果是对称串则返回1,否则返回0: " << symmetry(str0) << endl;

    ElemType str1[4] = {'a', 'b', 'b', 'a'};
    cout << "如果是对称串则返回1,否则返回0: " << symmetry(str1) << endl;

    return 0;
}