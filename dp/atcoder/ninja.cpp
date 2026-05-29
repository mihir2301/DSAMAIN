#include<bits/stdc++.h>
using namespace std;
int calcdays(int index,int ac,vector<vector<int>>&activity,vector<vector<int>>&dp){
    if(index<0)return 0;
    if(dp[index][ac]!=-1)return dp[index][ac];
    int ans=INT_MIN;
    for(int i=0;i<3;i++){
        if(i!=ac){
           ans=max(ans,calcdays(index-1,i,activity,dp)+activity[index][i]);
        }
    }
    return dp[index][ac]=ans;
}
int main(){
    int n, ac;
    cout<<"Enter no. of days no. of activity";
    cin>>n>>ac;
    vector<vector<int>>activity;
    vector<vector<int>>dp(n,vector<int>(4,-1));
    for(int i=0;i<n;i++){
        vector<int>temp;
        for(int j=0;j<ac;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        activity.push_back(temp);
    }
    int ans=calcdays(n-1,3,activity,dp);
    cout<<ans;
}