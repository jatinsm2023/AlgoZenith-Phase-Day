#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define int long long
using state = pair<int, int>;
int n;
vector<vector<char>> grid;
vector<vector<int>> vis;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool is_valid(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < n) return true;
    return false;
}

state perimeter(state node) {
    int x = node.F;
    int y = node.S;

    state values = {0, 0};
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (is_valid(xx, yy)) {
            if (grid[xx][yy] == '.' || !vis[xx][yy]) {
                if (grid[xx][yy] == '.') {
                    values.F++;
                } else if (!vis[xx][yy]) {
                    state new_values = perimeter({xx, yy});
                    values.F += new_values.F;
                    values.S += new_values.S + 1;
                }
            }
        } else {
            values.F++;
        }
    }
    return values;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    grid.assign(n, vector<char>(n));
    vis.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    state parameters = {0,0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j] && grid[i][j] == '#') {
                state value = perimeter({i, j});
               
                if(parameters.S<value.S){
                    parameters = value;
                }
                else if(parameters.S==value.S && parameters.F>value.F){
                    parameters = value;
                }
            }
        }
    }
   
    cout<<parameters.S+1<<" "<<parameters.F<<'\n';

    return 0;
}
