#include <iostream>
using namespace std;

class GaussSeidel
{
    float A[10][10], b[10], x[10];
    int n;
    public :
        GaussSeidel(int);
        void GetInput();
        void FindRoots();
        void DisplayRoots();
};

GaussSeidel :: GaussSeidel(int n)
{
    GaussSeidel :: n = n;
}

void GaussSeidel :: GetInput()
{
    int i, j;
    cout << "Enter the elements of the matrices A and B where AX = B :\n";
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << "A[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i][j];
        }
        cout << "B[" << i + 1 << "] : ";
        cin >> b[i];
        x[i] = 0;
    }
}

void GaussSeidel :: FindRoots()
{
    GetInput();
    int i, j, nIter = 0;
    float diff = 1, eps = 0, sum = 0, prev;
    while(1)
    {
        nIter++;
        for(i = 0; i < n; i++)
        {
            sum = b[i];
            prev = x[i];
            for(j = 0; j < n; j++)
            {
                if(i != j)
                    sum -= A[i][j]*x[j];
            }
            x[i] = sum / A[i][i];
            diff = x[i] - prev;
            if(diff < 0)
                diff = -diff;
            if(i == 0)
                eps = diff;
            else if(eps < diff)
                eps = diff;
        }
        if(eps <= 1e-6)
            break;
    }
    DisplayRoots();
    cout << "\nNumber of Iterations : " << nIter;
}

void GaussSeidel :: DisplayRoots()
{
    cout << "The roots are : ";
    for(int i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "] = " << x[i] << "\n";
    }
}

int main()
{
    int n;
    cout << "Enter The Number of Equations : ";
    cin >> n;
    GaussSeidel g(n);
    g.FindRoots();
    return 0;
}
