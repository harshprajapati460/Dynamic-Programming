#include<bits/stdc++.h>
using namespace std;

bool subset_sum_optimized(vector<int>set,int n,int sum){
    
   bool subset[n + 1][sum + 1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
 
    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
 
    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j]
                    = subset[i - 1][j]
                      || subset[i - 1][j - set[i - 1]];
        }
    }
  
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= sum; j++) {
    //        cout<<subset[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    return subset[n][sum];
    
}
bool subset_sum_recursion(vector<int>arr,int n,int sum){
        
        if(sum == 0) return true;
        if(n <= 0) return false;

        if(arr[n-1] <= sum){
            return subset_sum_recursion(arr,n-1,sum-arr[n-1]) || subset_sum_recursion(arr,n-1,sum);
        }
       else  return subset_sum_recursion(arr,n-1,sum);
}
bool subset_sum_memoization(vector<int>arr,int n,int sum,vector<vector<int>>&dp){
        
        if(sum == 0) return true;
        if(n <= 0) return false;
        
        if(dp[n-1][sum] != -1) return dp[n-1][sum];

        if(arr[n-1] <= sum){
            return dp[n-1][sum] = subset_sum_memoization(arr,n-1,sum-arr[n-1],dp) || subset_sum_memoization(arr,n-1,sum,dp);
        }
       else  return dp[n-1][sum] = subset_sum_memoization(arr,n-1,sum,dp);
}

int main(){

vector<int>arr = {1,3,5,6,8,10};
int sum  = 11;
int n = arr.size();
vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
cout<<"subset_sum_recursion: "<<subset_sum_recursion(arr,n,sum)<<endl;
cout<<"subset_sum_memoization: "<<subset_sum_memoization(arr,n,sum,dp)<<endl;
cout<<"subset_sum_optimized: "<<subset_sum_optimized(arr,n,sum)<<endl;
return 0;
}