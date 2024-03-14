
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indeg(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indeg[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        ans.push_back(x);
        q.pop();
        for (auto i : adj[x])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                q.push(i);
        }
    }
    return ans;
}