#include<bits/stdc++.h>
using namespace std;
void bfs(int i,vector<int>adj[],vector<int>&visited,vector<int>&res){
    if(visited[i]==1)
     return;
    visited[i]=1;
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int c=q.front();
        res.push_back(c);
        q.pop();
        for(auto j:adj[c]){
            if(visited[j]==0){
                visited[j]=1;
                q.push(j);
            }
        }

    }
}
int main(){
    int n,e;
    cout<<"Enter no.of nodes";
    cin>>n;
    vector<int>adj[n];
    cout<<"\n enter no. of edges";
    cin>>e;
    for(int i=0;i<e;i++){
        int t,c;
        cin>>t>>c;
        adj[t].push_back(c);
        adj[c].push_back(t);
    }
    vector<int>visited(n,0);
    vector<int>result;
    for(int i=0;i<n;i++){

        bfs(i,adj,visited,result);
    }
    for(auto i:result){
        cout<<i<<" "; 
    }
}