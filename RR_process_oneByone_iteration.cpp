#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, quantum;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival[n], burst[n], remaining[n], ct[n], wt[n], turn[n], pid[n];
    bool done[n] = {false};

    for (int i = 0; i < n; i++)
    {
        cout << "Enter CPU time for Process " << i + 1 << ": ";
        cin >> burst[i];
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> arrival[i];
        pid[i] = i + 1;
        remaining[i] = burst[i];
    }

    cout << "Enter Time Quantum: ";
    cin >> quantum;

    queue<int> q;
    int time = 0, completed = 0;
    bool in_queue[n] = {false};

    for (int i = 0; i < n; i++)
    {
        if (arrival[i] <= time && !in_queue[i])
        {
            q.push(i);
            in_queue[i] = true;
        }
    }

    int iteration = 0;
    cout << "\n--- Execution Trace ---\n";

    while (completed < n)
    {
        if (!q.empty())
        {
            int i = q.front();
            q.pop();

            iteration++;
            cout << "Iteration " << iteration << ": Timer = " << time
                 << ", Process " << pid[i] << " starts execution.\n";

            int exec_time = min(quantum, remaining[i]);
            time += exec_time;
            remaining[i] -= exec_time;

            if (remaining[i] == 0)
            {
                ct[i] = time;
                done[i] = true;
                completed++;
                cout << "Iteration " << iteration << ": Timer = " << time
                     << ", Process " << pid[i] << " finishes execution.\n";
            }
            else
            {
                cout << "Iteration " << iteration << ": Timer = " << time
                     << ", Process " << pid[i] << " paused (Remaining Time = "
                     << remaining[i] << ").\n";
            }

            for (int j = 0; j < n; j++)
            {
                if (arrival[j] <= time && !in_queue[j] && !done[j])
                {
                    q.push(j);
                    in_queue[j] = true;
                }
            }

            if (!done[i])
            {
                q.push(i);
            }
        }
        else
        {
            time++;
            for (int i = 0; i < n; i++)
            {
                if (arrival[i] <= time && !in_queue[i] && !done[i])
                {
                    q.push(i);
                    in_queue[i] = true;
                }
            }
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
