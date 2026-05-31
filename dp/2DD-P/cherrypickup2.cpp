#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000][1000];
int dfs(int i,int j1,int j2,int n,vector<vector<int>>&grid){
    if(j1<0||j1>n-1||j2<0||j2>n-1){
        return -1e9;
    }
    if(i==n-1){
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int ans=-1e9;
    int value;
    for(int t=-1;t<=1;t++){
        for(int k=-1;k<=1;k++){
            if(j1==j2)
            value=grid[i][j1];
            else
            value=grid[i][j1]+grid[i][j2];
            ans=max(ans,dfs(i+1,j1+t,j2+k,n,grid)+value);
        }
    }
    return dp[i][j1][j2]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
     int n;
    cin>>n;
    vector<vector<int>>grid;
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        grid.push_back(temp);
    }
    int ans=dfs(0,0,n-1,n,grid);
    cout<<ans;
}