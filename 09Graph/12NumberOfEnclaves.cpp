void dfs(int n, int m, int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    vis[r][c] = 1;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0)
        {
            dfs(n, m, nr, nc, grid, vis);
        }
    }
}
int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1 && !vis[0][j])
        {
            dfs(n, m, 0, j, grid, vis);
        }
        if (grid[n - 1][j] == 1 && !vis[n - 1][j])
        {
            dfs(n, m, n - 1, j, grid, vis);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1 && !vis[i][0])
        {
            dfs(n, m, i, 0, grid, vis);
        }
        if (grid[i][m - 1] == 1 && !vis[i][m - 1])
        {
            dfs(n, m, i, m - 1, grid, vis);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
                ans++;
        }
    }
    return ans;
}