#include<bits/stdc++.h>
using namespace std;
// N = 8
// Price[] = {1, 5, 8, 9, 10, 17, 17, 20}
// Output:
// 22
// Explanation:
// The maximum obtainable value is 22 by 
// cutting in two pieces of lengths 2 and 
// 6, i.e., 5+17=22.
 int solve_topdown(int price[],int n , int W){
        vector<vector<int>>t(n+1,vector<int>(W+1,0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=W; j++){
                if(i <= j){
                    t[i][j] = max(price[i-1] + t[i][j-i],t[i-1][j]);
                }
                else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
int solve_memoization(int price[],int n , int W,vector<vector<int>>&dp){
        if(W == 0 || n == 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        if(n <= W){
            return dp[n][W] = max(price[n-1]+solve_memoization(price,n,W-n,dp),solve_memoization(price,n-1,W,dp));
        }
        else return dp[n][W] = solve_memoization(price,n-1,W,dp);
}
 int solve_recursion(int price[],int n , int W){
        if(W == 0 || n == 0) return 0;
        
        if(n <= W){
            return max(price[n-1]+solve_recursion(price,n,W-n),solve_recursion(price,n-1,W));
        }
        else return solve_recursion(price,n-1,W);
    }
int main(){
 
 int Price[] = {1, 5, 8, 9, 10, 17, 17, 20};
 int n = 8;
vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
cout<<"Through recursion : "<<solve_recursion(Price,n,n)<<endl;
cout<<"Through recursion Memoization : "<<solve_memoization(Price,n,n,dp)<<endl;
cout<<"Through Top Down : "<<solve_topdown(Price,n,n)<<endl;

return 0;
}
