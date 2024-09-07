#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll cost[102][102];
pair<ll, ll> banyakCara[102][102]; // number of ways, number of optimalCount

void solve()
{
    ll n, q;
    cin >> n;

    ll arr[n + 1];

    for (ll i = 0; i <= n; i++)
        cin >> arr[i];

    cin >> q;

    for (ll i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
        banyakCara[i][i].first = 1;
        banyakCara[i][i].second = 1;

        if (i < n)
        {
            banyakCara[i][i + 1].first = 1;
            banyakCara[i][i + 1].second = 1;
        }
    }

    for (ll l = 2; l <= n; l++) // l means length
    {

        for (ll i = 1; i <= n - l + 1; i++)
        {
            ll res = LONG_LONG_MAX;
            ll countOptimalTotal = 0;
            ll countWays = 0;
            ll ujung = i + l - 1;

            for (ll k = i; k < ujung; k++)
            {
                countWays += ((banyakCara[i][k].first % 26101991) * (banyakCara[k + 1][ujung].first % 26101991) % 26101991);
                ll countOptimal = ((banyakCara[i][k].second % 26101991) * (banyakCara[k + 1][ujung].second % 26101991) % 26101991);

                if (res > cost[i][k] + cost[k + 1][ujung] + arr[i - 1] * arr[k] * arr[ujung])
                {
                    countOptimalTotal = countOptimal;
                    res = cost[i][k] + cost[k + 1][ujung] + arr[i - 1] * arr[k] * arr[ujung];
                }
                else if (res == cost[i][k] + cost[k + 1][ujung] + arr[i - 1] * arr[k] * arr[ujung])
                {
                    countOptimalTotal += countOptimal;
                }
            }

            cost[i][ujung] = res;
            banyakCara[i][ujung].first = countWays;
            banyakCara[i][ujung].second = countOptimalTotal;
        }
    }

    if (q == 1)
        cout << cost[1][n] << endl;
    else if (q == 2)
        cout << banyakCara[1][n].second % 26101991;
    else if (q == 3)
        cout << banyakCara[1][n].first % 26101991;
}

int main()
{
    ll tc = 1;
    // cin >> tc ;

    while (tc--)
    {
        solve();
    }
}