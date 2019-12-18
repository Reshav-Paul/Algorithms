#include<iostream>
#include<cmath>
using namespace std;

class VAM
{
    int A[10][10], nD, nS, demand[10], supply[10], supplyPen[10], demandPen[10]; //maxSupPenPos, maxDemPenPos;
    long int cost;
public:
    VAM()
    {
        nD = 0;
        nS = 0;
    }
    VAM(int, int);
    void findCost();
    void findSupplyPenalty();
    void findDemandPenalty();
    int findMaxSupplyPenalty();
    int findMaxDemandPenalty();
    void allocateInRow(int);
    void allocateInColumn(int);
};

VAM::VAM(int s, int d)
{
    cost = 0;
    nD = d;
    nS = s;
    int i, j;
    long int supplySum = 0, demandSum = 0;
    for(i = 0; i < nS; i++)
    {
        cout << "Enter Supply[" << i + 1 << "] : ";
        cin >> supply[i];
        supplySum += supply[i];
    }
    for(i = 0; i < nD; i++)
    {
        cout << "Enter Demand[" << i + 1 << "] : ";
        cin >> demand[i];
        demandSum += demand[i];
    }

    for(i = 0; i < nS; i++)
    {
        for(j = 0; j < nD; j++)
        {
            cout << "Enter Cost[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> A[i][j];
        }
    }

    if(supplySum < demandSum)
    {
        supply[nS] = demandSum - supplySum;

        for(i = 0; i < nD; i++)
        {
            A[nS][i] = 0;
        }
        nS++;
    }
    else if(demandSum < supplySum)
    {
        demand[nD] = supplySum - demandSum;

        for(i = 0; i < nS; i++)
        {
            A[i][nD] = 0;
        }
        nD++;
    }

}

void VAM::findCost()
{
    long int demandSum, supplySum, i;
    int ctr = 1;
    int allocRow, allocColumn, maxSupplyPenI, maxDemandPenJ;
    do
    {
        findSupplyPenalty();
        findDemandPenalty();

        maxSupplyPenI = findMaxSupplyPenalty();
        maxDemandPenJ = findMaxDemandPenalty();
        //cout << maxSupplyPenI << " " << maxDemandPenJ;
        if(supplyPen[maxSupplyPenI] > demandPen[maxDemandPenJ])
        {
            allocateInRow(maxSupplyPenI);
        }
        else
        {
            allocateInColumn(maxDemandPenJ);
        }
        supplySum = demandSum = 0;
        for(i = 0; i < nS; i++)
            supplySum+= supply[i];
        for(i = 0; i < nD; i++)
            demandSum+=demand[i];
        if(supplySum == 0 && demandSum == 0)
            ctr = 0;
    }
    while(ctr);
    cout << cost;
}

void VAM::findSupplyPenalty()
{
    int i, j, k, min_idx;
    int maxC, max2C;
    int temp[10], tempPos[10], t;
    for(int p = 0; p < nS; p++)
    {
        if(supply[p] > 0)
        {
            maxC = 0;
            max2C = 0;
            for(i = 0; i < nD; i++)
            {
                temp[i] = A[p][i];
                tempPos[i] = i;
            }
            for(i = 0; i < nD - 1; i++)
            {
                min_idx = i;
                for(j = i + 1; j < nD; j++)
                {
                    if(temp[j] < temp[min_idx])
                        min_idx = j;
                }
                t = temp[i];
                temp[i] = temp[min_idx];
                temp[min_idx] = t;
                t = tempPos[i];
                tempPos[i] = tempPos[min_idx];
                tempPos[min_idx] = t;
            }

            for(i = 0; i < nD; i++)
            {
                if(demand[tempPos[i]] > 0)
                {
                    maxC = temp[i];
                    break;
                }
            }
            for(j = i + 1; j < nD; j++)
            {
                if(demand[tempPos[j]] > 0)
                {
                    max2C = temp[j];
                    break;
                }
            }
            supplyPen[p] = abs(max2C - maxC);
        }
        else
            supplyPen[p] = -1;
    }
}

void VAM::findDemandPenalty()
{
    int i, j, k, min_idx;
    int maxC, max2C;
    int temp[10], tempPos[10], t;
    for(int p = 0; p < nD; p++)
    {
        if(demand[p] > 0)
        {
            max2C = maxC = 0;
            for(i = 0; i < nS; i++)
            {
                temp[i] = A[i][p];
                tempPos[i] = i;
            }
            for(i = 0; i < nS; i++)
            {
                min_idx = i;
                for(j = i + 1; j < nS; j++)
                {
                    if(temp[j] < temp[i])
                        min_idx = j;
                }
                t = temp[i];
                temp[i] = temp[min_idx];
                temp[min_idx] = t;
                t = tempPos[i];
                tempPos[i] = tempPos[min_idx];
                tempPos[min_idx] = t;
            }

            for(i = 0; i < nS; i++)
            {
                if(supply[tempPos[i]] > 0)
                {
                    maxC = temp[i];
                    break;
                }
            }
            for(j = i + 1; j < nS; j++)
            {
                if(supply[tempPos[j]] > 0)
                {
                    max2C = temp[j];
                    break;
                }
            }
            demandPen[p] = abs(max2C - maxC);
        }
        else
            demandPen[p] = -1;
    }
}

int VAM::findMaxSupplyPenalty()
{
    int maxPen = -1,maxPos = -1, i;
    for(i = 0; i < nS; i++)
    {
        if(maxPen < supplyPen[i])
        {
            maxPen = supplyPen[i];
            maxPos = i;
        }
    }
    return maxPos;
}

int VAM::findMaxDemandPenalty()
{
    int maxPen = -1,maxPos = -1, i;
    for(i = 0; i < nD; i++)
    {
        if(maxPen < demandPen[i])
        {
            maxPen = demandPen[i];
            maxPos = i;
        }
    }
    return maxPos;
}

void VAM::allocateInRow(int rowNum)
{
    int minCost = -1, minPos = -1, i, j;
    for(i = 0; i < nD; i++)
    {
        if(demand[i] > 0)
        {
            if(minCost < 0)
            {
                minCost = A[rowNum][i];
                minPos = i;
            }
            else if(minCost > 0 && minCost > A[rowNum][i])
            {
                minCost = A[rowNum][i];
                minPos = i;
            }
        }
    }
    if(supply[rowNum] > demand[minPos])
    {
        cost += A[rowNum][minPos] * demand[minPos];
        supply[rowNum] -= demand[minPos];
        demand[minPos] = 0;
    }
    else if(supply[rowNum] < demand[minPos])
    {
        cost += A[rowNum][minPos] * supply[rowNum];
        demand[minPos] -= supply[rowNum];
        supply[rowNum] = 0;
    }
    else
    {
        cost += A[rowNum][minPos] * supply[rowNum];
        demand[minPos] = supply[rowNum] = 0;
    }
}

void VAM::allocateInColumn(int colNum)
{
    int minCost = -1, minPos = -1, i, j;
    for(i = 0; i < nS; i++)
    {
        if(supply[i] > 0)
        {
            if(minCost < 0)
            {
                minCost = A[i][colNum];
                minPos = i;
            }
            else if(minCost > 0 && minCost > A[i][colNum])
            {
                minCost = A[i][colNum];
                minPos = i;
            }
        }
    }
    if(supply[minPos] > demand[colNum])
    {
        cost += A[minPos][colNum] * demand[colNum];
        supply[minPos] -= demand[colNum];
        demand[colNum] = 0;
    }
    else if(supply[minPos] < demand[colNum])
    {
        cost += A[minPos][colNum] * supply[minPos];
        demand[colNum] -= supply[minPos];
        supply[minPos] = 0;
    }
    else
    {
        cost += A[minPos][colNum] * supply[minPos];
        demand[colNum] = supply[minPos] = 0;
    }
}

int main()
{
    VAM v(3, 4);
    v.findCost();
    return 0;
}
