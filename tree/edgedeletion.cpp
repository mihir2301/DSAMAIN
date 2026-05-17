#include<bits/stdc++.h>
using namespace std;
int subtree[1000];
void dfs(int index,int p,vector<int>adj[],vector<int>value){
    subtree[index]+=value[index-1];
    for(auto i:adj[index]){
        if(i==p)continue;
        dfs(i,index,adj,value);
        subtree[index]+=subtree[i];
    }
}
int main(){
    int N;
    cin>>N;
    vector<int>adj[N+1];
    vector<int>value;
    for(int i=0;i<N-1;i++){
        int t,m;
        cin>>t>>m;
        adj[t].push_back(m);
        adj[m].push_back(t);
        
    }
    for(int i=1;i<=N;i++){
        int t;
        cin>>t;
        value.push_back(t);
    }
    dfs(1,0,adj,value);
    int ans=INT_MIN;
    for(int i=2;i<=N;i++){
        int p1=subtree[i];
        int  p2=subtree[1]-p1;
        ans=max(ans,p1*p2);
    }
    cout<<ans;
}