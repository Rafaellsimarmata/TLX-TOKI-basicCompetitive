#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;

bool isSorted(vector<int> &tempArr)
{
    for (int i = 1; i < n; i++)
        if (tempArr[i] > tempArr[i + 1])
            return false;
    return true;
}

vector<int> reverseSubArray(int l, int r, vector<int> tempArr)
{
    while (l < r)
    {
        int temp = tempArr[l];
        tempArr[l] = tempArr[r];
        tempArr[r] = temp;
        r--;
        l++;
    }
    return tempArr;
}

void solve()
{
    cin >> n;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cin >> k;

    queue<pair<vector<int>, int>> q; // node, depth
    set<vector<int>> st;             // to check whether the combination array is listed already or not

    q.push(make_pair(arr, 0));
    st.insert(arr);

    while (!q.empty())
    {
        vector<int> curr = q.front().first;
        int depth = q.front().second;
        q.pop();

        if (isSorted(curr))
        {
            // for (auto i : curr)
            // {
            //     cout << i << " ";
            // }
            // cout << endl;
            cout << depth << endl;
            return;
        }
        for (int i = 1; i + k - 1 <= n; i++)
        {
            vector<int> reversedArr = reverseSubArray(i, i + k - 1, curr);
            if (!st.count(reversedArr))
            {
                st.insert(reversedArr);
                q.push(make_pair(reversedArr, depth + 1));
            }
        }
    }
    cout << -1;
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