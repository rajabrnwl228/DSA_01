bool dfs(int child, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[child] = 1;
    for (auto i : adj[child])
    {
        if (!vis[i])
        {
            if (dfs(i, child, adj, vis))
                return true;
        }
        else if (i != parent)
            return true;
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
            if (dfs(i, -1, adj, vis))
                return true;
        }
    }
    return false;
    // Code here
}