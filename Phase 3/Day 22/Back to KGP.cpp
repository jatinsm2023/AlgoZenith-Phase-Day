#include <bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

using state = pair<int, int>;
const int INF = 1e18;
const int mod = 1e9 + 7;
int n, m;
vector<vector<state>> g;
vector<vector<state>> backedge;
vector<int> vis;
vector<pair<int, state>> dis;
vector<int> ways;

void bfs(int st)
{
    dis[st].F = 0;
    dis[st].S.F = 0;
    dis[st].S.S = 0;
    ways[st] = 1;
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.push({0, st});

    while (!pq.empty())
    {
        int node = pq.top().S;
        pq.pop();

        if (vis[node])
            continue;
        vis[node] = 1;

        for (auto v : g[node])
        {
            int next = v.F;
            int weight = v.S;
            if (dis[next].F > dis[node].F + weight)
            {
                dis[next].F = dis[node].F + weight;
                pq.push({dis[next].F, next});
            }
        }

        for (auto v : backedge[node])
        {
            if (dis[node].F == dis[v.F].F + v.S)
            {
                ways[node] = (ways[v.F] + ways[node]) % mod;
                dis[node].S.S = max(dis[node].S.S, dis[v.F].S.S + 1);
                dis[node].S.F = min(dis[node].S.F, dis[v.F].S.F + 1);
            }
        }
    }
}

signed main()
{

    cin >> n >> m;
    g.resize(n + 1);
    backedge.resize(n + 1);
    vis.assign(n + 1, 0);
    ways.assign(n + 1, 0);
    dis.assign(n + 1, {INF, {INF, -INF}});

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        backedge[b].push_back({a, c});
    }
    bfs(1);
    // for( int i=1; i<=n; i++){
    //     cout<<dis[i].F<<" "<<dis[i].S.F<<" "<<dis[i].S.S<<'\n';
    // }

    // for( int i=1; i<=n; i++){
    //     cout<<ways[i]<<" ";
    // }
    // cout<<'\n';
    if (dis[n].F != INF)
        cout << dis[n].F << " " << ways[n] << " " << dis[n].S.F << " " << dis[n].S.S << "\n";
    else
        cout << -1 << '\n';
}
