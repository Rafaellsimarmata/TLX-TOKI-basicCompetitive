#include <bits/stdc++.h>
using namespace std;

#define INF 1000000

vector<pair<int, bool>> graf[505];
int dist[505][2]; // dist[node][0] = distance without using toll, dist[node][1] = distance using toll

void solve()
{
    int n, l, t, initState, endState;
    cin >> n >> l >> t >> initState >> endState;

    // Initialize distances to INF
    for (int i = 1; i <= n; i++)
    {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    // Read the graph
    for (int i = 1; i <= l + t; i++)
    {
        int kota1, kota2;
        bool isToll = false;
        cin >> kota1 >> kota2;

        if (i > l)
            isToll = true;

        graf[kota1].push_back(make_pair(kota2, isToll));
        graf[kota2].push_back(make_pair(kota1, isToll));
    }

    // Initialize BFS
    queue<pair<int, bool>> q;
    dist[initState][0] = 0;
    q.push({initState, false}); // {node, tollUsed}

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int currNode = curr.first;
        bool tollUsed = curr.second;
        int currDist = dist[currNode][tollUsed];

        for (auto edge : graf[currNode])
        {
            int nextNode = edge.first;
            bool isToll = edge.second;
            bool nextTollUsed = tollUsed || isToll;

            if (isToll && tollUsed)
                continue; // Skip if toll already used

            int nextDist = currDist + 1;
            if (nextDist < dist[nextNode][nextTollUsed])
            {
                dist[nextNode][nextTollUsed] = nextDist;
                q.push({nextNode, nextTollUsed});
            }
        }
    }

    // Determine the result
    int result = min(dist[endState][0], dist[endState][1]);
    cout << result << endl;
}

int main()
{
    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        solve();
    }
    return 0;
}
