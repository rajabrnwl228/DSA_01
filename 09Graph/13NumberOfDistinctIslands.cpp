void dfs(int n, int m, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vec, int r0, int c0)
{
    vis[r][c] = 1;
    vec.push_back({r - r0, c - c0});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0)
        {
            dfs(n, m, nr, nc, grid, vis, vec, r0, c0);
        }
    }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
    // code here
    int n = grid.size();
    int m = grid[0].size();
    set<vector<pair<int, int>>> s;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
            {
                vector<pair<int, int>> vec;
                dfs(n, m, i, j, grid, vis, vec, i, j);
                s.insert(vec);
            }
        }
    }
    return s.size();
}

// space optimize
vector<vector<int>> nearest(vector<vector<int>> grid)
{
    // Code here
    int m = grid.size();
    int n = grid[0].size();
    // vector<vector<int>>vis(m,vector<int>(n,0));
    vector<vector<int>> ans(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> que;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                que.push({{i, j}, 0});
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
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && ans[nr][nc] == 0 && grid[nr][nc] != 1)
            {
                que.push({{nr, nc}, t + 1});
                ans[nr][nc] = t + 1;
            }
        }
    }
    return ans;
}
}
;