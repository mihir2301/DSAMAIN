#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool dfs(int i,int k,int n,int a[]){
    if(k==0)return true;
    if(i==0)return (a[i]==k);
    if(dp[i][k]!=-1)return dp[i][k];
    bool ans=false;
    ans=dfs(i-1,k,n,a);
    if(k-a[i]>=0)
    ans|=dfs(i-1,k-a[i],n,a);
    return dp[i][k]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,t;
    cin>>n>>t;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool ans=dfs(n-1,t,n,a);
    if(ans==1)cout<<"true";
    else cout<<"false";
}