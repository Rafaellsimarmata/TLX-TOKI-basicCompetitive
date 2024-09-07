#include <bits/stdc++.h>
using namespace std;
#define ll long long

int x1, y1a, x2, y2, x3, y3, x4, y4;

bool checkInSquare(int x, int y)
{
    if (((x >= x1 && x <= x2) || (x >= x2 && x <= x1)) && ((y >= y1a && y <= y2) || (y >= y2 && y <= y1a)))
        return true;
    return false;
}

void solve()
{
    cin >> x1 >> y1a >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // cout << x1;

    // cek kedua titik ujung garis berada di interval atau tidak
    if (checkInSquare(x3, y3) != checkInSquare(x4, y4))
        cout << "YA \n";
    else
        cout << "TIDAK \n";
}

int main()
{
    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }
}