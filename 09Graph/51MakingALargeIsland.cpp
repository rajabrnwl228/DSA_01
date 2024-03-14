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

public:
int largestIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    DisjointSet ds(n * n);
    int ans = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == 0)
                continue;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    int node = r * n + c;
                    int adjnode = nr * n + nc;
                    ds.unionBySize(node, adjnode);
                }
            }
        }
    }
    int mx = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == 1)
                continue;
            set<int> comp;
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1)
                {
                    comp.insert(ds.findPar(nr * n + nc));
                }
            }
            int sizetotal = 0;
            for (auto it : comp)
            {
                sizetotal += ds.size[it];
            }
            mx = max(mx, sizetotal + 1);
        }
    }
    for (int cell = 0; cell < n * n; cell++)
    {
        mx = max(mx, ds.size[ds.findPar(cell)]);
    }
    return mx;
    // Your code goes here.
}