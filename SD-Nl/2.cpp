#include <bits/stdc++.h>
using namespace std;
#define ll long long

priority_queue<int> pq;

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int act;
        cin >> act;

        if (act == 1)
        {
            int tempPrice;
            cin >> tempPrice;
            pq.push(tempPrice);
        }
        if (act == 2)
        {
            cout << pq.top() << endl;
        }
        if (act == 3)
        {
            pq.pop();
        }
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