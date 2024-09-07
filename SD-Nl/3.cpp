#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string label;
    cin >> label;

    int n, staminaDengklek, sm;
    cin >> n >> staminaDengklek >> sm;

    ll timeAns = 0;

    priority_queue<int, vector<int>, greater<int>> sd;

    for (ll i = 0; i < n - 1; i++)
    {
        ll reqStamina, timeKabur, timeLawan;
        cin >> reqStamina >> timeKabur >> timeLawan;

        while (reqStamina > staminaDengklek)
        {
            if (!sd.empty())
            {
                ll timeConsumed = sd.top();
                sd.pop();
                timeAns += timeConsumed;
                staminaDengklek++;
            }
            else
            {
                cout << -1;
                return;
            }
        }

        if (timeLawan <= timeKabur)
        {
            timeAns += timeLawan;
            staminaDengklek++;
        }
        else
        {
            timeAns += timeKabur;
            sd.push(timeLawan - timeKabur);
        }
    }

    while (staminaDengklek < sm)
    {
        if (!sd.empty())
        {
            ll timeConsumed = sd.top();
            sd.pop();
            timeAns += timeConsumed;
            staminaDengklek++;
        }
        else
        {
            cout << -1;
            return;
        }
    }

    cout << timeAns;
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