#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the no. of processes: ";
    cin >> n;
    cout << "Enter the no. of resources: ";
    cin >> m;

    int maxNeed[10][10], allocation[10][10], need[10][10];
    int total[10], available[10], work[10];
    bool finish[10] = {false};
    int safeSequence[10];

    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << endl;
        for (int j = 0; j < m; j++)
        {
            cout << "Maximum value for resource " << j + 1 << ": ";
            cin >> maxNeed[i][j];
        }
        for (int j = 0; j < m; j++)
        {
            cout << "Allocated from resource " << j + 1 << ": ";
            cin >> allocation[i][j];
        }
    }

    for (int j = 0; j < m; j++)
    {
        cout << "Enter total value of resource " << j + 1 << ": ";
        cin >> total[j];
    }

    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += allocation[i][j];
        }
        available[j] = total[j] - sum;
        work[j] = available[j];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    int count = 0;
    bool found;

    while (count < n)
    {
        found = false;
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                bool canAllocate = true;
                for (int j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
                    safeSequence[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
        {
            break;
        }
    }

    bool safe = true;
    for (int i = 0; i < n; i++)
    {
        if (!finish[i])
        {
            safe = false;
        }
    }

    cout << endl;
    if (safe)
    {
        cout << "The System is currently in safe state and" << endl;
        cout << "< ";
        for (int i = 0; i < count; i++)
        {
            cout << "P" << safeSequence[i] + 1 << " ";
        }
        cout << "> is the safe sequence." << endl;
    }
    else
    {
        cout << "The System is NOT in a safe state." << endl;
    }

    return 0;
}
