#include <bits/stdc++.h> 
// M-1 brute force 
//Time complexity is O(2^N);
// space complexity is O( N)
void helper(int i,vector<int> &nums,int count,int flag,int &ans){
    if(i==nums.size()) {
        ans=max(ans,count);
        return ;
    }
    if(flag==0)
        helper(i+1,nums,count+nums[i],1,ans);
    helper(i+1,nums,count,0,ans);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int ans=0;
    helper(0,nums,0,0,ans);
    return ans;
}

// M-2 brute force 
//Time complexity is O(2^N);
// space complexity is O( N)
int helper(int i,vector<int> &nums){
    if(i==0) return nums[i];
    if(i<0) return 0;
    int x=nums[i]+helper(i-2,nums);
    int y=helper(i-1,nums);
    return max(x,y);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int ans=0;
    ans=helper(nums.size()-1,nums);
    return ans;
}

// M-3 Memoziation 
//Time complexity is O(N);
// space complexity is O( N)
int helper(int i,vector<int> &nums,vector<int>&dp){
    if(i==0) return nums[i];
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    int x=nums[i]+helper(i-2,nums,dp);
    int y=helper(i-1,nums,dp);
    dp[i]=max(x,y);
    return dp[i];
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int>dp(nums.size(),-1);
    int ans=helper(nums.size()-1,nums,dp);
    return ans;
}
// M-4 Memoziation 
//Time complexity is O(N);
// space complexity is O( N)
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int dp[nums.size()];
    dp[0]=nums[0];
    for(int i=1;i<nums.size();i++){
        int t=nums[i];
        if(i>1)
        t+=dp[i-2];
        int s=dp[i-1];
        dp[i]=max(t,s);
    }
    return dp[nums.size()-1];
}
// M-5 space optimization
//Time complexity is O(N);
// space complexity is O(1)
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int prev2=0,prev1=nums[0];
    for(int i=1;i<nums.size();i++){
        int t=nums[i];
        if(i>1)
        t+=prev2;
        int s=prev1;
        int curr=max(t,s);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}