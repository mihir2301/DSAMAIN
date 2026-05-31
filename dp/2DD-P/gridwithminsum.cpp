#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int j,vector<vector<int>>&grid){
    if(i<0||j<0)return INT_MAX;
    if(i==0&&j==0)return grid[0][0];
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    ans=min(ans,dfs(i-1,j,grid)+grid[i][j]);
    ans=min(ans,dfs(i,j-1,grid)+grid[i][j]);
    return ans;
    /*int left=dfs(i-1,j,grid)+grid[i][j];
    int right=dfs(i,j-1,grid)+grid[i][j];
    return dp[i][j]=min(left,right);*/
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>grid={{1,2,3},
                            {4,5,6},
                            {7,8,9}

    };
    int ans=dfs(2,2,grid);
    cout<<ans;
}