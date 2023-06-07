#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> burstArrive, copyburstArrive;

    int noProcess, quanTime;
    cout << "Enter the number of process: ";
    cin >> noProcess;
    cout << "Enter the quantum time: ";
    cin >> quanTime;
    for (int i = 0; i < noProcess; i++)
    {
        int input, num2;
        cout << "Enter the arrival time of process:" << i + 1 << " ";
        cin >> num2;
        cout << "Enter the burst time of process:" << i + 1 << " ";
        cin >> input;
        burstArrive.push_back(make_pair(num2, input));
        copyburstArrive.push_back(make_pair(num2, input));
    }

    sort(burstArrive.begin(), copyburstArrive.end());

    vector<pair<int, int>> arrivelist;
    int waitTime[noProcess], completionTime[noProcess];
    int noProcessCompleted = 0, timeline = 0, j = 0, count = 0;

    while (noProcessCompleted < noProcess)
    {
        while (arrivelist.size() == 0 && count <= timeline)
        {
            if (burstArrive[count].first == count)
            {
                arrivelist.push_back(burstArrive[count]);
            }
            count++;
        }

        if (arrivelist.size() > 0)
        {
            if (quanTime < arrivelist[j].second)
            {
                copyburstArrive[j].second = copyburstArrive[j].second - quanTime;
                timeline += quanTime;
                cout << "Executing timeline" << endl;
            }
            else if (quanTime > arrivelist[j].second && arrivelist[j].second > 0)
            {
                copyburstArrive[j].second = 0;
                timeline += abs(copyburstArrive[j].second - quanTime);
                cout << "Executing timeline else " << endl;
            }

            if (copyburstArrive[j].second == 0)
            {
                noProcessCompleted++;
                completionTime[j] = timeline;
                cout << "Executing copyburst" << endl;
            }
            j++;
        }
    }

    int avgWait = 0;
    for (int i = 0; i < noProcess; i++)
    {
        waitTime[i] = completionTime[i] - burstArrive[i].second;
        avgWait += waitTime[i];
    }
    avgWait /= noProcess;
    cout << "Average Waiting Time is: " << avgWait;
}
