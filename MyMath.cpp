#include "MyMath.h"
#include <iostream>
using namespace std;

int f(const int n, const int level, int& depth)
{
    cout << "Рівень рекурсії: " << level << ", n = " << n << endl;

    if (level > depth)
        depth = level;

    if (n == 1)
        return 1;
    else if (n % 2 == 0)
        return 2 * f(n / 2, level + 1, depth) - 1;
    else
        return 2 * f(n / 2, level + 1, depth) + 1;
}