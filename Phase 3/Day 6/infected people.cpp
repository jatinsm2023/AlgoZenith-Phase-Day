#include <bits/stdc++.h>
using namespace std;

using state = pair<int,int>;
int n,m;
vector <vector <int>>grid;
vector <vector <int>> vis;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

bool is_valid(int x, int y){
    if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==1e9 && grid[x][y]!=0)return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
    grid.assign(n, vector <int> (m));
    vis.assign(n, vector <int> (m, 1e9));
	queue <state> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
            if (grid[i][j] == 2) {
				vis[i][j] = 0;
				q.push({i, j});
			}
		}
	}
	
	while (!q.empty()) {
		state cur = q.front();
		q.pop();
		int x, y;
		x = cur.first;
		y = cur.second;
		for( int i=0; i<4; i++){
		    int xx = x+dx[i];
		    int yy = y+dy[i];
		    if(is_valid(xx,yy)){
		        vis[xx][yy] = vis[x][y]+1;
		        q.push({xx,yy});
		    }
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] != 0) {
				ans = max(ans, vis[i][j]);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		    cout<<vis[i][j]<<" ";
		}
		cout<<'\n';
	}
	
	
	if (ans == 1e9)
		ans = -1;
	cout << ans;
}
