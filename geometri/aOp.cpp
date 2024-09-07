#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct point
{
    double x, y;
};

void solve()
{
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    point p1 = {x1, y1}, p2 = {x2, y2};
    double dist = hypot(p2.x - p1.x, p2.y - p1.y);

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