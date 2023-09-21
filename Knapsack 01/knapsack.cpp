#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[],int val[],int n,int W){
   if(W == 0 || n == 0) return 0;
   
   if(wt[n-1] <= W){
     return max(val[n - 1] + knapsack(wt,val,n - 1,W - wt[n - 1]),knapsack(wt,val,n - 1,W));
   }
   else if(wt[n-1] > W){
    return knapsack(wt,val,n - 1,W);
   }
   
}
int main(){

int wt[] = {1,3,4,5};
int val[] = {1,4,7,5};
int W = 7;
int n = sizeof(wt)/sizeof(wt[0]);
cout<<knapsack(wt,val,n,W)<<" ";

return 0;
}
