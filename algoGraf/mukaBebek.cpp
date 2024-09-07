#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    int adjMatrix[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjMatrix[i][j];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, adj
    bool visited[n + 1] = {false};

    int start = 0;
    int ans = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currDistNode = pq.top().first;
        pq.pop();

        if (!visited[currNode])
        {
            ans += currDistNode;
            visited[currNode] = true;

            for (int i = 0; i < n; i++)
                if (i != currNode && !visited[i])
                    pq.push(make_pair(adjMatrix[currNode][i], i));
        }
    }

    cout << ans;
}

int main()
{
    int tc = 1;
    // cin >> tc ;

    while (tc--)
    {
        solve();
    }
}