#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> burstTime;
    cout << "Enter the number of processes: ";
    int no_process;
    cin >> no_process;
    for (int i = 0; i < no_process; i++)
    {
        int input;
        cout << "Enter the burst of process " << i + 1 << " ";
        cin >> input;
        burstTime.push_back(input);
    }
    sort(burstTime.begin(), burstTime.end());
    vector<int> completionTime, waitTime;

    int turnAroundTime[no_process];
    int timeline = 0;
    waitTime.push_back(0);
    for (int i = 0; i < no_process; i++)
    {
        timeline = timeline + burstTime[i];
        completionTime.push_back(timeline);
        waitTime.push_back(timeline);
        turnAroundTime[i] = waitTime[i] + burstTime[i];
    }
    float avgWaiting = 0, avgturnAround = 0;
    cout << "Waiting Time: " << endl;
    for (int i = 0; i < no_process; i++)
    {
        cout << waitTime[i] << " ";
        avgWaiting = avgWaiting + waitTime[i];
    }
    avgWaiting = avgWaiting / no_process;
    cout << endl
         << "Turn Around time:" << endl;
    for (int i = 0; i < no_process; i++)
    {
        cout << turnAroundTime[i] << " ";
        avgturnAround = avgturnAround + turnAroundTime[i];
    }
    cout << endl;
    avgturnAround = avgturnAround / no_process;

    cout << "Average Waiting Time is: " << avgWaiting << endl;
    cout << "Average Turn aorund time is: " << avgturnAround << endl;

    return 0;
}