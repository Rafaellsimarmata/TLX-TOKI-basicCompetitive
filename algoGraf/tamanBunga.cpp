#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e9;

void solve()
{

    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> adj[e + 2];
    int dist[v + 2];
    bool visited[v + 2] = {false};

    for (int i = 0; i < v; i++)
        dist[i] = INF;

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(make_pair(b, c));
        // adj[b].push_back(make_pair(a, c));
    }

    dist[0] = 0;

    for (int k = 0; k < v - 1; k++)
        for (int i = 0; i < v - 1; i++)
            for (auto j : adj[i])
                if (dist[j.first] > dist[i] + j.second)
                    dist[j.first] = dist[i] + j.second;

    for (int i = 0; i < v - 1; i++)
        for (auto j : adj[i])
            if (dist[j.first] > dist[i] + j.second)
            {
                cout << "Pak Dengklek tidak mau pulang" << endl;
                return;
            }

    if (dist[v - 1] == 1e9)
    {
        cout << "Tidak ada jalan" << endl;
        return;
    }
    else
    {
        cout << dist[v - 1] << endl;
        return;
    }
}

int main()
{
    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }
}