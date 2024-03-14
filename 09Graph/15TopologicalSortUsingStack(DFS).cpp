void dfs(int start, vector<int> adj[], vector<int> &vis, stack<int> &ans)
{
    vis[start] = 1;
    for (auto i : adj[start])
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, ans);
        }
    }
    ans.push(start);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, adj, vis, ans);
    }
    vector<int> a;
    while (!ans.empty())
    {
        int x = ans.top();
        a.push_back(x);
        ans.pop();
    }
    return a;
}