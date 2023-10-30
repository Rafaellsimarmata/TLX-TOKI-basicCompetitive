#include <iostream>
#include <cstring>
using namespace std;

int N;
int ans[50][50];
bool computed[50][50];

int solve(string target, int left, int right)
{
    if (left > right)
        return 0;

    if (left == right)
        return 1;

    if (computed[left][right])
        return ans[left][right];

    int best = max(solve(target, left, right - 1), solve(target, left + 1, right));

    if (target[left] == target[right])
        best = max(solve(target, left + 1, right - 1) + 2, best);

    computed[left][right] = true;
    ans[left][right] = best;
    return best;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string word;
        cin >> word;

        cout << solve(word, 0, word.length() - 1) << endl;
        memset(ans, 0, sizeof(ans));
        memset(computed, 0, sizeof(computed));
    }
}