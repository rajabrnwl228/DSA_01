bool isBipartite_bfs(int s, vector<int> adj[], int *color)
{
    queue<int> que;
    que.push(s);
    color[s] = 0;
    while (!que.empty())
    {
        int p = que.front();
        que.pop();
        for (auto i : adj[p])
        {
            if (color[i] == -1)
            {
                color[i] = !color[p];
                que.push(i);
            }
            else if (color[i] == color[p])
                return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here

    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite_bfs(i, adj, color))
                return false;
        }
    }
    return true;
}