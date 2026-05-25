#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int j){
    if(i==0&&j==0)return 1;
    if(i<0||j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=dfs(i-1,j)+dfs(i,j-1);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,m;
    cout<<"enter value of n and m";
    cin>>n>>m;
    int ans=dfs(n-1,m-1);
    cout<<ans;
}
/*int main(){
int m,n;
cin>>n>>m;
int dp[m][n];
dp[0][0]=1;
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(i==0&&j==0)continue;
int up=0,left=0;
if(i>0){
up=dp[i-1][j];
if(j>0){
left=dp[i][j-1];
}
dp[i][j]=left+up;
}
}
}
cout<<dp[m-1][n-1];
}
*/