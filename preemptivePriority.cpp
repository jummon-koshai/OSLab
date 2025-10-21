#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival[n], burst[n], remaining[n], priority[n], ct[n], wt[n], turn[n], pid[n];
    bool completed[n] = {false};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter CPU time for Process " << i + 1 << ": ";
        cin >> burst[i];
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> arrival[i];
        cout << "Enter priority for Process " << i + 1 << ": ";
        cin >> priority[i];
        pid[i] = i + 1;
        remaining[i] = burst[i];
    }

    int time = 0, completedCount = 0, current = -1, prev = -1;
    vector<bool> isStarted(n, false);
    cout << "\n--- Execution Trace ---\n";

    while (completedCount < n)
    {
        int idx = -1, min_priority = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arrival[i] <= time && !completed[i])
            {
                if (priority[i] < min_priority || (priority[i] == min_priority && arrival[i] < arrival[idx]))
                {
                    min_priority = priority[i];
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            if (prev != idx)
            {
                cout << "At time " << time << ", Process " << pid[idx] << " starts/resumes execution.\n";
                prev = idx;
            }

            remaining[idx]--;
            time++;

            if (remaining[idx] == 0)
            {
                ct[idx] = time;
                completed[idx] = true;
                completedCount++;
                cout << "At time " << time << ", Process " << pid[idx] << " finishes execution.\n";
            }
        }
        else
        {
            time++;
        }
    }

    float avgwt = 0, avgturn = 0;

    for (int i = 0; i < n; i++)
    {
        turn[i] = ct[i] - arrival[i];
        wt[i] = turn[i] - burst[i];
        avgwt += wt[i];
        avgturn += turn[i];
    }

    cout << "\nSample Output:\n";

    for (int p = 1; p <= n; p++)
    {
        for (int i = 0; i < n; i++)
        {
            if (pid[i] == p)
            {
                cout << "Process " << pid[i]
                     << ": Waiting Time: " << wt[i]
                     << " Turnaround Time: " << turn[i] << endl;
                break;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "Average Waiting time: " << avgwt / n << endl;
    cout << "Average Turnaround time: " << avgturn / n << endl;

    return 0;
}
