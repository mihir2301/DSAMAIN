#include<bits/stdc++.h>
using namespace std;
int dfs(int n,int m,int l,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(n==l-1) return grid[n][m];
    if(dp[n][m]!=-1)return dp[n][m];
    int d=dfs(n+1,m,l,grid,dp)+grid[n][m];
    int diag=dfs(n+1,m+1,l,grid,dp)+grid[n][m];
    return dp[n][m]=min(d,diag);
}
int main(){
    int n,m,l;
    cin>>n>>m>>l;
    vector<vector<int>>dp(l,vector<int>(l,-1));
    vector<vector<int>>grid;
    for(int i=0;i<l;i++){
        vector<int>temp;
        for(int j=0;j<=i;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        grid.push_back(temp);
    }
    int ans=dfs(n,m,l,grid,dp);
    cout<<ans;
}