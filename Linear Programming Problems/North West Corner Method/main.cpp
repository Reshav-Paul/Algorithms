#include <iostream>
using namespace std;

class NorthWestCorner{
    int *cost, *demand, *supply;
    int rowNum, columnNum;
public:
    NorthWestCorner();
    NorthWestCorner(int,int);
    int findOptimalValue();
    void getInput();
    void display();
};

NorthWestCorner ::NorthWestCorner() {
    rowNum = 0;
    columnNum = 0;
    cost = demand = supply = nullptr;
}

NorthWestCorner ::NorthWestCorner(int row, int column) {
    rowNum = row;
    columnNum = column;
    cost = new int[row * column];
    demand = new int[column + 1];
    supply = new int[row + 1];
}

void NorthWestCorner :: getInput() {
    int i, j;
    int demandSum = 0, supplySum = 0;

    cout << endl;
    for(i = 0; i < columnNum; i++){
        cout << "Enter Demand[" << i + 1 << "] : ";
        cin >> demand[i];
        demandSum += demand[i];
    }

    cout << endl;
    for(i = 0; i < rowNum; i++){
        cout << "Enter Supply[" << i + 1 << "] : ";
        cin >> supply[i];
        supplySum += supply[i];
    }

    cout << "\nEnter the elements of the Cost Matrix\n";
    if(demandSum != supplySum){
        delete[] cost;
        if(demandSum < supplySum){
            cost = new int[rowNum * (columnNum + 1)];
            columnNum++;
            demand[columnNum - 1] = supplySum - demandSum;
            for(i = 0; i < rowNum; i++){
                for(j = 0; j < columnNum - 1; j++){
                    cout << "\nEnter Cost[" << i + 1 << "][" << j + 1 << "] : ";
                    cin >> cost[i * columnNum + j];
                }
                cost[i * columnNum + j] = 0;
            }
        }
        else{
            cost = new int[(rowNum + 1) * (columnNum)];
            rowNum++;
            supply[rowNum - 1] = demandSum - supplySum;
            for(i = 0; i < rowNum - 1; i++){
                for(j = 0; j < columnNum; j++){
                    cout << "\nEnter Cost[" << i + 1 << "][" << j + 1 << "] : ";
                    cin >> cost[i * columnNum + j];
                }
            }
            for(j = 0; j < columnNum; j++){
                cost[(rowNum - 1) * columnNum + j] = 0;
            }
        }
    }
    else{
        for(i = 0; i < rowNum; i++){
            for(j = 0; j < columnNum; j++){
                cout << "\nEnter Cost[" << i + 1 << "][" << j + 1 << "] : ";
                cin >> cost[i * columnNum + j];
            }
        }
    }
}

int NorthWestCorner :: findOptimalValue() {
    getInput();
    int returnSum = 0;
    int allocRow = 0, allocColumn = 0;
    //display();
    while(allocRow < rowNum && allocColumn < columnNum){

        if(demand[allocColumn] < supply[allocRow]){
            supply[allocRow] -= demand[allocColumn];
            returnSum += cost[allocRow * columnNum + allocColumn] * demand[allocColumn];
            demand[allocColumn] = 0;
            allocColumn++;
        }
        else if(supply[allocRow] < demand[allocColumn]){
            demand[allocColumn] -= supply[allocRow];
            returnSum += cost[allocRow * columnNum + allocColumn] * supply[allocRow];
            supply[allocRow] = 0;
            allocRow++;
        }
        else if(supply[allocRow] == demand[allocColumn]){
            returnSum += cost[allocRow * columnNum + allocColumn] * demand[allocColumn];
            demand[allocColumn] = supply[allocRow] = 0;
            allocRow++;
            allocColumn++;
        }
        display();
    }
    return returnSum;
}

void NorthWestCorner :: display() {
    int i, j;
    cout << "\n------------------------------------------------------\n";
    for(i = 0; i < rowNum; i++){
        for(j = 0; j < columnNum; j++){
            cout << cost[i * columnNum + j] << "\t";
        }
        cout << "|\t" << supply[i] << endl;
    }
    for(j = 0; j < columnNum; j++){
        cout << demand[j] << "\t";
    }
}

int main() {
    int demandUnit, supplyUnit;
    cout << "Enter the Number of Demand Units : ";
    cin >> demandUnit;
    cout << "Enter the Number of Supply Units : ";
    cin >> supplyUnit;
    NorthWestCorner n(supplyUnit, demandUnit);
    int result = n.findOptimalValue();
    cout << "\nInitial Basic Feasible Solution : " << result;
    return 0;
}