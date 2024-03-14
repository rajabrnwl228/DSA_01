void change(int r, int c, int m, int n, vector<vector<int>> &upd)
{
    // row
    for (int i = 0; i < m; i++)
    {
        upd[i][c] = 0;
    }
    // col
    for (int i = 0; i < n; i++)
    {
        upd[r][i] = 0;
    }
}

public:
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> upd(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                change(i, j, m, n, upd);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (upd[i][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}