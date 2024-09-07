#include <bits/stdc++.h>
using namespace std;

deque<int> arr;
int N;

int main()
{
    cin >> N;
    bool isRev = false;

    for (int i = 0; i < N; i++)
    {
        string action;
        cin >> action;

        if (action == "add")
        {
            int x, y;
            cin >> x >> y;
            if (!isRev)
            {

                for (int i = 0; i < y; i++)
                {
                    arr.push_back(x);
                }
            }
            else
            {
                for (int i = 0; i < y; i++)
                {
                    arr.push_front(x);
                }
            }

            cout << arr.size() << endl;
        }
        else if (action == "del")
        {
            int y;
            cin >> y;
            if (!isRev)
            {
                cout << arr.front() << endl;

                for (int i = 0; i < y; i++)
                {
                    arr.pop_front();
                }
            }
            else
            {
                cout << arr.back() << endl;
                for (int i = 0; i < y; i++)
                {
                    arr.pop_back();
                }
            }
        }
        else if (action == "rev")
        {
            isRev = !isRev;
        }
    }
}