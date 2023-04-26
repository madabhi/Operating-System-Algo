#include <bits/stdc++.h>
using namespace std;
#define disk_max 199
int main()
{
    system("cls");
    int size;
    cout << "Enter the number of request: ";
    cin >> size;
    int header;
    cout << "What is the header position ? ";
    cin >> header;
    vector<int> big_no, small_no;
    small_no.push_back(0);
    big_no.push_back(disk_max);
    for (int i = 0; i < size; i++)
    {
    Invalid:
        int input;
        cout << "Enter request: ";
        cin >> input;
        if (input > header)
        {
            big_no.push_back(input);
        }
        else if (input < header)
        {
            small_no.push_back(input);
        }
        else
        {
            cout << "Invalid !";
            goto Invalid;
        }
    }

    sort(small_no.begin(), small_no.end());
    sort(big_no.begin(), big_no.end());
    int direction;
    if (abs(small_no.back() - header) < abs(big_no.front() - header))
    {
        cout << "Left Direction" << endl;
        direction = 1;
    }
    else
    {
        cout << "Right Direction" << endl;
        direction = 0;
    }
    int total_seek = 0;
    if (direction == 0)
    {
        bool temp = false, flag = false;
        for (int i = 0; i < big_no.size(); i++)
        {
            if (temp == false)
            {
                total_seek = total_seek + abs(header - big_no.front());
                temp = true;
            }
            else
            {
                total_seek = total_seek + abs(big_no[i] - big_no[i - 1]);
            }
        }

        for (int i = small_no.size() - 1; i > 0; i--)
        {
            if (flag == false)
            {
                total_seek = total_seek + abs(disk_max - small_no.back());
                flag = true;
            }
            else
            {
                total_seek = total_seek + abs(small_no[i] - small_no[i + 1]);
            }
        }
    }
    else
    {

        bool temp = false, flag = false;
        for (int i = small_no.size() - 1; i >= 0; i--)
        {
            if (temp == false)
            {
                total_seek = total_seek + abs(small_no.back() - header);
                temp = true;
            }
            else
            {
                total_seek = total_seek + abs(small_no[i] - small_no[i + 1]);
            }
        }
        for (int i = 0; i < big_no.size() - 1; i++)
        {
            if (flag == false)
            {
                total_seek = total_seek + abs(big_no.front() - 0);
                flag = true;
            }
            else
            {
                total_seek = total_seek + abs(big_no[i] - big_no[i - 1]);
            }
        }
    }
    cout << "Total seek is: " << total_seek;
}