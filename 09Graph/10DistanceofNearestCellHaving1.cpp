vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> que;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                que.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    while (!que.empty())
    {
        int r = que.front().first.first;
        int c = que.front().first.second;
        int t = que.front().second;
        ans[r][c] = t;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && vis[nr][nc] == 0)
            {
                vis[nr][nc] = 1;
                que.push({{nr, nc}, t + 1});
            }
        }
    }
    return ans;
}