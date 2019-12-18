#include<iostream>
using namespace std;

class GaussElimination{
	float a[10][10], x[10], b[10];
	int n;
	public:
		GaussElimination();
		void EliminationOperation();
		void DisplayMatrix();
		void DisplayResult();
};

GaussElimination :: GaussElimination(){
	cout << "Enter the no. of Equations : ";
	cin >> n;
	int i, j;
	cout << "Enter the elements of the coefficient Matrix A and the Matrix B where AX = B " << endl;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << "Enter the element A[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> a[i][j];
		}
		cout << "Enter the element B[" << i + 1 << "] : ";
		cin >> b[i];
	}
	system("cls");
}

void GaussElimination :: EliminationOperation(){
	float multi = 1, s = 0;
	int i, j, k;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			multi = a[j][i] / a[i][i];
			for(k = 0; k < n; k++){
				a[j][k] = a[j][k] - multi * a[i][k];	
			}
			b[j] = b[j] - multi * b[i];
		}
	}
	//Calculating the roots
	x[n - 1] = b[n - 1] / a[n - 1][n - 1];
	for(i = n - 2; i >= 0; i--){
		s = b[i];
		for(j = n - 1; j > i; j--){
			s = s - a[i][j] * x[j];
		}
		x[i] = s / a[i][i];
	}
}

void GaussElimination :: DisplayMatrix(){
	int i, j;
	cout << "The Matrix A after being reduced to a triangular matrix : " << endl;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << "\t" << a[i][j];
		}
		cout << endl;
	}
	cout << "The matrix B after corressponding operations as on A" << endl;
	for(i = 0; i < n; i++){
		cout << b[i] << endl;
	}
}

void GaussElimination :: DisplayResult(){
	int i;
	cout << "The roots of the System of Equations are : " << endl;
	for(i = 0; i < n; i++){
		cout << "x[" << i + 1 << "] =\t" << x[i] << endl;
	}
}

int main(){
	GaussElimination g;
	g.EliminationOperation();
	g.DisplayMatrix();
	g.DisplayResult();
	return 0;
}
