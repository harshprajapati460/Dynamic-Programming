#include<bits/stdc++.h>
using namespace std;
//Problem link : https://practice.geeksforgeeks.org/problems/coin-change2448/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// N = 4, Sum = 10
// coins = {2,5,3,6}
// Output: 5
// Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
long long int count_3(int coins[], int N, int sum) {
    
     long long int t[N+1][sum+1];
     t[0][0] = 0;
     for(int i=1; i<=N; i++) t[i][0] = 1;
     for(int j=1; j<=sum; j++) t[0][j] = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(coins[i-1] <= j){
                    t[i][j] =   t[i][j-coins[i-1]] + t[i-1][j];
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[N][sum];
        // code here.
    }
long long int count_2(int coins[],int n,int sum,vector<vector<int>>&dp){
        if(sum == 0) return 1;
        if(n == 0) return 0;
      
      if(dp[n][sum] != -1) return dp[n][sum];
      
      if(coins[n-1] <= sum){
          return dp[n][sum] = count_2(coins,n,sum-coins[n-1],dp) + count_2(coins,n-1,sum,dp);
      }
      else return dp[n][sum] =  count_2(coins,n-1,sum,dp);
        // code here.
        
}
long long int count_1(int coins[], int n, int sum) {

      if(sum == 0) return 1;
      if(n == 0) return 0;
      
      if(coins[n-1] <= sum){
          return count_1(coins,n,sum-coins[n-1]) + count_1(coins,n-1,sum);
      }
      else return count_1(coins,n-1,sum);
        // code here.
}

int main(){

int coins[] = {2,5,3,6};
int n = 4;
int sum = 10;
cout<<"Through recursion : "<<count_1(coins,n,sum)<<endl;
vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
cout<<"Through recursion Memoization : "<<count_2(coins,n,sum,dp)<<endl;
cout<<"Through Top Down : "<<count_3(coins,n,sum)<<endl;

return 0;
}