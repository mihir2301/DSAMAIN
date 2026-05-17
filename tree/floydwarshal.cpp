#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;

int dp[N][N];

int main(){
    int n,m;
    cout<<"Enter no. of nodes and edges";
    cin>>n>>m;
    for(int i=0;i<N;i++){
        for(int j=0;j<n;j++){
            if(i==j)dp[i][j]==0;
            dp[i][j]=INF;
        }
    }
    for(int i=1;i<=m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        dp[x][y]=wt;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][k]==INF||dp[k][j]==INF){continue;}
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }

}