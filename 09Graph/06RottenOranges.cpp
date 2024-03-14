int orangesRotting(vector<vector<int>> &grid)
{
    // Code here
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int, int>, int>> que;
    int rotten[m][n];
    int count = 0, countfresh = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                que.push({{i, j}, 0});
                rotten[i][j] = 2;
            }
            else
            {
                rotten[i][j] = 0;
            }
            if (grid[i][j] == 1)
                countfresh++;
        }
    }
    int mt = 0;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, -1, 0, 1};
    while (!que.empty())
    {
        int r = que.front().first.first;
        int c = que.front().first.second;
        int t = que.front().second;
        que.pop();
        mt = max(mt, t);
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && rotten[nr][nc] == 0)
            {
                que.push({{nr, nc}, t + 1});
                rotten[nr][nc] = 2;
                count++;
            }
        }
    }
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++)
    //     {
    //         if(grid[i][j]==1&&rotten[i][j]!=2)
    //         return -1;
    //     }
    // }
    if (count != countfresh)
        return -1;
    return mt;
}