#include <bits/stdc++.h> 
long long int helper(vector<int>& arr){
    long long int prev1=arr[0],prev2=0;
    int n=arr.size();
    for(int i=1;i<n;i++){
        long long int x=arr[i]+prev2;
        long long int y=prev1;
        long long int curr=max(x,y);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1)return valueInHouse[0];
    vector<int>temp1;
    vector<int>temp2;
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(valueInHouse[i]);     
        if(i!=n-1)temp2.push_back(valueInHouse[i]);     
    }
    return max(helper(temp1),helper(temp2));

}