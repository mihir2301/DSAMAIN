#include<bits/stdc++.h>
using namespace std;
const int NN=1e5+10;
long long int dp[NN];
int frogjump(int n,int k,int h[]){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    long long int ans=INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i>=0)
        ans=min(ans,frogjump(n-i,k,h)+abs(h[n-i]-h[n])+0LL);
    }
    return dp[n]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int N,K;
    cin>>N>>K;
    int h[N];
    for(int i=0;i<N;i++){
        int t;
        cin>>t;
        h[i]=t;
    }
    int ans=frogjump(N-1,K,h);
    cout<<ans;
}