#include "MyMath.h"

// Загальний член суми: (1 + i/N) / i^2
double f(const int N, const int i)
{
    return (1 + 1. * i / N) / (1. * i * i);
}

// Ітераційний спосіб
double S0(const int K, const int N)
{
    double s = 0;
    for (int i = K; i <= N; i++)
        s += f(N, i);
    return s;
}

// Рекурсивний спуск, i зростає
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return f(N, i) + S1(K, N, i + 1);
}

// Рекурсивний спуск, i спадає
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 0;
    else
        return f(N, i) + S2(K, N, i - 1);
}

// Рекурсивний підйом, i зростає
double S3(const int K, const int N, const int i, double t)
{
    t = t + f(N, i);
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// Рекурсивний підйом, i спадає
double S4(const int K, const int N, const int i, double t)
{
    t = t + f(N, i);
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}