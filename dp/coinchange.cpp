#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N];
int cost(int amount,vector<int>coins){
    if(amount==0)return 0;
    int ans=INT_MAX;
    for(auto coin:coins){
        if(amount-coin>=0){
           ans=min(ans, cost(amount-coin,coins)+1);
        }
    }
    return ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<int>coins={1,2,5};
    int amount=11;
    int ans=cost(amount,coins);
    cout<<ans;
}