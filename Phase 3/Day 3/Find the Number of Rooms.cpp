#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<string> g;
int vis[1000][1000];
int sx[] = {1, 0, -1, 0};
int sy[] = {0, 1, 0, -1};

bool is_valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    else
        return true;
}

void dfs(int x, int y)
{
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        if (is_valid(x + sx[i], y + sy[i]) && g[x + sx[i]][y + sy[i]] == '.')
        {
            if (!vis[x + sx[i]][y + sy[i]])
            {
                dfs(x+sx[i],y+sy[i]);
            }
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < n; i++)
    {
        cin>>g[i];
    }

    int ans = 0;
    for( int i=0; i<n ;i++)
    {
        for(int j=0; j<m; j++)
        {
            if(g[i][j] == '.' && !vis[i][j])
            {
                ans++;
                dfs(i,j);
            }
        }
    }

    cout<<ans<<'\n';
}