#include<bits/stdc++.h>
using namespace std;
int dp[5005][305];
int cost(int index,int amount ,vector<int>coins){ //use all first at particular index
    
    if(amount==0) return 1;
    if(index<0)return 0;
    if(dp[index][amount]!=-1)return dp[index][amount];
       
    int ways=0;
    for(int i=0;i<=amount;i+=coins[index]){
        ways+=cost(index-1,amount-i,coins);
    }
    return dp[index][amount]= ways;
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<int>coins={1,2,5};
    int amount=5;
    int ans=cost(2,amount,coins);
    cout<<ans;
}