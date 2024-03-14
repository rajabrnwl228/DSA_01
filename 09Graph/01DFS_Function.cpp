    #include<vector>
     void dfs_helper(int start,vector<int>adj[],vector<int>&vis,vector<int>&ans){
        vis[start]=1;
        ans.push_back(start);
        //  for(auto i:adj[start]){
        //     if(!vis[i]){
        //         dfs_helper(i,adj,vis,ans);
        //     }
        // }
        //using iterator
        vector<int>::iterator it;
        for(it=adj[start].begin();it!=adj[start].end();it++){
            if(!vis[*it]){
                dfs_helper(*it,adj,vis,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        vector<int>ans;
        int start=0;
        dfs_helper(start,adj,vis,ans);
        return ans;
    }