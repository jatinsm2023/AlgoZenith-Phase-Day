#include <bits/stdc++.h>
using namespace std;

using state = pair<int, int>;

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool is_valid(int x, int y, int N)
{
    if (x > 0 && x <= N && y > 0 && y <= N)
        return true;
    return false;
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
    if (Sx == Fx && Sy == Fy)
        return 0;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));
    queue<state> q;
    q.push({Sx, Sy});
    dist[Sx][Sy] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_valid(nx, ny, N) && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
                if (nx == Fx && ny == Fy)
                    return dist[nx][ny];
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;

    while (test_case--)
    {
        int N, Sx, Sy, Fx, Fy;
        cin >> N >> Sx >> Sy >> Fx >> Fy;

        cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
    }

    return 0;
}
