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

int main(){

vector<int>arr = {2,3,5,8,10};
int n = arr.size();
int sum = 10;

cout<<count_subset(arr,n,sum)<<endl;

return 0;
}