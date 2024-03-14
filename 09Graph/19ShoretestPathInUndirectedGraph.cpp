void topo(int Node, int N, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[Node] = 1;
    for (auto i : adj[Node])
    {
        if (!vis[i.first])
            topo(i.first, N, adj, vis, st);
    }
    st.push(Node);
}

public:
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        vector<int> Node = edges[i];
        adj[Node[0]].push_back({Node[1], Node[2]});
    }
    stack<int> st;
    vector<int> vis(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
            topo(i, N, adj, vis, st);
    }
    vector<int> dis(N, 1e9);
    dis[0] = 0;
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        for (auto c : adj[p])
        {
            int i = c.first;
            int wt = c.second;
            if (dis[p] + wt < dis[i])
            {
                dis[i] = dis[p] + wt;
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