vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{
    // code here
    vector<int> adj[N];
    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> dis(N, 1e9);
    dis[src] = 0;

    queue<pair<int, int>> q;
    q.push({src, 0});
    while (!q.empty())
    {
        pair<int, int> node = q.front();
        int p = node.first;
        int t = node.second;
        q.pop();
        for (auto i : adj[p])
        {
            if (dis[p] + 1 < dis[i])
            {
                q.push({i, t + 1});
                dis[i] = t + 1;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (dis[i] == 1e9)
            dis[i] = -1;
    }
    return dis;
}