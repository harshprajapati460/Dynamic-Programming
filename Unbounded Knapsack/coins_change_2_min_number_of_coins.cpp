#include<bits/stdc++.h>
using namespace std;
int solve(int coins[], int N, int sum) {
    
     long long int t[N+1][sum+1];
     
     for(int i=1; i<=N; i++) t[i][0] = 0;
     for(int j=0; j<=sum; j++) t[0][j] = INT_MAX - 1;
     
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1] <= j){
                    t[i][j] =  min(1 + t[i][j-coins[i-1]] , t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
      int ans;
	    t[N][sum] == INT_MAX-1 ? ans = -1 : ans = t[N][sum];
	    return ans;
    }
int Memoization(int coins[],int n,int sum,vector<vector<int>>&dp){
    if(sum == 0) return 0;
     if(n == 0) return INT_MAX - 1;

     if(dp[n][sum] != -1) return dp[n][sum];

     if(coins[n-1] <= sum){
       return dp[n][sum] = min(1 + Memoization(coins,n,sum-coins[n-1],dp),Memoization(coins,n-1,sum,dp));
     }
     else return dp[n][sum] =  Memoization(coins,n-1,sum,dp);
}    
int Rec(int coins[],int n,int sum){
     if(sum == 0) return 0;
     if(n == 0) return INT_MAX - 1;

     if(coins[n-1] <= sum){
       return min(1 + Rec(coins,n,sum-coins[n-1]),Rec(coins,n-1,sum));
     }
     else return Rec(coins,n-1,sum);
    }
int main(){
int coins[]  = {25, 10, 5, 15};
int n = 4;
int sum = 30;
vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
cout<<Rec(coins,n,sum)<<endl;
cout<<Memoization(coins,n,sum,dp)<<endl;
return 0;
}