#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int j,int n,vector<vector<int>>&grid){
    if(j<0||j>n-1) return INT_MIN;
    if(i==n-1)return grid[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MIN;
    int down=dfs(i+1,j,n,grid);
    if(down!=INT_MIN) down=down+grid[i][j];
    int dl=dfs(i+1,j-1,n,grid);
    if(dl!=INT_MIN) dl=dl+grid[i][j];
    int dr=dfs(i+1,j+1,n,grid);
    if(dr!=INT_MIN) dr=dr+grid[i][j];
    return dp[i][j]=max(down,max(dl,dr));
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
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,dfs(0,i,n,grid));  
    }
    cout<<ans;
}