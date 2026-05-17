#include<bits/stdc++.h>
using namespace std;
int parent[1000];
void dfs(int index,int p,vector<int>adj[]){  // stroing parent
    for(auto i:adj[index]){
        if(i==p)continue;
        parent[i]=index;
        dfs(i,index,adj);
    }
}

vector<int> path(int n){
    vector<int>pa;
    while(n!=0){
        pa.push_back(n);
        n=parent[n];
    }
    reverse(pa.begin(),pa.end());
    return pa;
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
    int m,n;
    cout<<"Enter two nodes";
    cin>>m>>n;
    dfs(1,0,adj);
    vector<int>pa1=path(m);
    vector<int>pa2=path(n);
    int i=0;
    int ans=-1;
    while(i<pa1.size()&&i<pa2.size()){
        if(pa1[i]!=pa2[i]){
            ans=pa1[i-1];
        }
        i++;
    }
    cout<<ans;
}