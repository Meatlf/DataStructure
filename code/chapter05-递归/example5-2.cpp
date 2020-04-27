// 例5.2
#include <iostream>
using namespace std;

double Min(double A[], int i)
{
    if (i == 0)
        return A[0];
    else
    {
        double min = Min(A, i - 1);
        if (min < A[i])
            return min;
        else
            return A[i];
    }
}

int main()
{
    cout << "例5.2" << endl;
    double A[8] = {3.1, 1.9, 2.3, 4.3, 5.3, 2.3, 4.4, 3.9};
    int i = 4;
    cout << Min(A, i) << endl;

    return 0;
}