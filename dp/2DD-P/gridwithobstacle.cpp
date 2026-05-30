#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool check(int i,int j,vector<pair<int,int>>p){
    for(auto t:p){
        if(i==t.first&&j==t.second)return true;
    }
    return false;
}
int dfs(int i,int j,vector<pair<int,int>>p){
    if(check(i,j,p))return 0;
    if(i==0&&j==0)return 1;
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=dfs(i-1,j,p)+dfs(i,j-1,p);
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<pair<int,int>>p={{1,1},{2,2},{3,3}};
    int n,m;
    cin>>n>>m;
    int ans=dfs(n,m,p);
    cout<<ans;
}