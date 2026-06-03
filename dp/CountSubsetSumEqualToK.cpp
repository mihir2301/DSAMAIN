#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int k,int a[]){                        // for 0 
    if(k==0)return 1;                                // remove this line
    if(i==0)return (a[i]==k);                       //if(i==0) if(sum==0)&&a[0]==0 return 2;
    if(dp[i][k]!=-1)return dp[i][k];                //if(sum==a[0])return 1;
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