#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define int long long

using state = pair<int, int>;
vector<vector<int>> vis;
vector<vector<int>> vis2;
vector<vector<int>> graph;
vector<vector<int>> finalans;
int n, m;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool is_valid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && graph[x][y] != 1)
        return true;
    return false;
}

vector<state> neighbours(state node)
{
    vector<state> ans;
    for (int i = 0; i < 4; i++)
    {
        int x = node.F + dx[i];
        int y = node.S + dy[i];
        if (is_valid(x, y))
        {
            ans.push_back({x, y});
        }
    }
    return ans;
}

void real_solve(state st_node, int value)
{
    vis2[st_node.F][st_node.S] = 1;
    finalans[st_node.F][st_node.S] = value;

    queue<state> q;
    q.push(st_node);

    while (!q.empty())
    {
        state node = q.front();
        q.pop();

        for (auto v : neighbours(node))
        {
            if (vis2[v.F][v.S] == 0)
            {
                vis2[v.F][v.S] = 1;
                q.push(v);
                finalans[v.F][v.S] = value;
            }
        }
    }
}
int bfs(state st_node)
{
    vis[st_node.F][st_node.S] = 1;
    int ans = 1;

    queue<state> q;
    q.push(st_node);

    while (!q.empty())
    {
        state node = q.front();
        q.pop();

        for (auto v : neighbours(node))
        {
            if (vis[v.F][v.S] == 0)
            {
                vis[v.F][v.S] = 1;
                q.push(v);
                ans++;
            }
        }
    }
    return ans;
}

void solve()
{
    cin >> n >> m;
    graph.assign(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));
    vis2.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
        }
    }
    finalans.assign(n, vector<int>(m, 0));
    finalans = graph;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0 && graph[i][j] == 0)
            {
                int value = bfs({i, j});
                if (value == 1)
                {
                    real_solve({i, j}, 0);
                }
                else
                    real_solve({i, j}, value);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << finalans[i][j] << " ";
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}