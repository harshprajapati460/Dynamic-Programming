#include<bits/stdc++.h>
using namespace std;
// Input: N = 4, W = 8
// val[] = {1, 4, 5, 7}
// wt[] = {1, 3, 4, 5}
// Output: 11
// Explanation: The optimal choice is to 
// pick the 2nd and 4th element.

// TIME COMPLEXITY O(2^N) 
// AUX SPACE S(N)  STACK SPACE  
int KnapSack_recursion(vector<int>&wt,vector<int>&val,int W,int n){
      if(n == 0 || W == 0) return 0;
       
      if(wt[n-1] <= W){
        return max(val[n-1] + KnapSack_recursion(wt,val,W-wt[n-1],n),KnapSack_recursion(wt,val,W,n-1));
      }  
      else {
           return KnapSack_recursion(wt,val,W,n-1);
      }
}

// TIME COMPLEXITY O(N*W)
// AUX COMPLEXITY S(N*W)
int KnapSack_Memoization(vector<int>&wt,vector<int>&val,int W,int n,vector<vector<int>>&dp){
      if(n == 0 || W == 0) return 0;

      if(dp[n][W] != -1) return dp[n][W];

      if(wt[n-1] <= W){
        return dp[n][W] = max(val[n-1] + KnapSack_Memoization(wt,val,W-wt[n-1],n,dp), KnapSack_Memoization(wt,val,W,n-1,dp));
      }
      else {
        return dp[n][W] = KnapSack_Memoization(val,wt,W,n-1,dp);
      }
}
// TIME COMPLEXITY O(N*W)
// AUX COMPLEXITY S(N*W)
int KnapSack_Top_Down(vector<int>&wt,vector<int>&val,int W,int n){
    vector<vector<int>>t(n+1,vector<int>(W+1,0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i-1] <= j){
                t[i][j] = max((val[i-1] + t[i][j-wt[i-1]]),t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
}
// OPTIMIZED
// TIME COMPLEXITY O(N*W)
// AUX SPACE S(W) -- > 1D ARRAY
int optimized(vector<int>&wt,vector<int>&val,int W,int n){
     vector<int>dp(W+1,0);
        
       for (int i=0; i<=W; i++)
      for (int j=0; j<n; j++)
         if (wt[j] <= i)
            dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
  
    return dp[W];
}
int main(){

vector<int>wt{1 , 3 , 4 , 5};
vector<int>val{1 , 4 , 5 , 7};
int W = 8;
int n = wt.size();
cout<<"Through recursion : "<<KnapSack_recursion(wt,val,W,n)<<endl;
vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
cout<<"Through recursion Memoization : "<<KnapSack_Memoization(wt,val,W,n,dp)<<endl;
cout<<"Through Top Down : "<<KnapSack_Top_Down(wt,val,W,n)<<endl;
cout<<"Opmized : "<<optimized(wt,val,W,n)<<endl;
return 0;
}