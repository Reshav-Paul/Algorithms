#include <iostream>
using namespace std;

class NewtonForward
{
    float *x, *y, *forwardDiffTable;
    float h;
    int nDataPoints;
    public :
        NewtonForward() {}
        NewtonForward(float, int);
        void takeInput();
        void genDiffTable();
        float findValue(float);
};

NewtonForward :: NewtonForward(float h, int n)
{
    NewtonForward :: h = h;
    nDataPoints = n;
    x = new float[nDataPoints];
    y = new float[nDataPoints];
    forwardDiffTable = new float[(nDataPoints) * (nDataPoints)];
}

void NewtonForward ::takeInput()
{
    int i;
    for(i = 0; i < nDataPoints; i++)
    {
        cout << "Enter x" << i << " : ";
        cin >> x[i];
        cout << "Enter y" << i << " : ";
        cin >> y[i];
    }
}

void NewtonForward ::genDiffTable()
{
    float* delta = new float[nDataPoints];
    int n, i, j, k, d;
    n = nDataPoints;
    d = n - 1;
    for(i = 0; i < n; i++)
    {
        delta[i] = y[i];
        for (j = 0; j < n - 1; j++)
        {
            forwardDiffTable[i*(n-1) + j] = 0;
        }
    }

    for(i = 0; i < n; i++)
    {
        k = i;
        for(j = 0; j < d; j++)
        {
            delta[j] = delta[j + 1] - delta[j];
            forwardDiffTable[k * (n - 1) + i] = delta[j];
            k++;
        }
        d--;
    }
    cout << "\nForward Difference Table : \n";
    for(i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            cout << forwardDiffTable[i * (n - 1) + j] << "\t";
        }
        cout << endl;
    }
}

float NewtonForward ::findValue(float xFind)
{
    genDiffTable();
    float min = ((x[0] - xFind) < 0)? xFind - x[0] : x[0] - xFind, temp;
    int i, minPos = 0;
    cout << endl << "0 " << min;
    for(i = 1; i < nDataPoints; i++)
    {
        temp = ((x[i] - xFind) < 0)? xFind - x[i] : x[i] - xFind;
        cout << endl << i << " " << temp;
        if(temp < min)
        {
            minPos = i;
            min = temp;
        }
    }
    cout << "min = " << x[minPos] << endl;
    float s = (xFind - x[minPos]) / h;
    float ret = y[minPos];
    int ctr = 1, fact = 1, deltaX = minPos, deltaY = 0;
    float prod = s;
    while(deltaX < nDataPoints - 1 && deltaY < nDataPoints - 1)
    {
        fact = fact * ctr;
        cout << " + " << prod << " * " <<  forwardDiffTable[deltaX * (nDataPoints - 1) + deltaY] <<  " / " << fact;
        ret += (prod * forwardDiffTable[deltaX * (nDataPoints - 1) + deltaY]) / fact;
        //cout << "prod = " << prod << "*" << (s - 1) << endl;
        prod *= (s - ctr);
        ctr++;
        deltaX++;
        deltaY++;
    }
    return ret;
}

int main() {
    int n;
    float h, x;
    cout << "Enter the Number of Data Points : ";
    cin >> n;
    cout << "Enter the Step Length : ";
    cin >> h;
    NewtonForward NF(h, n);
    NF.takeInput();
    cout << "Enter the Value Of x at which the function value is to be Found : ";
    cin >> x;
    float result = NF.findValue(x);
    cout << "\nResult = " << result;
    return 0;
}