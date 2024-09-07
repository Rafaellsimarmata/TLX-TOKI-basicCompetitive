// angka sangar

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll, ll>> p = {
    {1, 10},
    {5, 10},
    {6, 10},
    {25, 100},
    {76, 100},
    {376, 1000},
    {625, 1000},
    {9376, 10000},
    {90625, 100000},
    {109376, 1000000},
    {890625, 1000000},
    {2890625, 10000000},
    {7109376, 10000000},
    {12890625, 100000000},
    {87109376, 100000000},
    {212890625, 1000000000},
    {787109376, 1000000000},
};

void solve()
{
    // for (ll i = 11; i <= 1e9; i++)
    // {
    //     ll temp = i * i;
    //     if (!(temp % 10 == 6 || temp % 10 == 5 || temp % 10 == 1))
    //         continue;

    //     ll mod = 10;

    //     while (mod < i)
    //     {
    //         mod *= 10;
    //         if (temp % mod == i)
    //             cout << "{ " << i << " , " << mod << " }, " << endl;
    //     }
    // }

    ll n;
    cin >> n;

    for (auto i : p)
    {
        ll c = i.first;
        ll multp = i.second;

        for (int a = 1; a <= 1e5; a++)
        {
            ll nc = n * multp + c; // NC
            ll ac = a * multp + c; // AC

            if (nc % ac != 0)
                continue;
            if (ac >= nc)
                break;

            ll bc = nc / ac;

            if (bc % multp == c)
            {
                cout << "YA \n";
                cout << a << " " << bc / multp << " " << c;
                return;
            }
        }
    }
    cout << "TIDAK \n";
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