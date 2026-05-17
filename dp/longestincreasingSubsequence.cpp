#include<bits/stdc++.h>
using namespace std;
const int N=2505;
int dp[N];
int lis(int n,int a[]){
    if(dp[n]!=-1) return dp[n];
    int ans=1;
    for(int j=0;j<n;j++){
        if(a[n]>a[j]){
            ans=max(ans,lis(j,a)+1);
        } 
    }
    return dp[n]=ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int a[8]={10,9,2,5,3,7,101,18};
    int ans=INT_MIN;
    for(int i=7;i>0;i--){
        ans=max(ans,lis(i,a));
    }
    cout<<ans;
}