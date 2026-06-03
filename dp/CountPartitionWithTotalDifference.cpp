#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int sum,int a[]){
    if(i==0){
        if(a[0]==0&&sum==0)return 2;
        if(a[0]==sum)return 1;
        return 0;
    }
    if(dp[i][sum]!=-1)return dp[i][sum];
    int nottake=dfs(i-1,sum,a);
    int take=0;
    if(a[i]<=sum) take=dfs(i-1,sum-a[i],a);
    return dp[i][sum]=take+nottake;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,d;
    cin>>n>>d;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    int sum=s-d;
    if(sum<0){
        cout<<"Not possible";
        return 0;
    }
    if(sum%2!=0){
        cout<<"Not possible";
        return 0;
    }
    sum=sum/2;
    int ans=dfs(n-1,sum,a);
    cout<<ans;
}