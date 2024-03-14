#include<iostream>
#include<climits>
using namespace std;
//Normal 
int minSteps_norm(int N)
{
    if(N==1){
        return 0;
	}
    int a,b,c;
	    a=minSteps_norm(N-1);
	    if(N%2==0){
	        b=minSteps_norm(N/2);
	    }
	    else{
	        b=INT_MAX;
	    }
	    if(N%3==0){
	        c=minSteps_norm(N/3);
	    }
	    else{
	    c=INT_MAX;
        }
        return 1+min(a,min(b,c));

}
//memoization 
int minSteps_memo(int N, int*arr)
 {      
        if(N==1){
	        return 0;
	    }
	    if(arr[N]!=-1){
	        return arr[N];
	    }
	    int a,b,c;
	    a=minSteps_memo(N-1,arr);
	    if(N%2==0){
	        b=minSteps_memo(N/2,arr);
	    }
	    else{
	        b=INT_MAX;
	    } 
	    if(N%3==0){
	        c=minSteps_memo(N/3,arr);
	    }
	    else
	    c=INT_MAX;
	    arr[N]=1+min(a,min(b,c));
	    return arr[N];
} 
//dp
int minSteps_dp(int n){
	
  int *ans = new int[n + 1];
  ans[0] = 0;
  ans[1] = 0;

  for (int i = 2; i <= n; i++) {
    int x, y = INT_MAX, z = INT_MAX;
    x = ans[i - 1];
    if (i % 2 == 0)
      y = ans[i / 2];
    if (i % 3 == 0)
      z = ans[i / 3];
    ans[i] = 1 + min(x, min(y, z));
  }
  int output = ans[n];
  delete[] ans;
  return output;

}
int main(){
        int N;
        cin>>N;
        cout<<minSteps_norm(N)<<endl;;
        int *arr=new int[N+1];
	    for(int i=0;i<=N;i++){
	        arr[i]=-1;
	    }
	    cout<<minSteps_memo(N,arr)<<endl;
	    cout<<minSteps_dp(N,arr)<<endl;
}