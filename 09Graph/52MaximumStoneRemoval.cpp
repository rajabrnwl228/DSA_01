class DisjointSet
{

public:
    vector<int> size;
    vector<int> rank;

    vector<int> parent;
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

int maxRemove(vector<vector<int>> &stones, int n)
{
    // Code here
    int mr = 0, mc = 0;
    for (int i = 0; i < n; i++)
    {
        mr = max(mr, stones[i][0]);
        mc = max(mc, stones[i][1]);
    }
    DisjointSet ds(mr + mc + 1);
    unordered_map<int, int> stoneNodes;
    for (auto it : stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1] + mr + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }
    int cnt = 0;
    for (auto it : stoneNodes)
    {
        if (ds.findPar(it.first) == it.first)
            cnt++;
    }
    return n - cnt;
}