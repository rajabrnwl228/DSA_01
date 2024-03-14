class Solution
{
public:
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
    int minimumConnections(int n, vector<vector<int>> &connections)
    {
        // code here
        // count the extraEdge and numberOfComponent  if (extraEdge>=ans) return ans(ans=NumberOfComponents-1)  else -1
        DisjointSet ds(n);
        int extEdg = 0, ConCom = 0;
        for (auto it : connections)
        {
            int node = it[0];
            int adjnode = it[1];
            if (ds.findPar(node) == ds.findPar(adjnode))
                extEdg++;
            else
            {
                ds.unionBySize(node, adjnode);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (ds.findPar(i) == i)
                ConCom++;
        }
        if (extEdg >= ConCom - 1)
            return ConCom - 1;
        return -1;
    }