 int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int prev1=arr[0],prev2=0;
        for(int i=1;i<n;i++){
            int take=arr[i]+prev2;
            int notTake=prev1;
            int curr=max(take,notTake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }