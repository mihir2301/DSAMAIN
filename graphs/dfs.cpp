#include<bits/stdc++.h>
using namespace std;
void dfs(int i,vector<int>adj[],vector<int>&visited,vector<int>&res){
    visited[i]=1;
    for(auto j:adj[i]){
        if(visited[j]==0){
            dfs(j,adj,visited,res);
            res.push_back(j);
        }
    }
   
}
int main(){
    int n,e;
    cout<<"Enter no. of nodes and edges";
    cin>>n>>e;
    vector<int>adj[n];
    for(int i=0;i<e;i++){
        int t,c;
        cin>>t>>c;
        adj[t].push_back(c);
        adj[c].push_back(t);
    }
    vector<int>visited(n,0);
    vector<int>res;
    for(int i=0;i<n;i++){
        if(visited[i]!=1){
            dfs(i,adj,visited,res);
        }
    }
    for(auto i:res){
        cout<<i<<" ";
    }
}