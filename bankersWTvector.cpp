#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the no. of processes: ";
    cin >> n;
    cout << "Enter the no. of resources: ";
    cin >> m;

    vector<vector<int>> maxNeed(n, vector<int>(m));
    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> total(m), available(m);

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
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }

    vector<bool> finish(n, false);
    vector<int> safeSequence;
    vector<int> work = available;

    bool found;
    while (true)
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
                    safeSequence.push_back(i);
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
        for (int i = 0; i < safeSequence.size(); i++)
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
