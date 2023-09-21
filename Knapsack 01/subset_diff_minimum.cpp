#include<bits/stdc++.h>
using namespace std;
int find_mini_subset_diff(vector<int>arr,int n){
    int sum = 0;
    for(auto it:arr){
        sum += it;
    }
    vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;

    for(int i=1; i<=n; i++){ 
        for(int j=1; j<=sum; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }

    }
    int ans = INT_MAX;
    for(int i=0; i<=sum/2; i++){
        if(dp[n][i]){
            ans = min(ans,sum - 2*i);
        }
    }
    return ans;
}
int main(){
vector<int>arr = {1,2,7};
int n = arr.size();
cout<<find_mini_subset_diff(arr,n);
return 0;
}