#include <iostream>
#include <windows.h>
using namespace std;

class Lagrange
{
    float *y, *x, targetX;
    int numPoints;
    public :
        Lagrange() { };
        Lagrange(int, float);
        void getInput();
        void findY();
};

Lagrange :: Lagrange(int n, float X)
{
    numPoints = n;
    y = new float[numPoints + 1];
    x = new float[numPoints + 1];
    targetX = X;
}

void Lagrange :: getInput()
{
    int i;
    cout << "\nEnter The X values and the corresponding X values : \n";
    for(i = 0; i < numPoints; i++)
    {
        cout << "\nEnter x(" << i << ") : ";
        cin >> x[i];
        cout << "Enter y(" << i << ") : ";
        cin >> y[i];
    }
}

void Lagrange :: findY()
{
    getInput();
    int i, j;
    float numerator = 1, denominator = 1, sum = 0;
    for(i = 0; i < numPoints; i++)
    {
        numerator = 1;
        denominator = 1;
        for(j = 0; j < numPoints; j++)
        {
            if(j != i)
            {
                numerator *= (targetX - x[j]);
                denominator *= (x[i] - x[j]);
            }
        }
        sum += (numerator / denominator) * y[i];
    }
    cout << "\n\nEstimated Value of Y = " << sum;
}

int main()
{
    int n;
    float x;
    cout << "Enter no. of points for Interpolation : ";
    cin >> n;
    if(n <= 0)
    {
        cout << "\nNo. of intervals cannot be 0 or negative\n";
        exit(1);
    }
    cout << "\nEnter the value of X at which the value of Y has to be calculated : ";
    cin >> x;
    Lagrange l(n, x);
    l.findY();
    return 0;
}

