#include <bits/stdc++.h>
using namespace std;

bool check(int input, int frames[])
{
    for (int i = 0; i < 3; i++)
    {
        if (input == frames[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    system("cls");
    int frames[3], hit = 0, fault = 0, increment = 0;
    int input;

    while (input != -1)
    {
        cout << "Enter the page number: ";
        cin >> input;

        bool chky = check(input, frames);
        if (chky)
        {
            hit++;
        }
        else
        {
            fault++;
            frames[increment] = input;
            increment = (increment + 1) % 3;
        }

        if (input == -1)
        {
            fault--;
        }
    }

    cout << "Total Hits: " << hit << endl;
    cout << "Total Faults: " << fault << endl;

    return 0;
}
