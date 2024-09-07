#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<double, double>> point;

double dist(double x, double y, double xa, double ya)
{
    return sqrt((xa - x) * (xa - x) + (ya - y) * (ya - y));
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        point.push_back(make_pair(x, y));
    }

    double ans = 100000005;
    bool duplicate = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                double a = dist(point[i].first, point[i].second, point[j].first, point[j].second);
                double b = dist(point[i].first, point[i].second, point[k].first, point[k].second);
                double c = dist(point[k].first, point[k].second, point[j].first, point[j].second);

                double s = (a + b + c) / (double)2;
                double luas = sqrt(s * (s - a) * (s - b) * (s - c));

                if (ans > luas)
                {
                    duplicate = false;
                    ans = luas;
                }
                else if (ans == luas)
                    duplicate = true;
            }
        }
    }

    if (duplicate || ans == 100000005)
        cout << "-1.00";
    else
        cout << fixed << setprecision(2) << ans;
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