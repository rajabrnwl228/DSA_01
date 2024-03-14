bool dfs(int child, int parent, vector<int> adj[], vector<int> &vis, vector<int> &vis2)
{
    vis[child] = 1;
    vis2[child] = 1;
    for (auto i : adj[child])
    {
        if (!vis[i])
        {
            if (dfs(i, child, adj, vis, vis2))
                return true;
        }
        else if (vis2[i])
            return true;
    }
    vis2[child] = 0;
    return false;
}
// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    vector<int> vis(V, 0);
    vector<int> vis2(V, 0);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1, adj, vis, vis2))
                return true;
        }
    }
    return false;
}