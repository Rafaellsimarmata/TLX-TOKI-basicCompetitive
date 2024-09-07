#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, e, q, r;
bool node[50050] = {0}; // here node is the index, and value is the special/not
bool visitedNode[50050] = {0};
vector<pair<ll, ll>> edge(200050);
vector<ll> adjList[50050];
ll tempValue = 0;

void reset()
{
    edge.clear();
    tempValue = 0;
    memset(node, false, sizeof(node));
    memset(visitedNode, false, sizeof(visitedNode));
    for (ll i = 1; i <= n; i++)
    {
        adjList[i].clear();
    }
}

void dfs(ll i)
{
    visitedNode[i] = true;
    // if special then count special
    if (node[i])
        tempValue++;

    for (auto adj : adjList[i])
    {
        if (!visitedNode[adj])
            dfs(adj);
    }
}

void solve()
{
    cin >> n >> e >> q >> r;

    reset();

    for (ll i = 0; i < e; i++)
    {
        ll e1, e2;
        cin >> e1 >> e2;
        edge.push_back(make_pair(e1, e2));
    }

    for (ll i = 0; i < q; i++)
    {
        ll temp;
        cin >> temp;
        node[temp] = true;
    }

    for (ll i = 0; i < r; i++)
    {
        ll temp;
        cin >> temp;
        edge[temp - 1].first = -1;
        edge[temp - 1].second = -1;
    }

    // because edge is stil in list
    // to make easier to do dfs, make edge list to adj list
    for (auto i : edge)
    {
        if (i.first != -1 && i.second != -1)
        {
            adjList[i.first].push_back(i.second);
            adjList[i.second].push_back(i.first); // Tambahkan ini untuk membuat adjacency list bidirectional
        }
    }

    // testing
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << i << " adj : ";
    //     for (auto j : adjList[i])
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    ll ans = q * (q - 1) / 2;

    // loop each node and do dfs while count for special node that connected
    for (ll i = 1; i <= n; i++)
    {
        if (!visitedNode[i])
        {
            dfs(i);
            ll x = tempValue * (tempValue - 1) / 2;
            ans -= x;
            tempValue = 0;
        }
    }
    cout << ans << endl;
}

int main()
{

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
