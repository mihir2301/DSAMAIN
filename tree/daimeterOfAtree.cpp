#include<bits/stdc++.h>
using namespace std;
int depth[1000];
void dfs(int index,int p,vector<int>adj[]){
    for(auto i:adj[index]){
        if(i==p)continue;
        depth[i]=depth[index]+1;
        dfs(i,index,adj);
    }
}
int main(){
    int N;
    cin>>N;
    vector<int>adj[N+1];
    for(int i=0;i<N-1;i++){
        int t,m;
        cin>>t>>m;
        adj[t].push_back(m);
        adj[m].push_back(t);
    }
    dfs(1,0,adj);
    int maxdepth=-1;
    int node;
    for(int i=1;i<=N;i++){
        if(depth[i]>maxdepth){
            maxdepth=depth[i];
            node=i;
        }
        depth[i]=0;
    }
    dfs(node,0,adj);
    maxdepth=-1;
    for(int i=1;i<=N;i++){
        maxdepth=max(maxdepth,depth[i]);
    }
    cout<<maxdepth;
}