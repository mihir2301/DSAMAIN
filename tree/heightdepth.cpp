#include<bits/stdc++.h>
using namespace std;
int height[1000];
int depth[1000];
void heightdepth(int i,int p,vector<int>adj[]){

    for(auto j:adj[i]){
        if(j==p)continue;
        depth[j]=depth[i]+1;
        
        heightdepth(j,i,adj);
        height[i]=max(height[i],height[j]+1);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>adj[n];
    for(int i=0;i<n-1;i++){
        int t,c;
        cin>>t>>c;
        adj[t].push_back(c);
        adj[c].push_back(t);
    }
    heightdepth(1,0,adj);
    cout<<depth[7]<<height[7];
}