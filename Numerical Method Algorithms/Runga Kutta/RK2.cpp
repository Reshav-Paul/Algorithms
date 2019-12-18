#include <cmath>
#include <iostream>
using namespace std;

class RK2
{
    float coeffX[10], coeffY[10], h;
    int nX, nY;
    public :
        RK2() {}
        RK2 (float);
        void getInput();
        float f(float, float);
        float calValue(float, float, int);
};

RK2 :: RK2(float h)
{
    RK2 :: h = h;
}

float RK2 :: f(float x, float y)
{
    int i;  float sum = 0;
    for(i = 0; i <= nX; i++)
    {
        sum += coeffX[i] * pow(x, i);
    }
    for(i = 0; i <= nY; i++)
    {
        sum += coeffY[i] * pow(y, i);
    }
    return sum;
}

void RK2 :: getInput()
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

float RK2 :: calValue(float initX, float initY, int n)
{
    float ret, k1, k2;
    for(int i = 1; i <= n; i++)
    {
        k1 = h * f(initX, initY);
        k2 = h * f(initX + h, initY + k1);
        ret = initY + (k1 + k2) / 2;
        cout << "\ny(" << initX + h << ") = " << ret;
        initY = ret;
        initX += h;
    }
    return ret;
}

int main()
{
    float h, x, y, result;  int n;
    cout << "Enter the value of h : ";      cin >> h;
    RK2 r(h);
    cout << "\nEnter Initial Value of x : ";    cin >> x;
    cout << "\nEnter Initial Value of y : ";    cin >> y;
    cout << "\nEnter the no. of iterations : ";   cin >> n;
    r.getInput();
    result = r.calValue(x, y, n);
    return 0;
}
