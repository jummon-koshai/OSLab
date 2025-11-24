#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, initial_head;
    cout << "Enter number of disk requests: ";
    cin >> N;

    vector<int> request_queue(N);
    cout << "Enter disk requests: ";
    for (int i = 0; i < N; i++)
    {
        cin >> request_queue[i];
    }

    cout << "Enter initial head position: ";
    cin >> initial_head;

    vector<int> service_order;
    int total_movement = 0;
    int current_head = initial_head;

    for (int i = 0; i < N; i++)
    {
        service_order.push_back(request_queue[i]);
        total_movement += abs(current_head - request_queue[i]);
        current_head = request_queue[i];
    }

    cout << "Order of service: ";
    for (int i = 0; i < service_order.size(); i++)
    {
        cout << service_order[i];
        if (i != service_order.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    cout << "Total head movement: " << total_movement << endl;
    cout << "Average head movement per request: " << (float)total_movement / N << endl;

    return 0;
}
