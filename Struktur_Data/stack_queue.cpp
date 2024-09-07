#include <bits/stdc++.h>
using namespace std;

deque<int> arr;
int N;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string action;
        int data;

        cin >> action;

        if (action == "push_front")
        {
            cin >> data;
            arr.push_front(data);
        }
        else if (action == "pop_front")
            arr.pop_front();
        else if (action == "push_back")
        {
            cin >> data;
            arr.push_back(data);
        }
        else if (action == "pop_back")
            arr.pop_back();
    }

    for (auto i : arr)
    {
        cout << i << endl;
    }
}