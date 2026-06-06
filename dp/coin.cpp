#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int k,int a[]){
    if(i==0){
        if(k%a[i]==0)return k/a[i];
        else return 1e8;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    int nottake=dfs(i-1,k,a);
    int take=1e8;
    if(k>=a[i])take=dfs(i,k-a[i],a)+1;
    return dp[i][k]=min(take,nottake);
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