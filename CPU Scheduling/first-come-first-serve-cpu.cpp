#include <bits/stdc++.h>
using namespace std;
int main()
{
    int no_process;
    cout << "Enter the number of process: ";
    cin >> no_process;
    int ariveTime[no_process], burstTime[no_process], complete[no_process];
    int turnaroundTime[no_process], waitingTime[no_process];
    for (int i = 0; i < no_process; i++)
    {

        cout << "Enter the arrival time of process " << i + 1 << ": ";
        cin >> ariveTime[i];
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> burstTime[i];
    }
    vector<pair<int, int>> ariveWait;
    for (int i = 0; i < no_process; i++)
    {
        ariveWait.push_back(make_pair(ariveTime[i], burstTime[i]));
    }
    stable_sort(ariveWait.begin(), ariveWait.end());
    for (int i = 0; i < no_process; i++)
    {
        ariveTime[i] = ariveWait[i].first;
        burstTime[i] = ariveWait[i].second;
        cout << ariveTime[i] << " " << burstTime[i] << endl;
    }

    complete[0] = ariveTime[0] + burstTime[0];
    turnaroundTime[0] = complete[0] - ariveTime[0];
    waitingTime[0] = turnaroundTime[0] - burstTime[0];
    for (int i = 1; i < no_process; i++)
    {
        if (ariveTime[i] > complete[i - 1])
        {
            complete[i] = ariveTime[i] + burstTime[i];
        }
        else
        {
            complete[i] = complete[i - 1] + burstTime[i];
        }

        turnaroundTime[i] = complete[i] - ariveTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }
    float avgTurn = 0, avgWait = 0;
    for (int i = 0; i < no_process; i++)
    {
        avgTurn += turnaroundTime[i];
        avgWait += waitingTime[i];
    }
    avgTurn = avgTurn / no_process;
    avgWait = avgWait / no_process;

    cout << "The average Turn Around Time is: " << avgTurn << " and average waiting time is: " << avgWait;

    return 0;
}