#include<bits/stdc++.h>
using namespace std;
int count_subset(vector<int>arr,int n,int sum){
    int t[n+1][sum+1];
    for(int i=0; i<=n; i++) t[i][0] = 1;
    for(int j=1; j<=sum; j++) t[0][j] = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<= sum; j++){
            if(arr[i-1] > j){
                t[i][j] = t[i-1][j];
            }
            else {
                t[i][j] = t[i-1][j] + t[i-1][j-arr[i-1]];
            }
        }
    }
    return t[n][sum];
}
// MEMOIZATION AND RECURSION REMAIN SAME LOGIC

int count_subset_recursion(vector<int>arr,int n,int sum){
    if(sum == 0) return 1;
    if(n == 0) return 0;

    if(arr[n-1] > sum){
        return count_subset_recursion(arr,n-1,sum);
    }
    else return  count_subset_recursion(arr,n-1,sum-arr[n-1]) + count_subset_recursion(arr,n-1,sum);
}

int count_subset_memoization(vector<int>arr,int n,int sum,vector<vector<int>>&dp){
    if(sum == 0) return 1;
    if(n == 0) return 0;

    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    if(arr[n-1] > sum){
        return dp[n][sum] =  count_subset_recursion(arr,n-1,sum);
    }
    else return dp[n][sum] =  count_subset_recursion(arr,n-1,sum-arr[n-1]) + count_subset_recursion(arr,n-1,sum);
}

int main(){

vector<int>arr = {2,3,5,8,10};
int n = arr.size();
int sum = 10;
vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
cout<<count_subset_recursion(arr,n,sum)<<endl;
cout<<count_subset_memoization(arr,n,sum,dp)<<endl;
cout<<count_subset(arr,n,sum)<<endl;
return 0;
}