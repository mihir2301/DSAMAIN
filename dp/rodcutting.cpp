#include<bits/stdc++.h>
using namespace std;
int dp[1005];
int rod(int l,vector<int>&prices){
    if(l==0)return 0;
    if(dp[l]!=-1)return dp[l];
    int ans=INT_MIN;
    for(int i=0;i<prices.size();i++){
        if(l-(i+1)>=0)
        ans=max(ans,rod(l-(i+1),prices)+prices[i]);
    }
    return dp[l]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    vector<int>prices={1, 5, 8, 9, 10, 17, 17, 20};
    cout<<rod(8,prices);
}