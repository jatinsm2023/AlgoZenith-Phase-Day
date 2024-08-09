#include <bits/stdc++.h>
using namespace std;

#define int long long
string cur = "";
int n;
int ans = 0;
void rec(int l1, int l2, vector<vector<char>> &board)
{
    if (cur.size() > n)
        return;
    if (cur.size() == n)
    {
        cout << cur << '\n';
        ans++;
        return;
    }
    if ((l2 > board.size() || l2 > board[0].size()) || (l1 < 0 || l2 < 0) || (l1 == board.size() || l2 == board[0].size()))
    {
        if (cur.size() == n)
        {
            cout << cur << '\n';
            ans++;
        }
        return;
    }

    cur += board[l1][l2];
    rec(l1, l2 + 1, board);
    rec(l1 + 1, l2, board);
    rec(l1 - 1, l2, board);
    rec(l1, l2 - 1, board);
    cur.pop_back();
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<char>> board = {{'A', 'B', 'C'}, {'D', 'E', 'F'}, {'G', 'H', 'I'}};
     for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {

            rec(i, j, board);
        }
    }
    cout << ans << '\n';
}