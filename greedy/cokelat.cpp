#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll N;
pair<ll, ll> bebek[100002];
ll D;

bool sortTerm(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}

int main()
{
    cin >> N >> D;

    for (ll i = 0; i < N; i++)
    {
        cin >> bebek[i].first >> bebek[i].second;
    }

    sort(bebek, bebek + N, sortTerm);
    ll res = 0;

    for (ll i = 0; i < N; i++)
    {
        if (D < bebek[i].first)
            break;

        if (D / bebek[i].first >= bebek[i].second)
        {
            res += bebek[i].second;
            D -= bebek[i].first * bebek[i].second;
        }
        else
        {
            ll sisa = D / bebek[i].first;
            D -= bebek[i].first * sisa;
            res += sisa;
        }
    }

    cout << res;
}