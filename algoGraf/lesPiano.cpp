#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e+9

class Compare
{
public:
    bool operator()(pair<int, int> below, pair<int, int> above)
    {
        return below.second > above.second;
    }
};

vector<pair<int, int>> adj[2502];                                   // adj, dist
priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // node, jarak

void solve()
{
    int v, e, a, b;
    cin >> v >> e >> a >> b;

    for (int i = 0; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }

    int dist[v + 1];
    bool visited[v + 1] = {false};

    for (int i = 1; i <= v; i++)
        dist[i] = INF;

    dist[a] = 0;
    pq.push(make_pair(a, 0));

    while (!pq.empty())
    {
        int currNode = pq.top().first;
        int currDistNode = pq.top().second;
        pq.pop();

        if (!visited[currNode])
        {
            visited[currNode] = true;

            for (auto i : adj[currNode])
                if (dist[i.first] > i.second + currDistNode)
                {
                    dist[i.first] = i.second + currDistNode;
                    pq.push(make_pair(i.first, dist[i.first]));
                }
        }
    }

    cout << dist[b];
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