#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n][k+1];
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    if(a[0]<=k)dp[0][a[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=k;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if(j-a[i]>=0) take=dp[i-1][j-a[i]];
            dp[i][j]=take+nottake;
        }
    }
    cout<<dp[n-1][k];
}