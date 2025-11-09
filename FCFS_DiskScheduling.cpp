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

    int total_movement = 0;
    int current = head;

    cout << "\nFCFS Order of Service: ";
    for (int i = 0; i < n; i++)
    {
        cout << requests[i];
        if (i != n - 1)
        {
            cout << " -> ";
        }
        total_movement += abs(requests[i] - current);
        current = requests[i];
    }

    cout << "\nTotal Head Movement: " << total_movement;
    cout << "\nAverage Head Movement: " << (float)total_movement / n << endl;

    return 0;
}
