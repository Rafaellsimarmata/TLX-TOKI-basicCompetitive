#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct compare
{
    bool operator()(const pair<ll, ll> &l, const pair<ll, ll> &r)
    {
        if (l.second == r.second)
            return l.first < r.first;

        return l.second > r.second;
    }
};

void solve()
{
    string label;
    cin >> label;

    ll n, staminaDengklek, sm;
    cin >> n >> staminaDengklek >> sm;

    ll timeAns = 0;
    bool solveAble = true;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compare> sd;

    for (ll i = 0; i < n - 1; i++)
    {
        ll reqStamina, timeKabur, timeLawan;
        cin >> reqStamina >> timeKabur >> timeLawan;

        while (reqStamina > staminaDengklek)
        {
            if (!sd.empty())
            {
                ll timeConsumed = sd.top().second;
                sd.pop();
                timeAns += timeConsumed;
                staminaDengklek++;
            }
            else
            {
                solveAble = false;
                break;
            }
        }

        sd.push(make_pair(timeKabur, timeLawan));
    }

    while (staminaDengklek < sm && solveAble)
    {
        if (!sd.empty())
        {
            ll timeConsumed = sd.top().second;
            sd.pop();
            timeAns += timeConsumed;
            staminaDengklek++;
        }
        else
        {
            solveAble = false;
            break;
        }
    }

    while (!sd.empty())
    {
        timeAns += min(sd.top().first, sd.top().second);
        sd.pop();
    }

    if (!solveAble)
        cout << -1;
    else
        cout << timeAns;
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