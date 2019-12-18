#include <iostream>
using namespace std;

class MatrixMinima{
    int *cost, *demand, *supply;
    int nDemand, nSupply;
public:
    MatrixMinima();
    MatrixMinima(int, int);
    void getInput();
    void sort(int*);
    int findBFS();
    void display();
};

MatrixMinima::MatrixMinima() {
    cost = demand = supply = nullptr;
    nDemand = nSupply = 0;
}

MatrixMinima::MatrixMinima(int s, int d) {
    nDemand = d;
    nSupply = s;
    cost = new int[nSupply * nDemand];
    demand = new int[nDemand + 1];
    supply = new int[nSupply + 1];
}

void MatrixMinima::getInput() {
    int i, j;
    int demandSum = 0, supplySum = 0;

    cout << endl;
    for(i = 0; i < nDemand; i++){
        cout << "Enter Demand[" << i + 1 << "] : ";
        cin >> demand[i];
        demandSum += demand[i];
    }

    cout << endl;
    for(i = 0; i < nSupply; i++){
        cout << "Enter Supply[" << i + 1 << "] : ";
        cin >> supply[i];
        supplySum += supply[i];
    }

    cout << "\nEnter the elements of the Cost Matrix\n";
    if(demandSum != supplySum){
        delete[] cost;
        if(demandSum < supplySum){
            cost = new int [nSupply * (nDemand + 1)];
            nDemand++;
            demand[nDemand - 1] = supplySum - demandSum;
            for(i = 0; i < nSupply; i++){
                for(j = 0; j < nDemand - 1; j++){
                    cout << "\nEnter Cost[" << i + 1 << "][" << j + 1 << "] : ";
                    cin >> cost[i * nDemand + j];
                }
                cost[i * nDemand + j] = 0;
            }
        }
        else{
            cost = new int[ (nSupply + 1) * (nDemand)];
            nSupply++;
            supply[nSupply - 1] = demandSum - supplySum;
            for(i = 0; i < nSupply - 1; i++){
                for(j = 0; j < nDemand; j++){
                    cout << "\nEnter Cost[" << i + 1 << "][" << j + 1 << "] : ";
                    cin >> cost[i * nDemand + j];
                }
            }
            for(j = 0; j < nDemand; j++){
                cost[ (nSupply - 1) * nDemand + j] = 0;
            }
        }
    }
    else{
        for(i = 0; i < nSupply; i++){
            for(j = 0; j < nDemand; j++){
                cout << "\nEnter Cost[" << i + 1 << "][" << j + 1 << "] : ";
                cin >> cost[i * nDemand + j];
            }
        }
    }
}

void MatrixMinima::sort(int *arr) {
    int i, j, temp;
    for(i = 0; i < nSupply * nDemand; i++){
        for(j = 0; j < nSupply * nDemand - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int MatrixMinima::findBFS() {
    int i, j;
    getInput();
    cout << "\nInput Problem : ";
    display();
    int *arr = new int[nDemand * nSupply];
    for(i = 0; i < nSupply; i++){
        for(j = 0; j < nDemand; j++){
            arr[i * nDemand + j] = cost[i * nDemand + j];
        }
    }
    sort(arr);
    int ctr = 0, tempAlloc = 0;
    int alloc = 0, allocCost = 0, allocRow = 0, allocColumn = 0, retSum = 0;

    while(ctr < nDemand * nSupply){
        allocCost = arr[ctr];
        alloc = 0;
        for(i = 0; i < nSupply; i++){
            for(j = 0; j < nDemand; j++){
                if(demand[j] == 0 || supply[i] == 0){
                    continue;
                }
                else{
                    tempAlloc = (demand[j] > supply[i]) ? supply[i] : demand[j];
                    if(allocCost == cost[i * nDemand + j] && tempAlloc > alloc){
                        alloc = tempAlloc;
                        allocRow = i;
                        allocColumn = j;
                    }
                }
            }
        }
        retSum += allocCost * alloc;
        if(demand[allocColumn] < supply[allocRow] && alloc > 0){
            supply[allocRow] -= demand[allocColumn];
            cout << "\nAllocated " << demand[allocColumn] << " at Cell(" << allocRow + 1 << ", " << allocColumn + 1 << ") having cost = " << allocCost;
            demand[allocColumn] = 0;
        }
        else if(supply[allocRow] < demand[allocColumn] && alloc > 0){
            demand[allocColumn] -= supply[allocRow];
            cout << "\nAllocated " << supply[allocRow] << " at Cell(" << allocRow + 1 << ", " << allocColumn + 1 << ") having cost = " << allocCost;
            supply[allocRow] = 0;
        }
        else if(supply[allocRow] == demand[allocColumn] && alloc > 0){
            cout << "\nAllocated " << supply[allocRow] << " at Cell(" << allocRow + 1 << ", " << allocColumn + 1 << ") having cost = " << allocCost;
            demand[allocColumn] = supply[allocRow] = 0;
        }

        for(i = 0; i < nDemand; i++){
            if(demand[i] != 0)
                break;
        }
        if(i >= nDemand)
            ctr = nDemand * nSupply + 1;

        ctr++;
    }
    return retSum;
}

void MatrixMinima :: display() {
    int i, j;
    cout << "\n------------------------------------------------------\n";
    for(i = 0; i < nSupply; i++){
        for(j = 0; j < nDemand; j++){
            cout << cost[i * nDemand + j] << "\t";
        }
        cout << "|\t" << supply[i] << endl;
    }
    for(j = 0; j < nDemand; j++){
        cout << demand[j] << "\t";
    }
}

int main() {
    MatrixMinima m(3, 3);
    int result = m.findBFS();
    cout << "\nInitial BFS = " << result;
    return 0;
}