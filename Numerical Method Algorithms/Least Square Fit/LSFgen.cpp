#include<iostream>
#include<cmath>
using namespace std;

class LeastSquareFit{
	float X[10], Y[10], M[10][10], C[10], rhs[10];
	int n, degree;
		public:
			float a, b;
			LeastSquareFit(){}
			LeastSquareFit(int, int);
			void findLine();
};

LeastSquareFit::LeastSquareFit(int s, int d){
	n = s;
	degree = d;
	int i, j;
	for(i = 0; i < n; i++){
		cout << "Enter X" << i + 1 << " : ";
		cin >> X[i];
		cout << "Enter Y" << i + 1 << " : ";
		cin >> Y[i];
		C[i] = 0;
		rhs[i] = 0;
		for(j = 0; j < degree + 1; j++){
			M[i][j] = 0;	
		}
	}
}

void LeastSquareFit::findLine(){
	float mul;
	int i, j, k;
	for(i = 0; i < degree + 1; i++){
		for(j = 0; j < degree + 1; j++){
			for(k = 0; k < n; k++){
				M[i][j] = M[i][j] + pow(X[k], i + j);
			}
		}
		for(k = 0; k < n; k++){
			rhs[i] = rhs[i] + Y[k] * pow(X[k], i);
		}
	}
	
	for(i = 0; i < degree + 1; i++){
		for(j = i + 1; j < degree + 1; j++){
			mul = M[j][i] / M[i][i];
			for(k = 0; k < degree + 1; k++){
				M[j][k] = M[j][k] - mul * M[i][k];
			}
			rhs[j] = rhs[j] - mul * rhs[i];
		}
	}
	
	C[degree] = rhs[degree] / M[degree][degree];
	for(i = degree - 1; i >= 0; i--){
		C[i] = rhs[i];
		for(j = degree; j > i; j--){
			C[i] = C[i] - M[i][j] * C[j];
		}
		C[i] = C[i] / M[i][i];
	}
	cout << C[0];
	for(i = 1; i < degree + 1; i++){
		cout << " + " << C[i] << "x^" << i;
	}
	cout << endl;
}

int main(){
	system("clear");
	LeastSquareFit l(4, 3);
	l.findLine();
	return 0;
}