#include <bits/stdc++.h>
using namespace std;

int a, b, mapX, mapY;
int world[105][105];
bool visited[105][105] = {0};
int depth[105][105];
queue<pair<int, int>> q;

int main()
{
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            cin >> world[i][j];
        }
    }

    cin >> mapX >> mapY;

    pair<int, int> base;
    base.first = mapX;
    base.second = mapY;
    q.push(base);
    depth[mapX][mapY] = 1;

    while (!q.empty())
    {
        int mapX_temp = q.front().first, mapY_temp = q.front().second;
        visited[mapX_temp][mapY_temp] = 1;
        q.pop();

        if (mapX_temp == 1 || mapX_temp == a || mapY_temp == 1 || mapY_temp == b)
        {
            cout << depth[mapX_temp][mapY_temp];
            exit(0);
        }

        if (mapX_temp < 1 || mapX_temp > a || mapY_temp < 1 || mapY_temp > b)
        {
            continue;
        }

        if (world[mapX_temp - 1][mapY_temp] == 0 && visited[mapX_temp - 1][mapY_temp] == 0)
        {
            depth[mapX_temp - 1][mapY_temp] = depth[mapX_temp][mapY_temp] + 1;
            q.push(make_pair(mapX_temp - 1, mapY_temp));
        }

        if (world[mapX_temp][mapY_temp - 1] == 0 && visited[mapX_temp][mapY_temp - 1] == 0)
        {
            depth[mapX_temp][mapY_temp - 1] = depth[mapX_temp][mapY_temp] + 1;
            q.push(make_pair(mapX_temp, mapY_temp - 1));
        }

        if (world[mapX_temp + 1][mapY_temp] == 0 && visited[mapX_temp + 1][mapY_temp] == 0)
        {
            depth[mapX_temp + 1][mapY_temp] = depth[mapX_temp][mapY_temp] + 1;
            q.push(make_pair(mapX_temp + 1, mapY_temp));
        }

        if (world[mapX_temp][mapY_temp + 1] == 0 && visited[mapX_temp][mapY_temp + 1] == 0)
        {
            depth[mapX_temp][mapY_temp + 1] = depth[mapX_temp][mapY_temp] + 1;
            q.push(make_pair(mapX_temp, mapY_temp + 1));
        }
    }
}