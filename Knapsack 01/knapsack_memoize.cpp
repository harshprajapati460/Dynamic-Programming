#include<bits/stdc++.h>
using namespace std;

int t[4][4];
int knapsack(int wt[],int val[],int n,int W){
    if(n == 0 || W == 0){
        return 0;
    }
    if(t[n][W] !=   -1){
        return t[n][W];
    }
    if(wt[n-1] >= W){
      return t[n][W] = max(val[n-1] + knapsack(wt,val,n-1,W - wt[n-1]), knapsack(wt,val,n-1,W));
    }
    else {
        return t[n][W] = knapsack(wt,val,n-1,W);
    }
}
int main(){
memset(t,-1,sizeof(t));
int val[] = {1,2,3};
int wt[] = {4,5,1};
int W = 4;
int n = 3;
cout<<knapsack(wt,val,n,W);
return 0;
}