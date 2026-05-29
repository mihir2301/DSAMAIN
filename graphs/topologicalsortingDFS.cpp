#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&visited,vector<int>&ans){
    visited[node]=1;
    for(auto i:adj[node]){
        if(visited[i]!=1){
            dfs(i,adj,visited,ans);
        }
    }
    ans.push_back(node);
    return;
}
int main(){
    int t,e;
    cout<<"Enter no. of nodes and edges";
    cin>>t>>e;
    vector<int>adj[t+1];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int>visited(t+1,0);
    vector<int>ans;
    for(int i=1;i<t+1;i++)
    {
        if(visited[i]!=1){
            dfs(i,adj,visited,ans);
        }
    }

}