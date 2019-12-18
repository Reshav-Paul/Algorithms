#include <iostream>
#include <iomanip>
using std :: cout;
using std :: cin;
using std :: setprecision;

class Trapezoidal
{
    double a, b, h;
    int n;
    public :
        Trapezoidal() { };
        Trapezoidal(double, double, int);
        double F(double);
        void Integrate();
};

inline Trapezoidal :: Trapezoidal(double a, double b, int n)
{
    Trapezoidal :: a = a;
    Trapezoidal :: b = b;
    Trapezoidal :: n = n;
    h = (b - a) / n;
}

double Trapezoidal :: F(double x)
{
    double f = 4 / (1 + x * x);
    return f;
}

void Trapezoidal :: Integrate()
{
    int iter = 1;
    double u, v, sum = 0;
    u = a + h;
    while(iter < n)
    {
        sum += 2 * F(u);
        u += h;
        iter++;
    }
    sum = 0.5 * h * (F(a) + F(b) + sum);
    cout << setprecision(9) << "Integral Value is = " << sum << "\n";
}

int main()
{
    double a, b, temp;
    int n;
    cout << "Enter the lower limit of the integration : ";          cin >> a;
    cout << "Enter the upper limit of the integration : ";          cin >> b;
    cout << "Enter the number of intervals for the integration : "; cin >> n;
    if(b < a)
    {
        temp = a;
        a = b;
        b = temp;
    }
    Trapezoidal t(0, 1, n);
    t.Integrate();
    return 0;
}
