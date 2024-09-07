#include <bits/stdc++.h>
using namespace std;

int N;

// first = height, second = value of people
stack<pair<int, int>> stackHeightandValue;

int main()
{
    cin >> N;
    long long result = 0;

    for (int i = 1; i <= N; i++)
    {
        int Height;
        cin >> Height;

        int maxSight = 1;

        while (!stackHeightandValue.empty() && (Height >= stackHeightandValue.top().first))
        {
            maxSight += stackHeightandValue.top().second;
            stackHeightandValue.pop();
        }

        result += maxSight;
        stackHeightandValue.push({Height, maxSight});
    }
    cout << result;
}
