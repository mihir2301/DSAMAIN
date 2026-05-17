#include<bits/stdc++.h>
using namespace std;
int n,m;
void dijkstra(int source,vector<pair<int,int>>adj[]){
    vector<int>visited(n+1,0);
    int INF=1e9+10;
    vector<int>distance(n+1,INF);
    set<pair<int,int>>s;
    s.insert({0,source});
    distance[source]=0;
    while(s.size()>0){
        auto node=*s.begin();
        int v=node.second;
        int wt=node.first;
        s.erase(s.begin());
        if(visited[v])continue;
        visited[v]=1;
        for(auto child:adj[v]){
            int child_v=child.first;
            int child_wt=child.second;
            if(distance[v]+child_wt<distance[child_v]){
                distance[child_v]=distance[v]+child_wt;
                s.insert({distance[child_v],child_v});
            }
        }
    }
}
int main(){
    cin>>n>>m;
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].push_back({y,wt});
    }
    dijkstra(1,adj);
}