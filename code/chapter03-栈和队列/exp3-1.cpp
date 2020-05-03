#include <iostream>
#include "stack.h"

using namespace std;
using namespace sqstack;

int main()
{
    cout << "实验题1:实现顺序栈的各种基本运算的算法." << endl;
    cout << "sizeof(SqStack) = " << sizeof(SqStack) << endl;

    ElemType str[4] = {'a', 'b', 'c', 'd'};

    SqStack *st;

    sqstack::InitStack(st);
    cout << "栈是否为空,空则输出1,非空则输出0: " << sqstack::StackEmpty(st) << endl;

    int i = 0;
    while (str[i] != '\0')
    {
        sqstack::Push(st, str[i]);
        cout << "Push栈中的元素: " << str[i++] << endl;
    }
    cout << "栈是否为空,空则输出1,非空则输出0: " << sqstack::StackEmpty(st) << endl;
    ElemType e;
    while (!sqstack::StackEmpty(st))
    {
        sqstack::Pop(st, e);
        cout << "Pop栈中的元素: " << e << endl;
    }
    cout << "栈是否为空,空则输出1,非空则输出0: " << sqstack::StackEmpty(st) << endl;
    sqstack::DestoryStack(st);
    return 0;
}