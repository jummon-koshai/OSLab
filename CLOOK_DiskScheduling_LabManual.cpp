#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, initial_head;
    string direction;

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

    cout << "Enter direction (left/right): ";
    cin >> direction;

    sort(request_queue.begin(), request_queue.end());

    int head_index = 0;
    for (int i = 0; i < N; i++)
    {
        if (request_queue[i] >= initial_head)
        {
            head_index = i;
            break;
        }
    }

    vector<int> service_order;
    int total_movement = 0;
    int current_head = initial_head;

    if (direction == "right")
    {
        for (int i = head_index; i < N; i++)
        {
            service_order.push_back(request_queue[i]);
            total_movement += abs(current_head - request_queue[i]);
            current_head = request_queue[i];
        }

        total_movement += abs(current_head - request_queue[0]) + 1;
        current_head = request_queue[0];

        for (int i = 0; i < head_index; i++)
        {
            service_order.push_back(request_queue[i]);
            total_movement += abs(current_head - request_queue[i]);
            current_head = request_queue[i];
        }
    }
    else
    {
        for (int i = head_index - 1; i >= 0; i--)
        {
            service_order.push_back(request_queue[i]);
            total_movement += abs(current_head - request_queue[i]);
            current_head = request_queue[i];
        }

        total_movement += abs(current_head - request_queue.back()) + 1;
        current_head = request_queue.back();

        for (int i = N - 1; i >= head_index; i--)
        {
            service_order.push_back(request_queue[i]);
            total_movement += abs(current_head - request_queue[i]);
            current_head = request_queue[i];
        }
    }

    cout << "Order of service: ";
    for (int i = 0; i < service_order.size(); i++)
    {
        cout << service_order[i];
        if (i != service_order.size() - 1)
        {
            cout << " -> ";
        }
    }
    cout << endl;

    cout << "Total head movement: " << total_movement << endl;
    cout << "Average head movement per request: " << (float)total_movement / N << endl;

    return 0;
}
