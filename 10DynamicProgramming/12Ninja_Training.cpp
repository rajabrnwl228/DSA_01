//Using recursion 
//TIme Complexity O(3^N)
//space Complexity O(N)

int ninjaTrainingRecursion(int last,int n,vector<vector<int>> &points){
    if(n==0){
        int ans=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                ans=max(ans,points[n][task]);
            }
        }
        return ans;
    }
    int ans=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int t=ninjaTrainingRecursion(task,n-1,points)+points[n][task];
            ans=max(ans,t);
        }
    }
    return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{

    int ans=0;
    for(int i=0;i<3;i++){
        ans=max(ans,ninjaTrainingRecursion(i,n-1,points));
    }
    return ans;
}
//Using Memoization 
//TIme Complexity ON*3*3)
//space Complexity O(N+N*3)
int ninjaTrainingRecursion(int last,int n,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(n==0){
        int ans=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                ans=max(ans,points[n][task]);
            }
        }
        dp[n][last]=ans;
        return ans;
    }
    if(dp[n][last]!=-1)return dp[n][last];
    int ans=0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int t=ninjaTrainingRecursion(task,n-1,points,dp)+points[n][task];
            ans=max(ans,t);
        }
    }
        dp[n][last]=ans;
        return ans;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{

    vector<vector<int>> dp(n,vector<int>(3,-1));
    int ans=0;
    for(int i=0;i<3;i++){
        ans=max(ans,ninjaTrainingRecursion(i,n-1,points,dp));
    }
    return ans;
}


//Using Memoization 
//TIme Complexity O(N*3*3)
//space Complexity O(N*3)
int ninjaTraining(int n, vector<vector<int>> &points){
   vector<vector<int>> dp(n,vector<int>(3,0));
    int ans=0;
    for(int i=n-2;i>=0;i--){
        for(int last=0;last<3;last++){
        int maxi=0;
            for(int task=0;task<3;task++){
                if(task!=last)
                maxi=max(maxi,points[i][task]);
            }
            dp[i][last]=maxi+points[i][last];
        }
    }
    return max(dp[0][0],dp[0][1],dp[0][2]);
}










int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int>prev(4,-1);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][1],points[0][0]);
    prev[3]=max(points[0][1],max(points[0][2],points[0][0]));
    for(int day=1;day<n;day++){
        vector<int>t(4,0);
        for(int last=0;last<4;last++){
            t[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last)
                t[last]=max(t[last],points[day][task]+prev[task]);
            }
        }
        prev=t;
    }
    return prev[3];
}