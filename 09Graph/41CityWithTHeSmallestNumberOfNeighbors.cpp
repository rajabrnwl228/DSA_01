int findCity(int n, int m, vector<vector<int>> &edges,
             int distanceThreshold)
{
    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
    for (auto it : edges)
    {
        dis[it[0]][it[1]] = it[2];
        dis[it[1]][it[0]] = it[2];
    }
    for (int dia = 0; dia < n; dia++)
        dis[dia][dia] = 0;
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][via] == INT_MAX && dis[via][j] == INT_MAX)
                    continue;
                dis[i][j] = min(dis[i][j], dis[i][via] + dis[via][j]);
            }
        }
    }
    int cntcity = n;
    int cityno = -1;
    for (int city = 0; city < n; city++)
    {
        int cnt = 0;
        for (int adjcity = 0; adjcity < n; adjcity++)
        {
            if (dis[city][adjcity] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= cntcity)
        {
            cntcity = cnt;
            cityno = city;
        }
    }
    return cityno;
}