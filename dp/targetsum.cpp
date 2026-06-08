#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int s,int a[]){
    if(i==0){
        if(a[i]==0 && s==0) return 2;
        if(a[i]==s)return 1;
        return 0;
    }
    if(dp[i][s]!=-1)return dp[i][s];
    int nottake=dfs(i-1,s,a);
    int take=0;
    if(s>=a[i]) take=dfs(i-1,s-a[i],a);
    return dp[i][s]=take+nottake;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,k;
    cin>>n>>k;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s=s-k;
    if(s<0){
        cout<<"Not possible";
        return 0;
    }
    if(s%2!=0){
        cout<<"Not possible";
        return 0;
    }
    int ans=dfs(n-1,s/2,a);
    cout<<ans;
}