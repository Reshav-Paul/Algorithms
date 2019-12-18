#include <iostream>
#include <iomanip>
using std :: cout;
using std :: cin;
using std :: setprecision;

class Simpson
{
    float a, b, h;
    int n;
    public :
        Simpson() { };
        Simpson(float, float, int);
        float F(float);
        void Integrate();
};

inline Simpson :: Simpson(float a, float b, int n)
{
    Simpson :: a = a;
    Simpson :: b = b;
    Simpson :: n = n;
    h = (b - a) / n;
}

float Simpson :: F(float x)
{
    float f = 4 / (1 + x * x);
    return f;
}

void Simpson :: Integrate()
{
    float u, v, sum = 0;
    int i = 1;
    u = a + h;
    while(i < n)
    {
        if(i % 2 == 0)
            sum += 2 * F(u);
        else
            sum += 4 * F(u);
        u += h;
        i++;
    }
    sum = (h / 3) * (F(a) + F(b) + sum);
    cout << setprecision(9);
    cout << "Given Range : [" << a << ", " << b << "]\n";
    cout << "Using Simpson's 1/3rd rule\nIntegral Value is = " << sum << "\n";
}

int main()
{
    float a, b, temp;
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
    Simpson t(a, b, n);
    t.Integrate();
    return 0;
}

