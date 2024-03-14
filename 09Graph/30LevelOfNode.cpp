int dfs(int start, vector<int> &vis, vector<int> adj[], int X, int count)
{
    if (start == X)
        return count;
    vis[start] = 1;
    for (auto i : adj[start])
    {
        if (!vis[i])
        {
            int a = dfs(i, vis, adj, X, count + 1);
            if (a != -1)
                return a;
        }
    }
    return -1;
}
// Function to find the level of node X.
int nodeLevel(int V, vector<int> adj[], int X)
{
    // code here
    int count = 0;
    vector<int> vis(V, 0);
    count = dfs(0, vis, adj, X, count);
    return count;
}