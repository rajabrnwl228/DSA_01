#include<vector>
#include<queue>
//using bfs
void bfs(int start,int V,vector<vector<int>>&adj,vector<int>&vis){
        queue<int>que;
        que.push(start);
        vis[start]=1;
        while(!que.empty()){
            int currentNode=que.front();
            que.pop();
            for(int i=0;i<V;i++){
                if(adj[currentNode][i]==1&&!vis[i]){
                    que.push(i);
                    vis[i]=1;
                }
            }
        }
  }
int numProvinces(vector<vector<int>> adj, int V) {
    // code here
        vector<int>vis(V+1,0);
    int ans=0;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            bfs(i,V,adj,vis);
            ans++;
        }
    }
    return ans;
}
//using dfs
  void dfs(int start,int V,vector<vector<int>>&adj,vector<int>&vis){
       vis[start]=1;
         for(int i=0;i<V;i++){
            //  if(start==i) continue;
            if(adj[start][i]==1&&!vis[i]){
                dfs(i,V,adj,vis);
            }
        }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
           vector<int>vis(V+1,0);
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,V,adj,vis);
                ans++;
            }
        }
        return ans;
    }