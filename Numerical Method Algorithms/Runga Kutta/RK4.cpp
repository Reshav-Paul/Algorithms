#include <cmath>
#include <iostream>
using namespace std;

class RK4
{
    float coeffX[10], coeffY[10], h;
    int nX, nY;
    public :
        RK4() {}
        RK4 (float);
        void getInput();
        float f(float, float);
        float calValue(float, float, int);
};

RK4 :: RK4(float h)
{
    RK4 :: h = h;
}

float RK4 :: f(float x, float y)
{
    /*int i;  float sum = 0;
    for(i = 0; i <= nX; i++)
    {
        sum += coeffX[i] * pow(x, i);
    }
    for(i = 0; i <= nY; i++)
    {
        sum += coeffY[i] * pow(y, i);
    }
    return sum;*/

    return (x* x +  y * y) / 10;
}

void RK4 :: getInput()
{
    int i;
    cout << "\nEnter Maximum Power of x in f(x, y) : ";
    cin >> nX;

    cout << "\nEnter Maximum Power of y in f(x, y) : ";
    cin >> nY;

    for(i = 0; i <= nX; i++)
    {
        cout << "\ncoefficient of x^" << i << " : ";
        cin >> coeffX[i];
    }

    for(i = 0; i <= nY; i++)
    {
        cout << "\ncoefficient of y^" << i << " : ";
        cin >> coeffY[i];
    }
}

float RK4 :: calValue(float initX, float initY, int n)
{
    float k1, k2, k3, k4;
    for(int i = 1; i <= n; i++)
    {
        k1 = h * f(initX, initY);
        k2 = h * f(initX + h * 0.5, initY + k1 * 0.5);
        k3 = h * f(initX + h * 0.5, initY + k2 * 0.5);
        k4 = h * f(initX + h, initY + k3);
        initY = initY + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        cout << "\ny(" << initX + h << ") = " << initY;
        initX += h;
    }
    return initY;
}

int main()
{
    float h, x, y, result;  int n;
    cout << "Enter the value of h : ";      cin >> h;
    RK4 r(h);
    cout << "\nEnter Initial Value of x : ";    cin >> x;
    cout << "\nEnter Initial Value of y : ";    cin >> y;
    cout << "\nEnter the no. of iterations : ";   cin >> n;
    r.getInput();
    result = r.calValue(x, y, n);
    return 0;
}
