#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

class Jacobi{
    double *matrix, *eigenValues, *p, *pTranspose;
    int n;
public:
    Jacobi();
    explicit Jacobi(int);
    void findMaxElement(int&, int&);
    void transpose();
    void getP(int, int, double);
    void findEigenValues();
    void getNewA();
};

Jacobi::Jacobi() {
    matrix = eigenValues = p = pTranspose = nullptr;
    n = 0;
}

Jacobi::Jacobi(int s) {
    n = s;
    matrix = new double [n * n];
    p = new double [n * n];
    pTranspose = new double [n * n];
    eigenValues = new double [n];
    int i, j;
    cout << "Enter the elements of the matrix : \n";
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << "\nMatrix(" << i + 1 << ", " << j + 1 <<") : ";
            cin >> matrix[i * n + j];
        }
    }
}

void Jacobi::findMaxElement(int &maxI, int &maxJ) {
    int i, j;
    double max = matrix[1];
    maxI = 0; maxJ = 1;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(abs(max) < abs(matrix[i * n + j])){
                max = matrix[i * n + j];
                maxI = i;
                maxJ = j;
            }
        }
    }
}

void Jacobi::transpose() {
    int i, j;
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            pTranspose[j * n + i] = p[i * n + j];
        }
    }
}

void Jacobi::getP(int posI, int posJ, double rad) {
    double cosine = cos(rad);
    double sine = sin(rad);
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(i == j)
                p[i * n + j] = 1;
            else
                p[i * n + j] = 0;
        }
    }
    p[posI * n + posI] = p[posJ * n + posJ] = cosine;
    p[posI * n + posJ] = -sine;
    p[posJ * n + posI] = sine;
}

void Jacobi::getNewA() {
    int i, j, k;
    const int size = n;
    double  temp[size][size];

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            temp[i][j] = 0;
            for(k = 0; k < n; k++){
                temp[i][j] += pTranspose[i * n + k] * matrix[k * n + j];
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matrix[i * n + j] = 0;
            for(k = 0; k < n; k++){
                matrix[i * n + j] += temp[i][k] * p[k * n + j];
            }
        }
    }
}

void Jacobi::findEigenValues() {
    bool shouldExit = false;
    int maxI, maxJ, i, j;
    double theta;
    double a;
    findMaxElement(maxI, maxJ);
    while(!shouldExit) {
        a = (2 * matrix[maxI * n + maxJ]) / (matrix[maxI * n + maxI] - matrix[maxJ * n + maxJ]);
        theta = atan(a) / 2;
        getP(maxI, maxJ, theta);
        transpose();
        getNewA();
        findMaxElement(maxI, maxJ);
        if(abs(matrix[maxI * n + maxJ]) < 1e-5)
            shouldExit = true;
    }
    cout << "Result : \n";
    for(i = 0; i < n; i++) {
        eigenValues[i] = matrix[i * n + i];
        cout << "\n" << eigenValues[i];
    }
}

int main() {
    Jacobi j(4);
    j.findEigenValues();
    return 0;
}