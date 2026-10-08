// Lab 5_1, варіант 30
#include <iostream>
#include <cmath>
using namespace std;

double t(const double x); 

int main()
{
    double z;
    cout << "z = "; cin >> z;

    double c = (t(1) + pow(t(t(1) + pow(t(t(1)), 2)), 2)) / (1 + sqrt(t(z + 1 + sqrt(t(z)))));

    cout << "c = " << c << endl;
    return 0;
}

double t(const double x) 
{
    return 1 + sqrt(1 + x * x);
}