// 实验题1:采用递归和非递归方法求解Hanoi问题
#include <iostream>
using namespace std;

void Hanoil(int n, char X, char Y, char Z)
{
    if (n == 1)
        cout << "将第" << n << "个盘片从" << X << "移动到" << Z << endl;
    else
    {
        Hanoil(n - 1, X, Z, Y);
        cout << "将第" << n << "个盘片从" << X << "移动到" << Z << endl;
        Hanoil(n - 1, Y, X, Z);
    }
}

int main()
{
    cout << "实验题1:采用递归和非递归方法求解Hanoi问题" << endl;

    int n = 3;
    char X = 'a';
    char Y = 'b';
    char Z = 'c';

    Hanoil(n, X, Y, Z);

    return 0;
}