 vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>ans;
	    vector<int>indeg(V,0);
	    for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
	    }
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0)
	        q.push(i);
	    }
	    while(!q.empty()){
	        int x=q.front();
	        ans.push_back(x);
	        q.pop();
	        for(auto i:adj[x]){
	            indeg[i]--;
	            if(indeg[i]==0)
	                q.push(i);
	        }
	    }
	    return ans;
	}
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int p=0;p<len;p++){
                if(s1[p]!=s2[p]){
                    adj[s1[p]-'a'].push_back(s2[p]-'a');
                    break;
                }
            }
        }
        vector<int>topo=topoSort(K,adj);
        string ans="";
        for(auto i:topo){
            ans=ans+char(i+'a');
        }
        return ans;
        
        
    }