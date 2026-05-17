#include<bits/stdc++.h>
using namespace std;
int dp[100005][3];
int happy(int n,int ac,int a[],int b[],int c[]){
    if(n<0)return 0;
    if(dp[n][ac]!=-1)return dp[n][ac];
    int ans=INT_MIN;
    if(ac==1){
       ans=max(ans,happy(n-1,2,a,b,c)+a[n]);
       ans=max(ans,happy(n-1,3,a,b,c)+a[n]);
    }
    if(ac==2){
        ans=max(ans,happy(n-1,1,a,b,c)+b[n]);
        ans=max(ans,happy(n-1,3,a,b,c)+b[n]);
    }
    if(ac==3){
        ans=max(ans,happy(n-1,1,a,b,c)+c[n]);
        ans=max(ans,happy(n-1,2,a,b,c)+c[n]);
    }
    return dp[n][ac]=ans;

}
int main(){
    memset(dp,-1,sizeof(dp));
    int N;
    cin>>N;
    int a[N],b[N],c[N];
    int ans=INT_MIN;
    for(int i=0;i<N;i++){
        int m,n,p;
        cin>>m>>n>>p;
        a[i]=m;
        b[i]=n;
        c[i]=p;
    }
    for(int i=1;i<=3;i++){
        ans=max(ans,happy(N-1,i,a,b,c));
    }
    cout<<ans;
}