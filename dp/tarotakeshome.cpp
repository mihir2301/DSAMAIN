#include<bits/stdc++.h>
using namespace std;
int dp[100][100005];
int takeshome(int index,int wt,vector<int>&v,vector<int>&weights){
    
    if(wt==0)return 0;
    if(index<0)return 0;
    if(dp[index][wt]!=-1)return dp[index][wt];
    
    int ans=takeshome(index-1,wt,v,weights);
    if(wt-weights[index]>=0)
    ans=max(ans,takeshome(index-1,wt-weights[index],v,weights)+v[index]);
    return dp[index][wt]=ans;

}
int main(){
memset(dp,-1,sizeof(dp));
int N,W;
cin>>N>>W;
vector<int>v;
vector<int>weights;
for(int i=0;i<N;i++){
    int t,w;
    cin>>t>>w;
    weights.push_back(t);
    v.push_back(w);
}
int ans=takeshome(N-1,W,v,weights);
cout<<ans;
}