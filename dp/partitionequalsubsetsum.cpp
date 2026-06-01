#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool dfs(int i,int k,int a[]){
    if(k==0)return true;
    if(i==0)return (a[0]==k);
    if(dp[i][k]!=-1)return dp[i][k];
    bool ans=false;
    ans=dfs(i-1,k,a);
    if(k-a[i]>=0)
    ans|=dfs(i-1,k-a[i],a);
    return dp[i][k]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    if(s%2!=0){cout<<"CANNOT BE DIVIDED";
    return 0;}
    int k=s/2;
    bool ans=dfs(n-1,k,a);
    if(ans==1)
    cout<<"CAN BE DIVIDED";
    else cout<<"CANNOT BE DIVIDED";
}