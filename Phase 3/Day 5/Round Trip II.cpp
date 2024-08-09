// Find Cycle
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> col;

// col - 1 => not visited
// col - 2 => visiting
// col - 3 => already visited

int n, m;
bool is_cycle = false;

void dfs(int node)
{
    col[node] = 2; // visiting
    for (auto v : g[node])
    {
        if (col[v] == 1)
        { // if not visited
            dfs(v);
        }
        else if(col[v]==2){
            is_cycle = true;
        }
    }
    col[node] = 3; // visited
}

void solve()
{
    cin >> n >> m;
    g.resize(n + 1);
    col.assign(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); // directed graph
    }

    for (int i = 1; i <= n; i++)
    {
        if (col[i] == 1)
        {
            dfs(i);
        }
    }

    if (is_cycle)
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}