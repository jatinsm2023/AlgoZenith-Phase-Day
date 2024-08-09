#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> vis;
map<int, int> mp;
void dfs(int node, int comp_no)
{
    vis[node] = 1;
    mp[node] = comp_no;
    for (auto v : g[node])
    {
        if (!vis[v])
        {
            dfs(v, comp_no);
        }
    }
    return;
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n + 1);
    vis.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != b)
        {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    int compo_no = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            compo_no++;
            dfs(i, compo_no);
        }
    }
    vector<int> component(compo_no + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        component[mp[i]]++;
    }

    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            cout << component[mp[y]] << '\n';
        }
        else if (x == 2)
        {
            int y, z;
            cin >> y >> z;
            if (mp[y] == mp[z])
            {
                cout << "YES" << '\n';
            }
            else
            {
                cout << "NO" << '\n';
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}