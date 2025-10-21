#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrival[n], cpu[n], wt[n], turn[n], pid[n];


    cout << "Enter the CPU times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> cpu[i];
        pid[i] = i + 1;
    }

    cout << "Enter the arrival times:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arrival[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arrival[j] > arrival[j + 1])
            {
                swap(arrival[j], arrival[j + 1]);
                swap(cpu[j], cpu[j + 1]);
                swap(pid[j], pid[j + 1]);
            }
        }
    }

    int ct[n], time = 0;
    for (int i = 0; i < n; i++)
    {
        if (time < arrival[i])
        {
            time = arrival[i];
        }
        time += cpu[i];
        ct[i] = time;
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
                cout << "Process " << pid[i] << ": Waiting Time: " << wt[i] << " Turnaround Time: " << turn[i] << endl;
                break;
            }
        }
    }

cout << fixed << setprecision(2);
cout << "Average Waiting time: " << avgwt / n << endl;
cout << "Average Turnaround time: " << avgturn / n << endl;

return 0;
}
