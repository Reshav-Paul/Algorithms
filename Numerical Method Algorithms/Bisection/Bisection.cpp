#include <iostream>
#include <cmath>
using namespace std;

class Bisection
{
    float coeff[11], x[11], a, b;
    int n, nRoots;
    public :
        Bisection() { };
        Bisection(float, float);
        float F(float);
        void InputEquation();
        void FindRoots();
        void Display();
};

inline Bisection :: Bisection(float a, float b)
{
    Bisection :: a = a;
    Bisection :: b = b;
    nRoots = 0;
}

float Bisection :: F(float x)
{
    float ret = 0;
    for(int i = 0; i <= n; i++)
    {
        ret += pow(x, i)*coeff[i];
    }
    return ret;
}

void Bisection :: InputEquation()
{
    cout << "\nEnter the degree of the Equation : ";      cin >> n;
    for(int i = 0; i <= n; i++)
    {
        cout << "\nEnter Coefficient of x^" << i << " : ";
        cin >> coeff[i];
    }
}

void Bisection :: FindRoots()
{
    float i, j, mid, diff, u, l;
    int index = 0;
    InputEquation();
    for(i = a; i < b; i = i + 0.01)
    {
        j = i + 0.01;
        if(F(i)*F(j) < 0)
        {
            l = i;  u = j;
            mid = (l + u) / 2;
            while((u - l) > 1e-6)
            {
                x[index] = mid;
                if(F(mid)*F(l) < 0)
                    u = mid;
                else
                    l = mid;
                mid = (l + u) / 2;
            }
            index++;
            nRoots = index;
        }
    }
    Display();
}

void Bisection :: Display()
{
    if(nRoots == 0)
    {
        cout << "\nNo Roots Found..";
        return;
    }
    cout << "The roots are :" << x[0] << "\n";
    for(int i = 1; i < nRoots; i++)
    {
        cout << "\t\t" << x[i] << "\n";
    }
}

int main()
{
    float a, b;
    cout << "Enter the lower Limit of the range : ";        cin >> a;
    cout << "\nEnter the upper Limit of the range : ";      cin >> b;
    Bisection bs(a, b);
    bs.FindRoots();
    return 0;
}
