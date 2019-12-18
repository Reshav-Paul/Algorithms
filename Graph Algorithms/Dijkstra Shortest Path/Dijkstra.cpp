#include<iostream>
using namespace std;

class Dijkstra{
	int weight[10][10], D[10];
	int n;
	public:
		Dijkstra(){n = 0;}
		Dijkstra(int);
		void findD(int, int);
};

Dijkstra::Dijkstra(int s){
	n = s;
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			cout << "Weight[" << i + 1 << "][" << j + 1 << "] : ";
			cin >> weight[i][j];
		}
	}
}

void Dijkstra::findD(int s, int d){
	int i, j, k, min, minPos, basis[10];
	for(i = 0; i < n; i++){
		if(i != s){
			D[i] = (weight[s][i] == 0)? -1 : weight[s][i];
		}
	}
	D[s] = -1;
	int ctr = 0;
	basis[ctr++] = s;
	for(i = 0; i < n - 2; i++){
	
		min = -1;
		for(j = 0; j < n; j++){
			for(k = 0; k < ctr; k++){
				if(basis[k] == j)
					break;
			}
			if(j != s && k == ctr){
				if(min < 0 && D[j] > 0){
					min = D[j];
					minPos = j;
				}
				else if(min > 0 && min > D[j] && D[j] > 0){
					min = D[j];
					minPos = j;
				}
			}
		}
		basis[ctr++] = minPos;
		for(j = 0; j < n; j++){
			for(k = 0; k < ctr; k++){
				if(basis[k] == j)
					break;
			}
			if(j != s && k == ctr){
				if(weight[minPos][j] > 0){
					if(D[j] > 0)
						D[j] = (D[j] < (D[minPos] + weight[minPos][j]))? D[j] : D[minPos] + weight[minPos][j];
					else
						D[j] = D[minPos] + weight[minPos][j];
				}
			}
		}
	}
	for(i = 0; i < n; i++){
		if(i != s)
			cout << endl << s << " -> " << i << " = "  << D[i];
	}
	cout << endl;
}

int main(){
	system("clear");
	Dijkstra d(4);
	d.findD(2, 4);
	return 0;
}