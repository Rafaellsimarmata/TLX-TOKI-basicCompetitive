#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    int answer = 0;
    int a;

    cin >> a;

    for (int i = 1; i < N; i++)
    {
        int temp;
        cin >> temp;

        answer += max(a, temp);
        a = temp;
    }
    cout << answer;
}