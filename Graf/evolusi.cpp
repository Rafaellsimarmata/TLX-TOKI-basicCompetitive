#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    unordered_map<string, string> mp;

    for (int i = 0; i < m; i++)
    {
        string parent, child;
        cin >> parent >> child;

        mp[child] = parent;
    }

    // for (auto i : mp)
    // {
    //     for (auto j : i.second)
    //     {
    //         cout << "Child : " << i.first << " Parent : " << j << endl;
    //     }
    // }
    string a, b;
    cin >> a >> b;

    vector<string> ans;
    string child1 = a;
    ans.push_back(child1);
    bool isFalse = true;

    while (isFalse)
    {
        if (mp[child1] != "")
        {
            if (mp[child1] == b)
            {
                isFalse = false;
                ans.push_back(mp[child1]);
                break;
            }
            ans.push_back(mp[child1]);
            child1 = mp[child1];
        }
        else
            break;
    }

    if (isFalse)
    {
        ans.clear();
        child1 = b;
        ans.push_back(child1);
    }
    while (isFalse)
    {
        if (mp[child1] != "")
        {
            if (mp[child1] == a)
            {
                isFalse = false;
                ans.push_back(mp[child1]);
                break;
            }
            ans.push_back(mp[child1]);
            child1 = mp[child1];
        }
        else
            break;
    }

    if (isFalse)
        cout << "TIDAK MUNGKIN";
    else
    {
        for (int i = ans.size() - 1; i >= 0; i--)
            cout << ans[i] << endl;
    }
}