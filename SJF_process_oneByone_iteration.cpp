#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival[n], cpu[n], wt[n], turn[n], pid[n];
    bool done[n] = {false};
    int ct[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter CPU time for Process " << i + 1 << ": ";
        cin >> cpu[i];
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> arrival[i];
        pid[i] = i + 1;
    }

    int time = 0, completed = 0;
    cout << "\n--- Execution Trace ---\n";

    while (completed < n)
    {
        int idx = -1;
        int min_cpu = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!done[i] && arrival[i] <= time)
            {
                if (cpu[i] < min_cpu)
                {
                    min_cpu = cpu[i];
                    idx = i;
                }
                else if (cpu[i] == min_cpu)
                {
                    if (arrival[i] < arrival[idx])
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx == -1)
        {
            time++;
            continue;
        }

        cout << "Iteration " << completed + 1 << ": At time " << time
             << ", Process " << pid[idx] << " starts execution.\n";

        time += cpu[idx];
        ct[idx] = time;
        done[idx] = true;
        completed++;

        cout << "Iteration " << completed << ": At time " << time
             << ", Process " << pid[idx] << " finishes execution.\n";
    }

    float avgwt = 0, avgturn = 0;

    for (int i = 0; i < n; i++)
    {
        turn[i] = ct[i] - arrival[i];
        wt[i] = turn[i] - cpu[i];
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

