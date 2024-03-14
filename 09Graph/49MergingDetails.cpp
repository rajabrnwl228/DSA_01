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
vector<vector<string>> mergeDetails(vector<vector<string>> &details)
{
    // code here
    unordered_map<string, int> mapMailNode;
    int n = details.size();
    DisjointSet ds(n);
    // create map for mails
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < details[i].size(); j++)
        {
            string mail = details[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end())
            {
                mapMailNode[mail] = i;
            }
            else
            {
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }
    // merge
    vector<string> mergeMail[n];
    for (auto it : mapMailNode)
    {
        string mail = it.first;
        int node = ds.findPar(it.second);
        mergeMail[node].push_back(mail);
    }
    // return ans
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
        if (mergeMail[i].size() == 0)
            continue;
        sort(mergeMail[i].begin(), mergeMail[i].end());
        vector<string> temp;
        // name push
        temp.push_back(details[i][0]);
        for (auto it : mergeMail[i])
        {
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}