#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> modStack;
int N;

int main()
{
    int change = 0;
    int stackSize = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string action;
        cin >> action;

        if (action == "add")
        {
            int x, y;
            cin >> x >> y;

            pair<int, int> temp;
            temp.first = x - change;
            temp.second = y;

            modStack.push(temp);
            stackSize += y;
            cout << stackSize << endl;
        }
        else if (action == "del")
        {
            int y;
            cin >> y;

            cout << modStack.top().first + change << endl;
            stackSize -= y;

            while (y > 0)
            {
                if (y - modStack.top().second < 0)
                {
                    modStack.top().second -= y;
                    break;
                }
                y -= modStack.top().second;
                modStack.pop();
            }
        }
        else if (action == "adx")
        {
            int y;
            cin >> y;

            change += y;
        }
        else
        {
            int y;
            cin >> y;

            change -= y;
        }
    }
}
