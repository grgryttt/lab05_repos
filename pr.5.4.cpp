// Лабораторна робота № 5.4/ 30 варіант
#include <iostream>
#include "MyMath.h"
using namespace std;

int main()
{
    int K, N;
    cout << "K = "; cin >> K;
    cout << "N = "; cin >> N;

    cout << "(iter)        S0 = " << S0(K, N) << endl;
    cout << "(rec up ++)   S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --)   S2 = " << S2(K, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(K, N, K, 0) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, N, 0) << endl;

    return 0;
}