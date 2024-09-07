#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int v, h, n;
    cin >> v >> h >> n;

    bool map[v + 1][h + 1];
    ll dp[v + 1][h + 1];
    memset(dp, 0, sizeof(dp));
    memset(map, 0, sizeof(map));

    for (int i = 0; i < n; i++)
    {
        int v1, h1, v2, h2;
        cin >> v1 >> h1 >> v2 >> h2;

        for (int v = v1; v <= v2; v++)
            for (int h = h1; h <= h2; h++)
                map[v][h] = 1;
    }

    for (int i = v - 1; i >= 0; i--)
    {
        for (int j = 1; j <= h; j++)
        {
            if (!map[i + 1][j] || map[i][j])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                int ujungKanan = j;
                int ujungKiri = j;
                // ujung kanan
                while (map[i + 1][ujungKanan] && ujungKanan >= 1 && ujungKanan <= h)
                    ujungKanan++;
                while (map[i + 1][ujungKiri] && ujungKiri >= 1 && ujungKiri <= h)
                    ujungKiri--;

                dp[i][j] = 1LL + dp[i + 1][ujungKiri] + dp[i + 1][ujungKanan];
            }
        }
    }

    ll ans = -1;

    for (int i = 1; i <= h; i++)
        ans = max(ans, dp[0][i]);

    cout << ans << endl;
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