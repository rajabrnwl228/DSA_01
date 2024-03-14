bool bfs(int start, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> que;
    que.push({start, -1});
    vis[start] = 1;
    while (!que.empty())
    {
        int currentNode = que.front().first;
        int parent = que.front().second;
        que.pop();
        for (auto i : adj[currentNode])
        {
            if (!vis[i])
            {
                que.push({i, currentNode});
                vis[i] = 1;
            }
            else if (i != parent)
                return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (bfs(i, adj, vis))
                return true;
        }
    }
    return false;
}