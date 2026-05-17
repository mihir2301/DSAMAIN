#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int Size[1000];
void make(int n){
    parent[n]=n;
    Size[n]=1;
}
int find(int n){
    if(n==parent[n])return n;
    return parent[n]=find(parent[n]);
}

void Union(int a ,int b){
    a=find(a);
    b=find(b);
    if(a==b)return;
    if(Size[b]>Size[a]){
        swap(a,b);
    }
    parent[b]=parent[a];
    Size[a]+=Size[b];
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;
    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        edges.push_back({wt,{x,y}});
    }
    sort(edges.begin(),edges.end());
    for(int i=1;i<=n;i++){
        make(i);
    }
    int totalcost=0;
    for(auto &edge:edges){
        int wt=edge.first;
        int x=edge.second.first;
        int y=edge.second.second;
        if(find(x)==find(y))continue;
        Union(x,y);
        totalcost+=wt;
    }
    cout<<totalcost;
}