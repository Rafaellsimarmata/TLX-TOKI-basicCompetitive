#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    int dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    if (dist > r1 + r2 || dist + r1 < r2 || dist + r2 < r1)
        cout << "tidak bersentuhan";
    else
        cout << "bersentuhan";
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