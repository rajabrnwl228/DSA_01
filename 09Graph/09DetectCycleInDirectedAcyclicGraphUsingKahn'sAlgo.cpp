
bool isCyclic(int V, vector<int> adj[])
{
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
        q.pop();
        for (auto i : adj[x])
        {
            indeg[i]--;
            if (indeg[i] == 0)
                q.push(i);
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (indeg[i] != 0)
        {
            return true;
        }
    }
    return false;
}