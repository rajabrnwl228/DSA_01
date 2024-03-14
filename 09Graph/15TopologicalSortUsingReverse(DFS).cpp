void dfs(int start, vector<int> adj[], vector<int> &vis, vector<int> &ans)
{
    vis[start] = 1;
    for (auto i : adj[start])
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }
    ans.push_back(start);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, ans);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}