#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, head;
    cout << "Enter number of requests: ";
    cin >> n;

    vector<int> requests(n);
    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++)
    {
        cin >> requests[i];
    }

    cout << "Enter initial head position: ";
    cin >> head;

    vector<bool> visited(n, false);
    vector<int> service_order;
    int total_movement = 0;
    int current = head;

    for (int i = 0; i < n; i++)
    {
        int min_distance = INT_MAX;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && abs(requests[j] - current) < min_distance)
            {
                min_distance = abs(requests[j] - current);
                index = j;
            }
        }
        visited[index] = true;
        total_movement += abs(requests[index] - current);
        current = requests[index];
        service_order.push_back(requests[index]);
    }

    cout << "\nSSTF Order of Service: ";
    for (int i = 0; i < n; i++)
    {
        cout << service_order[i];
        if (i != n - 1)
        {
            cout << " -> ";
        }
    }

    cout << "\nTotal Head Movement: " << total_movement;
    cout << "\nAverage Head Movement: " << (float)total_movement / n << endl;

    return 0;
}
