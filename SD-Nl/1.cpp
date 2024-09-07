//  Membangun Jalan Antar Kandang

#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> respresentative;

int findRep(int a)
{
    return (respresentative[a] == a) ? a : findRep(respresentative[a]);
}

void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i <= n; i++)
    {
        respresentative.push_back(i);
    }

    for (int i = 0; i < q; i++)
    {
        int act, a, b;
        cin >> act >> a >> b;

        if (act == 1)
            respresentative[findRep(max(a, b))] = findRep(min(a, b));

        if (act == 2)
        {
            if (findRep(a) == findRep(b))
                cout << "Y" << endl;
            else
                cout << "T" << endl;
        }

        // cout << "yess" << endl;
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