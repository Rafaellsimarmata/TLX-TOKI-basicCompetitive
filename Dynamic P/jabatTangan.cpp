#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;

    if (n % 2 != 0)
        cout << 1;
    else
    {
        ll dp[n + 1] = {0};
        dp[0] = 1;
        dp[2] = 1;

        for (int i = 4; i <= n; i += 2)
        {
            ll sum = 0;
            for (int j = 2; j <= i; j += 2)
            {
                sum += dp[j - 2] * dp[i - j];
            }
            dp[i] = sum;
        }

        cout << dp[n];
    }
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