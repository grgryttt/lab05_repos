// Лабораторна робота № 5.5, варіант 30
#include <iostream>
#include <windows.h>
#include "MyMath.h"
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);   
    SetConsoleCP(65001);         

    int n;
    cout << "n = "; cin >> n;

    int m = n;                 // кількість людей у поточному раунді
    int depth = 0;
    int x = f(m, 0, depth);    // перша ітерація
    cout << "Глибина рекурсії: " << depth << endl;
    cout << "Після першої ітерації залишився: " << x << endl << endl;

    int count = 0;             // кількість повторень після першої ітерації

    while (x != m)
    {
        m = x;
        depth = 0;
        x = f(m, 0, depth);
        count++;
        cout << "Глибина рекурсії: " << depth << endl;
        cout << "Повторення " << count << ": кількість людей " << m
            << ", залишився номер " << x << endl << endl;
    }

    cout << "Кількість повторень після першої ітерації: " << count << endl;
    cout << "Номер людини, яка залишилась: " << x << endl;

    return 0;
}