// Лабораторна робота № 5.2, варіант 30
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// 1-й спосіб: void-функції
void S_void(const double x, const double eps, int &n, double &s);
void A_void(const double x, const int n, double &a);

// 2-й спосіб: double-функції
double S_double(const double x, const double eps, int &n, double s);
double A_double(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps;
    double s1 = 0, s2 = 0;
    int n1 = 0, n2 = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "              Table of Arth(x) function" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x"
        << " |" << setw(10) << "Arth(x)"
        << " |" << setw(10) << "S (void)"
        << " |" << setw(5) << "n"
        << " |" << setw(10) << "S (double)"
        << " |" << setw(5) << "n" << " |" << endl;
    cout << "------------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        S_void(x, eps, n1, s1);           // 1-й спосіб
        s2 = S_double(x, eps, n2, s2);    // 2-й спосіб

        cout << "|" << setw(7) << setprecision(2) << x
            << " |" << setw(10) << setprecision(5) << atanh(x)
            << " |" << setw(10) << setprecision(5) << s1
            << " |" << setw(5) << n1
            << " |" << setw(10) << setprecision(5) << s2
            << " |" << setw(5) << n2 << " |" << endl;
        x += dx;
    }
    cout << "------------------------------------------------------------" << endl;
    return 0;
}

//  1-й спосіб: void-функції 
void S_void(const double x, const double eps, int& n, double& s)
{
    n = 0;
    double a = x;      
    s = a;
    do {
        n++;
        A_void(x, n, a);
        s += a;
    } while (abs(a) >= eps);
}

void A_void(const double x, const int n, double& a)
{
    double R = x * x * (2 * n - 1) / (2 * n + 1);
    a *= R;
}

//  2-й спосіб: double-функції 
double S_double(const double x, const double eps, int& n, double s)
{
    n = 0;
    double a = x;      
    s = a;
    do {
        n++;
        a = A_double(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A_double(const double x, const int n, double a)
{
    double R = x * x * (2 * n - 1) / (2 * n + 1);
    a *= R;
    return a;
}




//xp = -0.9
//xk = 0.9
//dx = 0.1
//eps = 0.0001