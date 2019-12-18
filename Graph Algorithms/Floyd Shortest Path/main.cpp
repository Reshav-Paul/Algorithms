#include <iostream>
using namespace std;

class Floyd{
    float *weight, *cost;
    int n;
public:
    Floyd();
    Floyd(int);
    void findMinCostMatrix();
};

Floyd::Floyd() {
    n = 0;
    weight = cost = nullptr;
}

Floyd::Floyd(int s) {
    n = s;
    weight = new float[n * n];
    cost = new float[n * n];
    int i, j;
    cout << "\nEnter the elements of the Weight Matrix";
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << "\nEnter Weight[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> weight[i * n + j];
            if(weight[i * n + j] == 0)
                cost[i * n + j] = -1;
            else
                cost[i * n + j] = weight[i * n + j];
        }
    }
}

void Floyd::findMinCostMatrix() {
    int i, j, k;
    float orgCost, newCost;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (j != i && k != i) {
                    orgCost = cost[j * n + k];
                    if ((cost[j * n + i] != -1) && (cost[i * n + k] != -1)) {
                        newCost = cost[j * n + i] + cost[i * n + k];
                        if(orgCost < 0)
                            cost[j * n + k] = newCost;
                        else
                            cost[j * n + k] = (orgCost < newCost) ? orgCost : newCost;
                    }
                }
            }
        }
    }
    cout << "Result : \n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << cost[i * n + j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    Floyd f(4);
    f.findMinCostMatrix();
    return 0;
}