#include <iostream>
using namespace std;

class MatrixInversion{
	float a[10][10], id[10][10], x[10], b[10];
	int n;
	public:
		MatrixInversion();
		void InversionOperation();
		void DisplayMatrix();
		void DisplayResult();
};

MatrixInversion :: MatrixInversion(){
	
	int i, j, k;
	cout << "Enter the Number of Equations (Max : 10) : ";
	cin >> n;
	cout << "\nThe Matrix format used is : AX = B" << endl;
	cout << "\nEnter the elements of the Coeffiecient Matrix A : " << endl;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << "Enter the element A[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> a[i][j];
			
			if(i == j){
				id[i][j] = 1;
			}
			else{
				id[i][j] = 0;
			}
		}
		cout << "Enter the element B[" << i + 1  << "] : ";
		cin >> b[i];
		cout << endl;
	}
	system("cls");
}

void MatrixInversion :: InversionOperation(){
	int i, j, k; float temp;
	for(i = 0; i < n; i++){
		temp = a[i][i];
		for(k = 0; k < n; k++){
			a[i][k] = a[i][k] / temp;
			id[i][k] = id[i][k] / temp;
		}

		for(j = 0; j < n; j++){
			if(j != i){
				temp = a[j][i];
				for(k = 0; k < n; k++){
					a[j][k] = a[j][k] - a[i][k] * temp;
					id[j][k] = id[j][k] - id[i][k] * temp;
				}
			}
		}
	}
	
	for(i = 0; i < n; i++){
		x[i] = 0;
		for(j = 0; j < n; j++){
			x[i] = x[i] + id[i][j] * b[j];
		}
	}
}

void MatrixInversion :: DisplayMatrix(){
	
	int i, j;
	cout << "The inverse of the coefficient matrix A is : " << endl;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << id[i][j] << "\t";
		}
	cout << endl;
	}
	DisplayResult();
}

void MatrixInversion :: DisplayResult(){
	int i;
	cout << endl;
	for(i = 0; i < n; i++){
		cout << "x[" << i + 1 << "] = " << x[i] << endl;
	}
}

int main(){
	MatrixInversion M;
	M.InversionOperation();
	M.DisplayMatrix();
	return 0;
}
