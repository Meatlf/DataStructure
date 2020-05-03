#include <iostream>
#include "stack.h"
#include "link_st_node.h"

using namespace std;
using namespace linknodestack;

int main()
{
    cout << "实验题2:实现链栈的各种基本运算的算法." << endl;
    cout << "sizeof(LinkStNode) = " << sizeof(LinkStNode) << endl;

    ElemType str[4] = {'a', 'b', 'c', 'd'};

    LinkStNode *st;

    InitStack(st);
    cout << "栈是否为空,空则输出1,非空则输出0: " << StackEmpty(st) << endl;

    int i = 0;
    while (str[i] != '\0')
    {
        Push(st, str[i]);
        cout << "Push栈中的元素: " << str[i++] << endl;
    }
    cout << "栈是否为空,空则输出1,非空则输出0: " << StackEmpty(st) << endl;
    ElemType e;
    while (!StackEmpty(st))
    {
        Pop(st, e);
        cout << "Pop栈中的元素: " << e << endl;
    }
    cout << "栈是否为空,空则输出1,非空则输出0: " << StackEmpty(st) << endl;
    DestoryStack(st);
    return 0;
}