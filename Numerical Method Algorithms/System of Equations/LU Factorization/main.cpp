#include <iostream>
using namespace std;

class MatrixFactorization
{
    float *A, *X, *B, *L, *U, *Y;
    int numOfEq;
    public:
        MatrixFactorization() {}
        MatrixFactorization(int);
        void factorize();
        void getResult();
};

MatrixFactorization :: MatrixFactorization(int n) {
    int i, j;
    numOfEq = n;
    A = new float[numOfEq * numOfEq];
    X = new float[numOfEq];
    B = new float[numOfEq];
    L = new float[numOfEq * numOfEq];
    U = new float[numOfEq * numOfEq];
    Y = new float[numOfEq];

    for(i = 0; i < numOfEq; i++){
        for(j = 0; j < numOfEq; j++){
            cout << "\nEnter the Value of A[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i * numOfEq + j];
            U[i * numOfEq + j] = A[i * numOfEq + j];
            if(i == j)
                L[i * numOfEq + j] = 1;
            else
                L[i * numOfEq + j] = 0;
        }
        X[i] = 0;
        Y[i] = 0;
        cout << "\nEnter the value of B[" << i + 1 << "] : ";
        cin >> B[i];
    }
}

void MatrixFactorization :: factorize() {
    int i, j, k;
    float mul;
    for(i = 0; i < numOfEq; i++){
        for(j = i + 1; j < numOfEq; j++){
            mul = U[j * numOfEq + i] / U[i * numOfEq + i];
            L[j * numOfEq + i] = mul;
            for(k = 0; k < numOfEq; k++){
                U[j * numOfEq + k] = U[j * numOfEq + k] - U[i * numOfEq + k] * mul;
            }
        }
    }
}

void MatrixFactorization :: getResult() {
    int i, j;
    float sum = 0;

    factorize();
    Y[0] = B[0] / L[0];
    for(i = 1; i < numOfEq; i++){
        sum = B[i];
        for(j = 0; j < numOfEq; j++){
            if(i != j)
                sum -= L[i * numOfEq + j] * Y[j];
        }
        Y[i] = sum / L[i * numOfEq + i];
    }

    X[numOfEq - 1] = Y[numOfEq - 1] / U[(numOfEq - 1) * numOfEq + (numOfEq - 1)];
    for(i = numOfEq - 2; i >= 0; i--){
        sum = Y[i];
        for(j = numOfEq - 1; j > i; j--){
            if(i != j)
                sum -= U[i * numOfEq + j] * X[j];
        }
        X[i] = sum / U[i * numOfEq + i];
    }

    cout << "\n";
    for(j = 0; j < numOfEq; j++){
        cout << "X[" << j + 1 << "] = " <<  X[j] << "\n";
    }
}

int main() {

    MatrixFactorization M(3);
    M.getResult();
    return 0;
}