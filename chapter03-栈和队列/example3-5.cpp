#include <iostream>
#include "stack.h"
#include "link_st_node.h"

using namespace std;
using namespace linknodestack;

bool Match(char exp[], int n)
{
    int i = 0;
    char e;
    LinkStNode *st;

    InitStack(st);
    while (i < n)
    {
        if (exp[i] == '(')
            Push(st, exp[i]);
        else if (exp[i] == ')')
        {
            if (!StackEmpty(st))
            {
                Pop(st, e);
                if (e != '(')
                    return false;
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    if (!StackEmpty(st))
        return false;
    DestoryStack(st);
    return true;
}

int main()
{
    cout << "例3.5:判断输入的表达式中括号是否配对(假设只含左,右圆括号)." << endl;
    cout << "sizeof(LinkStNode) = " << sizeof(LinkStNode) << endl;
    char exp0[] = {'(', '(', ')', ')'};
    int n0 = 4;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp0, n0) << endl;

    char exp1[] = {'(', ')', '(', '(', ')', ')'};
    int n1 = 6;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp1, n1) << endl;

    char exp2[] = {'(', ')', '(', ')', ')', ')'};
    int n2 = 6;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp2, n2) << endl;

    char exp3[] = {')', ')','(','('};
    int n3 = 4;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp3, n3) << endl;

    char exp4[] = {')', '('};
    int n4 = 2;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp4, n4) << endl;

    char exp5[] = {')', ')'};
    int n5 = 2;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp5, n5) << endl;

    char exp6[] = {'(', '('};
    int n6 = 2;
    cout << "如果匹配则输出1,否则输出0: " << Match(exp6, n6) << endl;

    return 0;
}