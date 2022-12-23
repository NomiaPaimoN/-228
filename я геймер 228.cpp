#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>

using namespace std;
typedef double (*uf)(double, double, int&);
void tabl(double, double, double, double, uf, uf);
double y(double, double, int&);
double s(double, double, int&);


int main()
{
    setlocale(LC_ALL, "ru");
    double a = 0.1, b = 1, h = 0.1, ep = 0;
    cout << "Нажмите 1 для автоматического ввода\n";

    if (_getch() == '1') {
        cout << "Введите е: "; cin >> ep;
    }
    else {
        cout << "Введите a, b, h, e" << endl;
        cin >> a >> b >> h >> ep;
    }

    cout << setw(10) << "X" << setw(15) << "Y(x)" << setw(15) << "S(x)" << setw(8) << "k" << endl;
    tabl(a, b, h, ep, y, s);
    cout << endl;
    return 0;
}

void tabl(double a, double b, double h, double eps, uf fun, uf fun2) //OutRez
{
    int k = 0;
    double sum = 0, sum2 = 0;
    for (double x = a; x < b + h / 2; x += h)
    {
        sum = fun(x, eps, k);
        sum2 = fun2(x, eps, k);
        cout << setw(10) << x << setw(15) << sum << setw(15) << sum2 << setw(8) << k << endl;
    }
}

double y(double x, double eps, int& k)
{
    return exp(2 * x);
}

double s(double x, double eps, int& k)
{
    double p = 1, sum = 1;
    k = 1;
    while (fabs(p) > eps)
    {
        p *= 2 * x / k;
        sum += p;
        k++;
    }
    return sum;
}