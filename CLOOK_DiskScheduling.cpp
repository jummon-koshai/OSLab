#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, head;
    string direction;

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

    cout << "Enter head movement direction (left/right): ";
    cin >> direction;

    sort(requests.begin(), requests.end());
    vector<int> service_order;
    auto it = lower_bound(requests.begin(), requests.end(), head);
    int pos = it - requests.begin();

    if (direction == "right")
    {
        for (int i = pos; i < requests.size(); i++)
        {
            service_order.push_back(requests[i]);
        }
        for (int i = 0; i < pos; i++)
        {
            service_order.push_back(requests[i]);
        }
    }
    else
    {
        for (int i = pos - 1; i >= 0; i--)
        {
            service_order.push_back(requests[i]);
        }
        for (int i = requests.size() - 1; i >= pos; i--)
        {
            service_order.push_back(requests[i]);
        }
    }

    int total_movement = 0;
    int current = head;
    for (int req : service_order)
    {
        total_movement += abs(req - current);
        current = req;
    }

    cout << "\nC-LOOK Order of Service: ";
    for (int i = 0; i < service_order.size(); i++)
    {
        cout << service_order[i];
        if (i != service_order.size() - 1)
        {
            cout << " -> ";
        }
    }

    cout << "\nTotal Head Movement: " << total_movement << endl;

    return 0;
}
