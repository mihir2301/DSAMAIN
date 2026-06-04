#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int dfs(int i,int w,int wt[],int value[]){
    if(i==0){
        if(w>=wt[i])return value[i];
        else return 0;
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int notake=dfs(i-1,w,wt,value);
    int take=INT_MIN;
    if(w>=wt[i]) take=dfs(i-1,w-wt[i],wt,value)+value[i];
    return dp[i][w]=max(take,notake);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n,w;
    cin>>n>>w;
    int wt[n];
    int value[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
        cin>>value[i];
    }
    int ans=dfs(n-1,w,wt,value);
    cout<<ans;
    
}