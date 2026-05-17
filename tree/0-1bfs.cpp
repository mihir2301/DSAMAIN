#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
vector<int>level;
int bfs(int index,vector<pair<int,int>>adj[],int n){
    deque<int>q;
    q.push_back(index);
    level[index]=0;
    while(!q.empty()){
        int p=q.front();
        q.pop_front();
        for(auto i:adj[p]){
            int child=i.first;
            int wt=i.second;
            if(level[p]+wt<level[child]){
                level[child]=level[p]+wt;
                if(wt==1){
                    q.push_back(child);
                }
                else q.push_front(child);
            }
        }
    }
    return level[n];
}
int main(){
    int n,m;
    cin>>n>>m;
    level.assign(n+1,INF);
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int t,c;
        cin>>t>>c;
        adj[t].push_back({c,0});
        adj[c].push_back({t,1});
    }
    cout<<bfs(1,adj,n);
}