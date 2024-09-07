#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;

    int ans = 0;

    vector<pair<int, int>> adj[n + 1];                                                  // adj, dist
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // dist, adj

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int start, target;
    cin >> start;

    for (int i = 1; i <= q - 1; i++)
    {
        pq.push(make_pair(0, start));

        int dist[n + 1];
        bool visited[n + 1] = {false};

        for (int j = 1; j <= n; j++)
            dist[j] = 1e9;

        dist[start] = 0;
        while (!pq.empty())
        {
            int currNode = pq.top().second;
            int currDistNode = pq.top().first;
            pq.pop();

            if (!visited[currNode])
            {
                visited[currNode] = true;

                for (auto j : adj[currNode])
                {
                    dist[j.first] = min(dist[j.first], currDistNode + j.second);
                    pq.push(make_pair(dist[j.first], j.first));
                }
            }
        }
        if (i < q)
        {
            cin >> target;
            ans += dist[target];
            start = target;
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