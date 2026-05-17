#include<bits/stdc++.h>
using namespace std;
const int n=1e5+10;
int dp[n];
int longest(int i,vector<int>adj[]){
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    for(auto j:adj[i]){
        ans=max(ans,longest(j,adj)+1);
    }
    return dp[i]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int N,M;
    cin>>N>>M;
    vector<int>adj[N+1];
    for(int i=0;i<M;i++){
        int t;
        int m;
        cin>>t>>m;
        adj[t].push_back(m);
    }
    int ans=INT_MIN;
    for(int i=1;i<=N;i++){
        ans=max(ans,longest(i,adj));
    }
    cout<<ans;
}