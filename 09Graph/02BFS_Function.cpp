    #include<vector>
    #include<queue>
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V+1,0);
        vector<int>ans;
        int start=0;
        queue<int>que;
        que.push(start);
        vis[0]=1;
        while(!que.empty()){
            int currentNode=que.front();
            que.pop();
            ans.push_back(currentNode);
            for(auto i:adj[currentNode]){
                if(!vis[i]){
                    que.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans;
    }