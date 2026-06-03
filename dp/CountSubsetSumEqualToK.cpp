#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int k,int a[]){
    if(k==0)return 1;
    if(i==0)return (a[i]==k);
    if(dp[i][k]!=-1)return dp[i][k];
    int nottake=dfs(i-1,k,a);
    int take=0;
    if(a[i]<=k) take=dfs(i-1,k-a[i],a);
    return dp[i][k]=take+nottake;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=dfs(n-1,k,a);
    cout<<ans;
}