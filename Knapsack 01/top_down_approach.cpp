#include<bits/stdc++.h>
using namespace std;
int knapsack(int wt[],int val[],int n,int W){
     int t[n+1][W+1];
    //  for(int i=0; i<=n; i++){
    //     for(int j=0; j<=W; j++){
    //         if(i == 0 || j == 0){
    //             t[i][j] = 0;
    //         }
    //     }
    //  }
     for(int i=0; i<=n; i++){
        for(int j=0; j<=W; j++){
           if(i== 0 || j == 0){
            t[i][j] = 0;
           }
          else if(wt[i-1] <= j){
            t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]],t[i-1][j]);
           }
           else {
                  t[i][j] = t[i-1][j];
           }
        }
     }
     return t[n][W];

}
int main(){
int wt[] = {1,3,4,5};
int val[] = {1,4,7,5};
int W = 7;
int n = sizeof(wt)/sizeof(wt[0]);
cout<<knapsack(wt,val,n,W)<<endl;
return 0;
}