class DisjointSet
{
    vector<int> size;
    vector<int> rank;
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        size.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

public:
// Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here

    // because we want to store first weight then node and adjnode
    // and given data is like node ispointed to vectr of vector which means every node have a vector and inside vector we node and their weight both store in vector data structure

    vector<pair<int, pair<int, int>>> edges;
    // O(N+E)
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int adjnode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt, {node, adjnode}});
        }
    }
    // to get minimum edge weight first
    sort(edges.begin(), edges.end());
    // to check does they belong to same component means making a loop
    DisjointSet ds(V);
    int sum = 0;

    // M*4alpha*2
    for (auto i : edges)
    {
        int wt = i.first;
        int u = i.second.first;
        int v = i.second.second;
        int ulp_u = ds.findPar(u);
        int ulp_v = ds.findPar(v);
        if (ulp_u == ulp_v)
            continue;
        sum += wt;
        // connect the component (not real link) make ultimate parent same
        ds.unionBySize(u, v);
    }
    return sum;
}