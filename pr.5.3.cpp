// Лабораторна робота № 5.2, варіант 30
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double A(const double x, const int n, const double a);
double S(const double x, const double eps, int& n);

int main()
{
    double xp, xk, dx, eps;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "         Table of Arth(x) function" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x"
        << " |" << setw(10) << "Arth(x)"
        << " |" << setw(10) << "S"
        << " |" << setw(5) << "n" << " |" << endl;
    cout << "-----------------------------------------" << endl;

    double x = xp;
    int n;
    while (x <= xk)
    {
        double s = S(x, eps, n);
        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(5) << atanh(x)
            << " |" << setw(10) << setprecision(5) << s
            << " |" << setw(5) << n << " |" << endl;
        x += dx;
    }
    cout << "-----------------------------------------" << endl;
    return 0;
}

double A(const double x, const int n, const double a)
{
    // рекурентне співвідношення: a(n) = a(n-1) * x^2 * (2n-1)/(2n+1)
    return a * x * x * (2 * n - 1) / (2 * n + 1);
}

double S(const double x, const double eps, int& n)
{
    n = 0;
    double a = x;      // перший доданок
    double s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (fabs(a) >= eps);
    return s;
}